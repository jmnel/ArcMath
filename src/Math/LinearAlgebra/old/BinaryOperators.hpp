#pragma once

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <type_traits>

#include "Common.hpp"
#include "ForwardDeclare.hpp"
#include "MatrixOptions.hpp"
#include "Traits.hpp"

using std::cout;
using std::endl;

namespace jmnel::matrix::detail {

    template <typename T>
    struct make_return_options {
        using Options = typename std::remove_const_t<std::remove_reference_t<T>>;
        using type = MatrixOptions<MatrixStorageType::Static,
                                   Options::storageOrder,
                                   MatrixDensity::Dense,
                                   MatrixDensity::Dense,
                                   1,
                                   1,
                                   true>;
    };

    static inline auto transformHelper = []( auto lambda,
                                             auto tBegin1,
                                             auto tEnd1,
                                             auto tBegin2,
                                             auto tEnd2,
                                             auto rBegin,
                                             auto rEnd ) {
        auto it1 = tBegin1;
        auto it2 = tBegin2;
        auto itResult = rBegin;
        for( it1; it1 != tEnd1; ++it1 ) {
            assertf( it2 != tEnd2 );
            assertf( itResult != rEnd );
            *itResult = lambda( *it1, *it2 );
        }
    };

    template <typename ScalarT,
              size_t rowsT,
              size_t colsT,
              typename Options1_T,
              typename Options2_T>
    auto operator+( Matrix<ScalarT, rowsT, colsT, Options1_T> const &m1,
                    Matrix<ScalarT, rowsT, colsT, Options2_T> const &m2 ) {

        using ReturnOptions = typename make_return_options<Options1_T>::type;
        using ReturnType = Matrix<ScalarT, rowsT, colsT, ReturnOptions>;
        ReturnType sum{};
        transformHelper( std::plus<double>(),
                         m1.cbeginElement(),
                         m1.cendElement(),
                         m2.cbeginElement(),
                         m2.cendElement(),
                         sum.beginElement(),
                         sum.endElement() );
        return sum;
    }

    template <typename ScalarT,
              size_t rowsT,
              size_t colsT,
              typename Options1_T,
              typename Options2_T>

    auto operator-( Matrix<ScalarT, rowsT, colsT, Options1_T> const &m1,
                    Matrix<ScalarT, rowsT, colsT, Options2_T> const &m2 ) {

        using ReturnOptions = typename make_return_options<Options1_T>::type;
        using ReturnType = Matrix<ScalarT, rowsT, colsT, ReturnOptions>;
        ReturnType sum{};
        transformHelper( std::minus<double>(),
                         m1.cbeginElement(),
                         m1.cendElement(),
                         m2.cbeginElement(),
                         m2.cendElement(),
                         sum.beginElement(),
                         sum.endElement() );
        return sum;
    }

    // Dot product
    template <typename ScalarT, size_t N, typename Options1_T, typename Options2_T>
    ScalarT dot( Matrix<ScalarT, 1, N, Options1_T> const &m1,
                 Matrix<ScalarT, N, 1, Options2_T> const &m2 ) {

        ScalarT sum = 0.0;
        for( size_t i = 0; i < N; ++i ) {
            sum += m1( i ) + m2( i );
        }
        return sum;
    }

    template <typename ScalarT, size_t N, typename Options1_T, typename Options2_T>
    ScalarT dot( Matrix<ScalarT, N, 1, Options1_T> const &m1,
                 Matrix<ScalarT, 1, N, Options2_T> const &m2 ) {

        ScalarT sum = 0.0;
        for( size_t i = 0; i < N; ++i ) {
            sum += m1( i ) + m2( i );
        }
        return sum;
    }

    template <typename ScalarT, size_t N, typename Options1_T, typename Options2_T>
    ScalarT dot( Matrix<ScalarT, N, 1, Options1_T> const &m1,
                 Matrix<ScalarT, N, 1, Options2_T> const &m2 ) {

        ScalarT sum = 0.0;
        for( size_t i = 0; i < N; ++i ) {
            sum += m1( i ) + m2( i );
        }
        return sum;
    }

    template <typename ScalarT, size_t N, typename Options1_T, typename Options2_T>
    ScalarT dot( Matrix<ScalarT, 1, N, Options1_T> const &m1,
                 Matrix<ScalarT, 1, N, Options2_T> const &m2 ) {

        ScalarT sum = 0.0;
        for( size_t i = 0; i < N; ++i ) {
            sum += m1( i ) * m2( i );
        }
        return sum;
    }

    template <typename ScalarT,
              size_t M,
              size_t N,
              size_t K,
              typename Options1_T,
              typename Options2_T>
    auto operator*( Matrix<ScalarT, M, N, Options1_T> &m1, Matrix<ScalarT, N, K, Options2_T> &m2 ) {

        //        static_assert( M > 1 && K > 1 );

        if constexpr( M == 1 && K == 1 ) {
            return dot( m1, m2 );
        } else {
            using ReturnOptions = typename make_return_options<Options1_T>::type;
            using ReturnType = Matrix<ScalarT, M, K, ReturnOptions>;
            ReturnType product{};

            for( size_t i = 0; i < M; ++i ) {
                for( size_t j = 0; j < K; ++j ) {
                    product( i, j ) = dot( m1.row( i ), m2.col( j ) );
                }
            }
            return product;
        }
    }

    template <typename ScalarT, size_t M, size_t N, typename OptionsT>
    auto operator*( Matrix<ScalarT, M, N, OptionsT> &lhs, ScalarT const &rhs ) {

        using ReturnOptions = typename make_return_options<OptionsT>::type;
        using ReturnType = Matrix<ScalarT, M, N, ReturnOptions>;
        ReturnType product{};

        auto itProd = product.beginElement();
        auto itLhs = lhs.beginElement();

        for( ; itProd != product.endElement(); ++itProd ) {
            *itProd = *itProd * rhs;
            ++itLhs;
        }

        return product;
    }

    template <typename ScalarT, size_t M, size_t N, typename OptionsT>
    auto operator*( ScalarT const &lhs, Matrix<ScalarT, M, N, OptionsT> &rhs ) {

        using ReturnOptions = typename make_return_options<OptionsT>::type;
        using ReturnType = Matrix<ScalarT, M, N, ReturnOptions>;
        ReturnType product{};

        auto itProd = product.beginElement();
        auto itRhs = rhs.beginElement();

        for( ; itProd != product.endElement(); ++itProd ) {
            *itProd = *itProd * lhs;
            ++itRhs;
        }

        return product;
    }

    template <typename ScalarT, size_t M, size_t N, typename OptionsT>
    auto operator/( Matrix<ScalarT, M, N, OptionsT> &lhs, ScalarT const &rhs ) {

        using ReturnOptions = typename make_return_options<OptionsT>::type;
        using ReturnType = Matrix<ScalarT, M, N, ReturnOptions>;
        ReturnType product{};

        auto itProd = product.beginElement();
        auto itLhs = lhs.beginElement();

        for( ; itProd != product.endElement(); ++itProd ) {
            *itProd = *itProd / rhs;
            ++itLhs;
        }

        return product;
    }

}  // namespace jmnel::matrix::detail
