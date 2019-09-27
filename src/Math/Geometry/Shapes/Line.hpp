#pragma once

#include <Core/Debug/Assert.hpp>
#include <Math/LinearAlgebra/Vec.hpp>

namespace arc::math {

    template <class T = float, size_t N = 3>
    struct Line {
        Vec<T, N> m_p0{T( 0.0 )};
        Vec<T, N> m_p1{T( 1.0 )};

        Line() noexcept {
        }
        Line( Vec<T, N> const &p0, Vec<T, N> const &p1 ) noexcept
            : m_p0( p0 ), m_p1( p1 ) {
        }

        Line( Vec<T, N> const &other )
            : m_p0( other.m_p0 ), m_p1( other.m_p1 ) {
        }

        Vec<T, N> &operator[]( const size_t i ) {
            massertf( "Line vertex access out of bounds.", i < 2 );
            return ( &( m_p0 ) )[i];
        }

        Vec<T, N> const &operator[]( const size_t i ) const {
            massertf( "Line vertex access out of bounds.", i < 2 );
            return ( &( m_p0 ) )[i];
        }
    };

    using Line2f = Line<float, 2>;
    using Line2d = Line<double, 2>;
    using Line3f = Line<float, 3>;
    using Line3d = Line<double, 3>;

}  // namespace arc::math
