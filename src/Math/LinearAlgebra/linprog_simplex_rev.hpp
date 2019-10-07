#include <algorithm>
#include <functional>
#pragma once

#include <array>
#include <iostream>
#include <tuple>

#include "matrix.hpp"
#include "ostream_helpers.hpp"
#include "qr_decompose.hpp"

namespace jmnel {

    void linprog_simplex_rev( mat<double, 3, 6> mat_a,
                              vec3d b,
                              vec<double, 6> c,
                              std::array<size_t, 3> starting_basis ) {

        // sats
        using std::array;
        static const size_t m = 3;
        static const size_t n = 6;

        array<size_t, 3> basis_j = starting_basis;
        array<size_t, 3> non_k;

        for( int iteration = 0; iteration < 1; ++iteration ) {

            // Determine non basis K.
            size_t k = 0;
            for( size_t i = 0; i < n; ++i ) {
                if( std::find( basis_j.begin(), basis_j.end(), i ) == basis_j.end() ) {
                    non_k[k++] = i;
                }
                if( k + 1 > m ) {
                    break;
                }
            }

            // Get c_K and c_J
            vec<double, m> c_j;
            vec<double, m> c_k;
            for( size_t k = 0; k < m; ++k ) {
                c_j( k ) = c( basis_j[k] );
            }
            for( size_t k = 0; k < n - m; ++k ) {
                c_k( k ) = c( non_k[k] );
            }
            cout << c_j << endl;
            cout << c_k << endl;

            // Build matrix A_J.
            array<vec<double, m>, m> columns_of_aj;
            for( size_t i = 0; i < m; ++i ) {
                columns_of_aj[i] = mat_a.col( basis_j[i] );
            }
            auto mat_aj = mat<double, m, m>::from_columns( columns_of_aj );

            cout << "A=" << endl;
            cout << mat_a << endl;

            cout << "A_J=" << endl;
            cout << mat_aj << endl;

            // Compute QR factorization of A_J.
            auto [mat_q, mat_r] = qr_decompose( mat_aj );
            cout << "Q=" << endl << mat_q << endl;
            cout << "R=" << endl << mat_r << endl;
        }
    }

    // -- test function --
    void test() {
        //        mat<double, 3, 3> a = mat<double, 3, 3>::identiy();
        //        _ARC_DEBUG_BREAK();
        //        auto [q, r] = qr_decompose( a );

        //        cout << q << endl << r << endl;

        mat<double, 3, 6> mat_a = {{2, 1, 1, 1, 0, 0}, {1, 2, 3, 0, 1, 0}, {2, 2, 1, 0, 0, 1}};
        vec3d b = {{2, 5, 6}};
        vec<double, 6> c = {{-3, -1, -3, 0, 0, 0}};

        std::array<size_t, 3> j{4 - 1, 5 - 1, 6 - 1};

        linprog_simplex_rev( mat_a, b, c, j );
    }

}  // namespace jmnel
