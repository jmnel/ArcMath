#pragma once

#include <Math/CoreMath.hpp>
#include "forward_declare.hpp"

namespace jmnel::detail {

    template <typename T, size_t M, size_t N, typename Policies>
    matrix<T, M, N, Policies> operator+( matrix<T, M, N, Policies> const &m1,
                                         matrix<T, M, N, Policies> const &m2 ) {

        matrix<T, M, N, Policies> sum{};
        for( size_t i = 0; i < M; ++i ) {
            for( size_t j = 0; j < N; ++j ) {
                sum( i, j ) = m1( i, j ) + m2( i, j );
            }
        }
        return sum;
    }

    template <typename T, size_t M, size_t N, typename Policies>
    matrix<T, M, N, Policies> operator-( matrix<T, M, N, Policies> const &m1,
                                         matrix<T, M, N, Policies> const &m2 ) {

        matrix<T, M, N, Policies> difference{};
        for( size_t i = 0; i < M; ++i ) {
            for( size_t j = 0; j < N; ++j ) {
                difference( i, j ) = m1( i, j ) - m2( i, j );
            }
        }
        return difference;
    }

    template <typename T, size_t M, size_t N, size_t K, typename Policies>
    matrix<T, M, K, Policies> operator*( matrix<T, M, N, Policies> const &m1,
                                         matrix<T, K, N, Policies> const &m2 ) {
        matrix<T, M, K, Policies> product{};
        for( size_t i = 0; i < M; ++i ) {
            for( size_t j = 0; j < K; ++j ) {
                auto accum = 0.0;
                for( size_t k = 0; k < N; ++k ) {
                    accum += m1( i, k ) * m2( k, j );
                }
                product( i, j ) = accum;
            }
        }
        return product;
    }

    template <typename T, size_t M, size_t N, typename Policies>
    matrix<T, M, N, Policies> operator*( T const &lhs, matrix<T, M, N, Policies> const &rhs ) {
        matrix<T, M, N, Policies> product{};
        for( size_t i = 0; i < M; ++i ) {
            for( size_t j = 0; j < N; ++j ) {
                product( i, j ) = rhs( i, j ) * lhs;
            }
        }
        return product;
    }

    template <typename T, size_t M, size_t N, typename Policies>
    matrix<T, M, N, Policies> operator*( matrix<T, M, N, Policies> const &lhs, T const &rhs ) {
        matrix<T, M, N, Policies> product{};
        for( size_t i = 0; i < M; ++i ) {
            for( size_t j = 0; j < N; ++j ) {
                product( i, j ) = lhs( i, j ) * rhs;
            }
        }
        return product;
    }

    template <typename T, size_t M, size_t N, typename Policies>
    matrix<T, M, N, Policies> operator/( matrix<T, M, N, Policies> const &lhs, T const &rhs ) {
        assertf( rhs != 0.0 );
        const auto rhsInv = 1.0 / rhs;
        matrix<T, M, N, Policies> product{};
        for( size_t i = 0; i < M; ++i ) {
            for( size_t j = 0; j < N; ++j ) {
                product( i, j ) = lhs( i, j ) * rhsInv;
            }
        }
        return product;
    }

    template <typename T, size_t N, typename Policies>
    T dot( matrix<T, N, 1, Policies> const &lhs, matrix<T, N, 1, Policies> const &rhs ) {
        T accum = 0.0;
        for( size_t k = 0; k < N; ++k ) {
            accum += lhs( k ) * rhs( k );
        }
        return accum;
    }

    template <typename T, size_t N, typename Policies>
    T length_sq( matrix<T, N, 1, Policies> const &m ) {
        return dot( m, m );
    }

    template <typename T, size_t N, typename Policies>
    T length( matrix<T, N, 1, Policies> const &m ) {
        return sqrt( dot( m, m ) );
    }

    template <typename T, size_t N, typename Policies>
    matrix<T, N, 1, Policies> normalize( matrix<T, N, 1, Policies> const &m ) {
        const auto l = length( m );
        assertf( l != 0.0 );
        const auto inv_l = 1.0 / l;
        return m * inv_l;
    }

    template <typename T, size_t M, size_t N, typename Policies>
    matrix<T, M, N, Policies> transpose( matrix<T, M, N, Policies> const &m ) {
        matrix<T, N, M, Policies> trans{};
        for( size_t i = 0; i < M; ++i ) {
            for( size_t j = 0; j < N; ++j ) {
                trans( i, j ) = m( j, i );
            }
        }
        return trans;
    }

}  // namespace jmnel::detail
