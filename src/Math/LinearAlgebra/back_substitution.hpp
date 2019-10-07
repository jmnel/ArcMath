#pragma once

#include <iostream>

#include <Math/CoreMath.hpp>
#include "matrix.hpp"

namespace jmnel {

    template <typename T, size_t N>
    auto solve_back_substitution( mat<T, N, N> const &mat_r, vec<T, N> const &b ) {

        using std::cout;
        using std::endl;

        cout << "r=" << endl << mat_r << endl;
        cout << "b=" << b << endl;

        // Check that matrix is upper triangle.
        for( size_t i = 1; i < N; ++i ) {
            for( size_t j = 0; j < i; ++j ) {
                assertf( abs( mat_r( i, j ) ) < 1e-12 );
            }
        }

        vec<T, N> x_known{};

        for( size_t k = N; k > 0; --k ) {
            assertf( k > 0 );
            const auto i = k - 1;
            cout << i << ", ";
            auto j = i + 1;
            //            auto foo = b( i );
            //            for( size_t j =
            cout << j << endl;
            for( size_t q = j; q < N; ++q ) {
                cout << "q=" << q << endl;
            }
            //            for( size_t
            //            for( size_t j = i + 1; j + 1 < N; ++j ) {
            //                foo -= mat_r( i, j ) * x_known( j );
            //            }
            //            x_known( i ) = mat_r( i, i ) / foo;
        }

        cout << x_known << endl;
    }

}  // namespace jmnel
