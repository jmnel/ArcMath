#pragma once

#include <cstddef>
#include <iterator>

#include <Core/Debug/Assert.hpp>

namespace jmnel {

    template <typename T, ptrdiff_t Stride>
    class pointer_iterator {
    public:
        using self_type = pointer_iterator;
        using value_type = T;
        using reference = value_type&;
        using const_reference = value_type const&;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = ptrdiff_t;

        auto stride() { return Stride; }

    private:
        pointer m_address = nullptr;

    public:
        pointer_iterator( pointer address ) : m_address( address ) { assertf( m_address ); }

        self_type operator++() {
            self_type i = *this;
            m_address += stride();
            return i;
        }

        self_type operator++( int ) {
            m_address += stride();
            return *this;
        }

        self_type operator--() {
            self_type i = *this;
            m_address -= stride();
            return i;
        }

        self_type operator--( int ) {
            m_address -= stride();
            ;
            return *this;
        }

        self_type operator+( const difference_type difference ) {
            m_address += difference * stride();
            return *this;
        }

        self_type operator-( const difference_type difference ) {
            m_address -= difference * stride();
            return *this;
        }

        reference operator*() { return *m_address; };
        const_reference operator*() const { return *m_address; }
        pointer operator->() { return m_address; };
        const_pointer operator->() const { return m_address; }
        bool operator<( self_type const& rhs ) { return m_address < rhs.m_address; }
        bool operator>( self_type const& rhs ) { return m_address > rhs.m_address; }
        bool operator<=( self_type const& rhs ) { return m_address <= rhs.m_address; }
        bool operator>=( self_type const& rhs ) { return m_address >= rhs.m_address; }
        bool operator==( self_type const& rhs ) { return m_address == rhs.m_address; }
        bool operator!=( self_type const& rhs ) { return m_address != rhs.m_address; }
    };

    template <typename T, ptrdiff_t Stride>
    class const_pointer_iterator {
    public:
        using self_type = const_pointer_iterator;
        using value_type = T;
        //        using reference = value_type&;
        using const_reference = value_type const&;
        //        using pointer = value_type*;
        using const_pointer = const value_type*;
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = ptrdiff_t;

        auto stride() { return Stride; }

    private:
        const_pointer m_address;

    public:
        const_pointer_iterator( const_pointer address ) : m_address( address ) {
            assertf( m_address );
        }

        self_type operator++() {
            self_type i = *this;
            m_address += stride();
            return i;
        }

        self_type operator++( int ) {
            m_address += stride();
            return *this;
        }

        self_type operator--() {
            self_type i = *this;
            m_address -= stride();
            return i;
        }

        self_type operator--( int ) {
            m_address -= stride();
            ;
            return *this;
        }

        self_type operator+( const difference_type difference ) {
            m_address += difference * stride();
            return *this;
        }

        self_type operator-( const difference_type difference ) {
            m_address -= difference * stride();
            return *this;
        }

        //        reference operator*() { return *m_address; };
        const_reference operator*() const { return *m_address; }
        //        pointer operator->() { return m_address; };
        const_pointer operator->() const { return m_address; }
        bool operator<( self_type const& rhs ) { return m_address < rhs.m_address; }
        bool operator>( self_type const& rhs ) { return m_address > rhs.m_address; }
        bool operator<=( self_type const& rhs ) { return m_address <= rhs.m_address; }
        bool operator>=( self_type const& rhs ) { return m_address >= rhs.m_address; }
        bool operator==( self_type const& rhs ) { return m_address == rhs.m_address; }
        bool operator!=( self_type const& rhs ) { return m_address != rhs.m_address; }
    };

}  // namespace jmnel
