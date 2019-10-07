#include "LinearAlgebra/BinaryOperators.hpp"
#pragma once

#include <tuple>

#include "Matrix"

namespace jmnel::matrix {

    using std::tuple;

    template <typename T, size_t N, typename OptionsT>
    auto decomposeQR( Matrix<T, N, N, OptionsT> const &matA ) {
        using ReturnOptions = typename detail::make_return_options<OptionsT>::type;

        Matrix < T, : ta
    }

}  // namespace jmnel::matrix
