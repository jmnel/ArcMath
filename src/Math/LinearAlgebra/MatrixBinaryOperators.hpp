#pragma once

#include <type_traits>

//#include <Math/LinearAlgebra/Matrix.hpp>
//#include <Math/LinearAlgebra/MatrixMap.hpp>

#include <Math/LinearAlgebra/ForwardDeclarations.hpp>

using std::remove_const_t;
using std::remove_reference_t;

namespace arc::detail {
    /*
        template <typename T>
        struct make_return_options {
            using type = MatrixOptions<typename
    remove_const_t<remove_reference_t<T>>::Options::Index, matrix_storage_static_tag,
                                       matrix_storage_dense_tag,
                                       matrix_storage_dense_tag,
                                       matrix_row_major_tag,
                                       1,
                                       1,
                                       matrix_has_named_members_tag>;
        };

        template <typename T>
        using make_return_options_t = typename make_return_options<T>::type;

    #define _MATRIX_SAME_SIZE                             \
        template <typename ScalarT,                       \
                  int RowsT,                              \
                  int ColsT,                              \
                  typename AOptionsT,                     \
                  template <typename, int, int, typename> \
                  class AMatrixT,                         \
                  typename BOptionsT,                     \
                  template <typename, int, int, typename> \
                  class BMatrixT>

        _MATRIX_SAME_SIZE
        auto operator+( AMatrixT<ScalarT, RowsT, ColsT, AOptionsT> const &m1,
                        BMatrixT<ScalarT, RowsT, ColsT, BOptionsT> const &m2 ) {
            using Index = typename AOptionsT::Index;

            using RetOptions = make_return_options_t<decltype( m1 )>;

            Matrix<ScalarT, RowsT, ColsT, RetOptions> product;

            // Implementation for vector type.
            if constexpr( get_traits_t<decltype( m1 )>::isVectorType() ) {
                static_assert( get_traits_t<decltype( m2 )>::isVectorType() );
                for( Index i = 0; i < product.cols(); ++i ) {
                    product.coeffs( i ) = m1.coeffs( i ) + m2.coeffs( i );
                }
            }
            // Implementation for matrix type.
            else {
                for( Index i = 0; i < product.rows(); ++i ) {
                    for( Index j = 0; j < product.cols(); ++j ) {
                        product.coeffs( i, j ) = m1.coeffs( i, j ) + m2.coeffs( i, j );
                    }
                }
            }
            return product;
        }

        _MATRIX_SAME_SIZE
        auto operator-( AMatrixT<ScalarT, RowsT, ColsT, AOptionsT> const &m1,
                        BMatrixT<ScalarT, RowsT, ColsT, BOptionsT> const &m2 ) {
            using Index = typename AOptionsT::Index;

            using RetOptions = make_return_options_t<decltype( m1 )>;

            Matrix<ScalarT, RowsT, ColsT, RetOptions> product;

            // Implementation for vector type.
            if constexpr( get_traits_t<decltype( m1 )>::isVectorType() ) {
                static_assert( get_traits_t<decltype( m2 )>::isVectorType() );
                for( Index i = 0; i < product.cols(); ++i ) {
                    product.coeffs( i ) = m1.coeffs( i ) - m2.coeffs( i );
                }
            }
            // Implementation for matrix type.
            else {
                for( Index i = 0; i < product.rows(); ++i ) {
                    for( Index j = 0; j < product.cols(); ++j ) {
                        product.coeffs( i, j ) = m1.coeffs( i, j ) - m2.coeffs( i, j );
                    }
                }
            }
            return product;
        }

        template <typename ScalarT,
                  int N,
                  typename AOptionsT,
                  template <typename, int, int, typename>
                  class AMatrixT,
                  typename BOptionsT,
                  template <typename, int, int, typename>
                  class BMatrixT>
        ScalarT dot( AMatrixT<ScalarT, 1, N, AOptionsT> const &m1,
                     BMatrixT<ScalarT, 1, N, BOptionsT> const &m2 ) {
            using Index = typename AOptionsT::Index;
            ScalarT sum = 0.0;
            for( Index i = 0; i < N; ++i ) {
                sum += m1.coeff( i ) + m2.coeff( i );
            }
            return sum;
        }
        template <typename ScalarT,
                  int N,
                  typename AOptionsT,
                  template <typename, int, int, typename>
                  class AMatrixT,
                  typename BOptionsT,
                  template <typename, int, int, typename>
                  class BMatrixT>
        ScalarT dot( AMatrixT<ScalarT, N, 1, AOptionsT> const &m1,
                     BMatrixT<ScalarT, N, 1, BOptionsT> const &m2 ) {
            using Index = typename AOptionsT::Index;
            ScalarT sum = 0.0;
            for( Index i = 0; i < N; ++i ) {
                sum += m1.coeff( i ) + m2.coeff( i );
            }
            return sum;
        }
        template <typename ScalarT,
                  int N,
                  typename AOptionsT,
                  template <typename, int, int, typename>
                  class AMatrixT,
                  typename BOptionsT,
                  template <typename, int, int, typename>
                  class BMatrixT>
        ScalarT dot( AMatrixT<ScalarT, 1, N, AOptionsT> const &m1,
                     BMatrixT<ScalarT, N, 1, BOptionsT> const &m2 ) {
            using Index = typename AOptionsT::Index;
            ScalarT sum = 0.0;
            for( Index i = 0; i < N; ++i ) {
                sum += m1.coeff( i ) + m2.coeff( i );
            }
            return sum;
        }
        template <typename ScalarT,
                  int N,
                  typename AOptionsT,
                  template <typename, int, int, typename>
                  class AMatrixT,
                  typename BOptionsT,
                  template <typename, int, int, typename>
                  class BMatrixT>
        ScalarT dot( AMatrixT<ScalarT, N, 1, AOptionsT> const &m1,
                     BMatrixT<ScalarT, 1, N, BOptionsT> const &m2 ) {
            using Index = typename AOptionsT::Index;
            ScalarT sum = 0.0;
            for( Index i = 0; i < N; ++i ) {
                sum += m1.coeff( i ) + m2.coeff( i );
            }
            return sum;
        }

        template <typename ScalarT,
                  int K,
                  int M,
                  int N,
                  typename AOptionsT,
                  template <typename, int, int, typename>
                  class AMatrixT,
                  typename BOptionsT,
                  template <typename, int, int, typename>
                  class BMatrixT>
        auto operator*( AMatrixT<ScalarT, M, N, AOptionsT> const &m1,
                        BMatrixT<ScalarT, N, K, BOptionsT> const &m2 ) {
            using Index = typename AOptionsT::Index;
            using RetOptions = make_return_options_t<decltype( m1 )>;

            Matrix<ScalarT, M, K, RetOptions> product;

            for( Index i = 0; i < M; ++i ) {
                for( Index j = 0; j < K; j++ ) {
                    assertf( i < m1.rows() );
                    assertf( j < m2.rows() );
                    product( i, j ) = dot( m1.row( i ), m2.col( j ) );
                }
            }
        }
    */
}  // namespace arc::detail
