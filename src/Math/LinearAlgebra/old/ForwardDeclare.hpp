#pragma once

#include <cstddef>

#include "Common.hpp"

namespace jmnel::matrix {

    template <typename ScalarT, size_t rowsT, size_t colsT, typename OptionsT>
    class Matrix;

    template <MatrixStorageType storageTypeT = MatrixStorageType::Static,
              MatrixStorageOrder storageOrderT = MatrixStorageOrder::RowMajor,
              MatrixDensity innerDensityT = MatrixDensity::Dense,
              MatrixDensity outerDensityT = MatrixDensity::Dense,
              ptrdiff_t innerStrideT = 1,
              ptrdiff_t outerStrideT = 1,
              bool hasNamedMembersT = true>
    class MatrixOptions;

    namespace detail {}

}  // namespace jmnel::matrix
