#pragma once

#include <cstddef>
#include <functional>
#include <initializer_list>

#include "common.hpp"
#include "forward_declare.hpp"
#include "matrix_base.hpp"
#include "matrix_operators.hpp"
#include "matrix_traits.hpp"

namespace jmnel {

    template <typename T, size_t M, size_t N, typename Policies>
    class matrix : public detail::matrix_base<matrix<T, M, N, Policies>> {
    private:
        using self_type = matrix<T, M, N, Policies>;

    public:
        static constexpr auto rows() { return M; }
        static constexpr auto cols() { return N; }
        static constexpr auto size() { return M * N; }

        matrix() noexcept = default;
        matrix( T const &x ) noexcept { fill( x ); }

        matrix( std::initializer_list<std::initializer_list<double>> const &list ) {
            size_t i = 0;
            for( auto const &eI : list ) {
                for( auto const &eJ : eI ) {
                    this->storage_at( i++ ) = eJ;
                }
            }
        }

        matrix( matrix const &other ) noexcept {
            for( size_t k = 0; k < size(); ++k ) {
                this->storage_at( k ) = other.storage_at( k );
            }
        }
        //        matrix( matrix && ) = delete;

        matrix &operator=( matrix const &rhs ) noexcept {
            if( &rhs == this ) {
                return *this;
            } else {
                for( size_t k = 0; k < size(); ++k ) {
                    this->storage_at( k ) = rhs.storage_at( k );
                }
            }
            return *this;
        }

        //        matrix &operator=( matrix && ) = delete;

        void fill( T const &x ) {
            for( size_t i = 0; i < M; ++i ) {
                for( size_t j = 0; j < N; ++j ) {
                    this->at( i, j ) = x;
                }
            }
        }

        void fill( std::function<T( const size_t i )> const lambda ) {
            for( size_t i = 0; i < size(); ++i ) {
                if constexpr( detail::traits<self_type>::is_vector_type() ) {
                    this->at( i ) = lambda( i );
                } else {
                    for( size_t k = 0; k < size(); ++k ) {
                        const auto i = k / cols();
                        const auto j = k % cols();
                        this->at( i, j ) = lambda( k );
                    }
                }
            }
        };

        void fill( std::function<T( const size_t i, const size_t j )> const lambda ) {
            for( size_t i = 0; i < size(); ++i ) {
                if constexpr( detail::traits<self_type>::is_vector_type() ) {
                    this->at( i ) = lambda( 1, i );
                } else {
                    for( size_t i = 0; i < rows(); ++i ) {
                        for( size_t j = 0; j < cols(); ++j ) {
                            this->at( i, j ) = lambda( i, j );
                        }
                    }
                }
            };
        }

        static self_type identiy() {
            self_type result;
            result.fill( []( const auto i, const auto j ) { return i == j ? 1.0 : 0.0; } );
            return result;
        }

        static self_type zero() {
            self_type result{};
            return result;
        }

        static auto from_columns( std::array<matrix<T, rows(), 1, Policies>, cols()> new_columns ) {
            self_type new_matrix{};
            for( size_t i = 0; i < rows(); ++i ) {
                for( size_t j = 0; j < cols(); ++j ) {
                    new_matrix( i, j ) = new_columns[j]( i );
                }
            }
            return new_matrix;
        }

        static auto from_rows( std::array<matrix<T, cols(), 1, Policies>, rows()> new_rows ) {
            self_type new_matrix{};
            for( size_t i = 0; i < rows(); ++i ) {
                for( size_t j = 0; j < cols(); ++j ) {
                    new_matrix( i, j ) = new_rows[i]( j );
                }
            }
            return new_matrix;
        }
    };

    using matrix_default_policies = policies<storage_policies::static_store,
                                             order_policies::row_major,
                                             density_policies::dense,
                                             density_policies::dense,
                                             1,
                                             1>;

    template <typename T, size_t N>
    using vec = matrix<T, N, 1, matrix_default_policies>;
    using vec2f = vec<float, 2>;
    using vec3f = vec<float, 3>;
    using vec4f = vec<float, 4>;
    using vec2d = vec<double, 2>;
    using vec3d = vec<double, 3>;
    using vec4d = vec<double, 4>;

    template <typename T, size_t M, size_t N>
    using mat = matrix<T, M, N, matrix_default_policies>;
    using mat2x2f = mat<float, 2, 2>;
    using mat3x3f = mat<float, 3, 3>;
    using mat4x4f = mat<float, 4, 4>;
    using mat2x2d = mat<double, 2, 2>;
    using mat3x3d = mat<double, 3, 3>;
    using mat4x4d = mat<double, 4, 4>;

}  // namespace jmnel
