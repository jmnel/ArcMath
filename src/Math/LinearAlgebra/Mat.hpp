#pragma once

#include <array>

#include <Core/Debug/Assert.hpp>

#include <Math/LinearAlgebra/Vec.hpp>

using std::array;

namespace arc {

    template <typename T, const size_t M, const size_t N>
    class Mat {
    private:
        array<Vec<T, N>, M> m_rows{};

    public:
        explicit Mat( T const &k = 0.0 ) noexcept {
            for( auto &row : m_rows ) {
                for( auto &e : row ) {
                    //                    assertf( e == 0.0 );
                    e = k;
                }
            }
        }

        Mat( array<Vec<T, N>, M> const &rows ) noexcept {
            for( size_t i = 0; i < M; ++i ) {
                for( size_t j = 0; j < N; ++j ) {
                    m_rows[i][j] = rows[i][j];
                }
            }
        }

        explicit Mat( Mat<T, M, N> const &m ) noexcept {
            for( size_t i = 0; i < M; ++i ) {
                for( size_t j = 0; j < N; ++j ) {
                    m_rows[i][j] = m.m_rows[i][j];
                }
            }
        }

        Mat &operator=( Mat<T, M, N> const &m ) noexcept {
            for( size_t i = 0; i < M; ++i ) {
                for( size_t j = 0; j < N; ++j ) {
                    m_rows[i][j] = m.m_rows[i][j];
                }
            }
        }

        size_t size() const {
            return M;
        }

        static Mat identity() {
            Mat m;
            for( size_t i = 0; i < N; ++i ) {
                m[i][i] = 1.0;
            }
        }

        static Mat zero() {
            return Mat{};
        }

        Vec<T, N> const &operator[]( const size_t i ) const {
            assertf( i < M );
            return m_rows[i];
        }

        Vec<T, N> &operator[]( const size_t i ) {
            assertf( i < M );
            return m_rows[i];
        }
    };

    template <typename T, const size_t M, const size_t N>
    Mat<T, M, N> operator+( Mat<T, M, N> const &m ) {
        return m;
    }

    template <typename T, const size_t M, const size_t N>
    Mat<T, M, N> operator-( Mat<T, M, N> const &m ) {
        return m * -1.0;
    }

    template <typename T, const size_t M, const size_t N>
    Mat<T, M, N> operator+( Mat<T, M, N> const &m0, Mat<T, M, N> const &m1 ) {
        Mat<T, M, N> sum;
        for( size_t i = 0; i < M; ++i ) {
            sum[i] = m0[i] + m1[i];
        }
        return sum;
    }

    template <typename T, const size_t M, const size_t N>
    Mat<T, M, N> operator*( Mat<T, M, N> const &m0, Mat<T, N, M> const &m1 ) {
        Mat<T, M, N> product;
        for( size_t i = 0; i < M; ++i ) {
            for( size_t j = 0; j < M; ++j ) {
                Vec<T, N> col;
                for( size_t q = 0; q < N; ++q ) {
                    col[q] = m1[q][j];
                }
                product[i][j] = dot( m0[i], col );
            }
        }
        return product;
    }

    template <typename T, const size_t M, const size_t N>
    Mat<T, M, N> operator*( const T s, Mat<T, M, N> const &m ) {
        Mat<T, M, N> product;
        for( size_t i = 0; i < M; ++i ) {
            product[i] = s * m[i];
        }
        return product;
    }

    template <typename T, const size_t M, const size_t N>
    Mat<T, M, N> operator*( Mat<T, M, N> const &m, const T s ) {
        return s * m;
    }

    template <typename T, const size_t M, const size_t N>
    Vec<T, N> operator*( Mat<T, M, N> const &m, Vec<T, M> const &v ) {
        Vec<T, M> product;
        for( size_t i = 0; i < M; ++i ) {
            product[i] = dot( m[i], v );
        }
        return product;
    }

    template <typename T, const size_t M, const size_t N>
    inline std::ostream &operator<<( std::ostream &os, Mat<T, M, N> const &m ) {
        for( size_t i = 0; i < M; ++i ) {
            os << m[i] << std::endl;
        }
        return os;
    }

};  // namespace arc
