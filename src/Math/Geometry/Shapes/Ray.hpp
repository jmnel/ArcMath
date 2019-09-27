#pragma once

#include <Math/Vec.hpp>

namespace arc {

    template <class T = float, const size_t N = 3>
    struct Ray {
        Vec<T, N> m_o{T( 0.0 )};
        Vec<T, N> m_dir{T{0.0f}};

        Ray() noexcept {
        }

        Ray( Vec<T, N> const &origin, Vec<T, N> direction )
            : m_o( origin ), m_dir( direction ) {
        }

        Ray( Ray const &rOther )
            : m_o( rOther.m_o ), m_dir( rOther.m_dir ) {
        }

        Vec<T, N> &operator[]( const size_t i ) {
            massertf( "Line vertex access out of bounds.", i < 2 );
            return ( &( m_o ) )[i];
        }

        Vec<T, N> const &operator[]( const size_t i ) const {
            massertf( "Line vertex access out of bounds.", i < 2 );
            return ( &( m_o ) )[i];
        }
    };

    using Ray2f = Ray<float, 2>;
    using Ray2d = Ray<double, 2>;
    using Ray3f = Ray<float, 3>;
    using Ray3d = Ray<double, 3>;

}  // namespace arc
