#pragma once

#include <cstddef>

#include "Common.hpp"

namespace arc::matrix {

    template <MatrixStorageType storageTypeT = MatrixStorageType::Static,
              MatrixStorageOrder storageOrderT = MatrixStorageOrder::RowMajor,
              MatrixDensity innerDensityT = MatrixDensity::Dense,
              MatrixDensity outerDensityT = MatrixDensity::Dense,
              size_t innerStrideT = 1,
              size_t outerStrideT = 1,
              bool hasNamedMembersT = true>
    class MatrixOptions {
    public:
        static constexpr MatrixStorageType storageType = storageTypeT;
        static constexpr MatrixStorageOrder storageOrder = storageOrderT;
        static constexpr MatrixDensity innerDensity = innerDensityT;
        static constexpr MatrixDensity outerDensity = outerDensityT;
        static constexpr size_t innerStride = innerStrideT;
        static constexpr size_t outerStride = outerStrideT;
        static constexpr bool hasNamedMembers = hasNamedMembersT;
    };

}  // namespace arc::matrix
