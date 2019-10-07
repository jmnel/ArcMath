#pragma once

#include <cstddef>

#include <Core/Debug/Assert.hpp>

#include "pointer_iterator.hpp"

namespace jmnel {

    template <typename T, size_t Extent, ptrdiff_t Stride = 1>
    class span {
    public:
        using value_type = T;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using reference = value_type &;
        using const_reference = value_type const &;
        using pointer = value_type *;
        using const_pointer = value_type const *;
        static constexpr size_t size() { return Extent; }
        static constexpr size_t stride() { return Stride; }
        using iterator = pointer_iterator<value_type, stride()>;
        using const_iterator = const_pointer_iterator<value_type, stride()>;

        // -- Constructor --
        span( const pointer start ) : m_start( start ) {}

        reference at( const size_t i ) {
            assertf( i < size() );
            return m_start[i * stride()];
        }

        const_reference at( const size_t i ) const {
            assertf( i < size() );
            return m_start[i * stride()];
        }

        reference operator[]( const size_t i ) {
            assertf( i < size() );
            return m_start[i * stride()];
        }

        const_reference operator[]( const size_t i ) const {
            assertf( i < size() );
            return m_start[i * stride()];
        }

        reference front() { return m_start[0]; }
        const_reference front() const { return m_start[0]; }

        reference back() { return at( size() - 1 ); }
        const_reference back() const { return at( size() - 1 ); }

        pointer data() { return m_start; };
        const_pointer data() const { return m_start; };

        iterator begin() const { return iterator( m_start ); }
        const_iterator cbegin() const { return const_iterator( m_start ); }

        iterator end() const { return iterator( m_start + size() * stride() ); }
        const_iterator cend() const { return const_iterator( m_start + size() * stride() ); }

        void fill( value_type const &x ) {
            for( auto &e : *this ) {
                e = x;
            }
        }

        template <size_type SubN, difference_type SubStride = 1>
        auto subspan( difference_type offset = 0 ) {
            static_assert( SubN * SubStride <= size() );
            massertf( offset + ( SubN - 1 ) * SubStride < size(), "Subspan out of range." );
            return span<value_type, SubN, SubStride * stride()>( &at( offset ) );
        }

    private:
        const pointer m_start = nullptr;
    };

}  // namespace jmnel
