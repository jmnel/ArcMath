#pragma once

#include <cstddef>

#include <Core/Debug/Assert.hpp>

namespace jmnel {

    template <typename T, size_t extentT, ptrdiff_t strideT = 1>
    struct Span {

        T* m_start = nullptr;

        Span( T* start ) : m_start( start ) {}

        static constexpr size_t size() { return extentT; }
        static constexpr size_t stride() { return strideT; }

        T& at( const size_t i ) {
            assertf( i < size() );
            return m_start[i * stride()];
        }
    };

}  // namespace jmnel
