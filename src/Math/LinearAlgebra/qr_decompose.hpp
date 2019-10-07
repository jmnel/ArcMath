#pragma once

#include <array>
#include <tuple>

#include "matrix.hpp"

namespace jmnel {

    template <typename T, size_t N>
    auto qr_decompose( mat<T, N, N> const &mat_a ) {

        std::array<vec<T, N>, N> u;
        std::array<vec<T, N>, N> a;
        std::array<vec<T, N>, N> e;

        mat<T, N, N> mat_q{};
        mat<T, N, N> mat_r{};

        for( size_t k = 0; k < N; ++k ) {

            a[k] = mat_a.col( k );

            u[k] = a[k];
            for( size_t i = 0; i < k; ++i ) {
                u[k] = u[k] - dot( a[k], e[i] ) * e[i];
            }
            e[k] = normalize( u[k] );

            for( size_t i = 0; i < N; ++i ) {
                mat_q( i, k ) = e[k]( i );
            }

            for( size_t i = 0; i <= k; ++i ) {
                mat_r( i, k ) = dot( a[k], e[i] );
            }
        }

        return std::make_tuple( transpose( mat_q ), mat_r );
    }

}  // namespace jmnel
