#pragma once

#include <cstddef>

#include "Common.hpp"
#include "ForwardDeclare.hpp"

namespace jmnel::matrix::detail {

    template <typename T>
    struct traits;

    template <typename ScalarT, size_t rowsT, size_t colsT, typename OptionsT>
    struct traits<Matrix<ScalarT, rowsT, colsT, OptionsT>> {
        using Scalar = ScalarT;
        static constexpr size_t rows = rowsT;
        static constexpr size_t cols = colsT;
        static constexpr size_t size = rows * cols;

        using Options = OptionsT;

        static constexpr MatrixStorageType storageType = Options::storageType;
        static constexpr MatrixStorageOrder storageOrder = Options::storageOrder;
        static constexpr MatrixDensity innerDensity = Options::innerDensity;
        static constexpr MatrixDensity outerDensity = Options::outerDensity;
        static constexpr size_t innerStride = Options::innerStride;
        static constexpr size_t outerStride = Options::outerStride;
        static constexpr bool hasNamedMembers = Options::hasNamedMembers;

        static constexpr bool isVectorType() {
            return ( rows == 1 && cols != 1 ) || ( rows != 1 && cols == 1 );
        }

        static constexpr MatrixDimension dimension =
            isVectorType() ? MatrixDimension::One : MatrixDimension::Two;

        static constexpr bool isRowMajor() { return storageOrder == MatrixStorageOrder::RowMajor; }
        static constexpr bool isColMajor() { return storageOrder == MatrixStorageOrder::ColMajor; }
    };

}  // namespace jmnel::matrix::detail
