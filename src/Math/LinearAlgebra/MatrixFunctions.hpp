#pragma once

#include <numeric>

#include <Math/CoreMath.hpp>
#include "BinaryOperators.hpp"
#include "ForwardDeclare.hpp"

namespace jmnel::matrix {

    template <typename ScalarT, size_t N, typename OptionsT>
    ScalarT lengthSquared( Matrix<ScalarT, 1, N, OptionsT> const &m ) {
        return std::inner_product( m.cbegin(), m.cend(), m.cbegin(), 0.0 );
    }

    template <typename ScalarT, size_t N, typename OptionsT>
    ScalarT length( Matrix<ScalarT, 1, N, OptionsT> const &m ) {
        return sqrt( std::inner_product( m.cbegin(), m.cend(), m.cbegin(), 0.0 ) );
    }

    template <typename ScalarT, size_t N, typename OptionsT>
    ScalarT lengthSquared( Matrix<ScalarT, N, 1, OptionsT> const &m ) {
        return std::inner_product( m.cbegin(), m.cend(), m.cbegin(), 0.0 );
    }

    template <typename ScalarT, size_t N, typename OptionsT>
    ScalarT length( Matrix<ScalarT, N, 1, OptionsT> const &m ) {
        return sqrt( std::inner_product( m.cbegin(), m.cend(), m.cbegin(), 0.0 ) );
    }

    template <typename ScalarT, size_t N, typename OptionsT>
    auto normalize( Matrix<ScalarT, 1, N, OptionsT> const &m ) {

        const auto invLength = 1.0 / length( m );
        assertf( invLength > 0.0 );

        using ReturnOptions = typename detail::make_return_options<OptionsT>::type;
        using ReturnType = Matrix<ScalarT, 1, N, ReturnOptions>;
        ReturnType result{};

        auto itResult = result.begin();
        auto itM = m.cbegin();

        for( ; itResult != result.end(); ++itResult ) {
            const auto term = *itM * invLength;
            *itResult = *itM * invLength;
            ++itM;
        }
        return result;
    }  // namespace jmnel::matrix

    //    template <typename ScalarT, size_t N, typename OptionsT>
    //    auto normalize( Matrix<ScalarT, N, 1, OptionsT> const &m ) {

    //        const auto invLength = 1.0 / length( m );
    //        assertf( invLength > 0.0 );
    //        using ReturnOptions = typename detail::make_return_options<OptionsT>::type;
    //        using ReturnType = Matrix<ScalarT, N, 1, ReturnOptions>;
    //        ReturnType result{};

    //        auto itResult = result.beginElement();
    //        auto itM = m.cbeginElement();

    //        for( ; itResult != result.endElement(); ++itResult ) {
    //                        *itResult = *itM * invLength;
    //            ++itM;
    //        }
    //        return result;
    //    }
    //    template <typename ScalarT, size_t N, typename OptionsT>
    //    ScalarT length( Matrix<ScalarT, N, 1, OptionsT> const &m ) {
    //        return sqrt( std::inner_product( m.cbegin(), m.cend(), m.cbegin(), 0.0 ) );
    //    }

}  // namespace jmnel::matrix
