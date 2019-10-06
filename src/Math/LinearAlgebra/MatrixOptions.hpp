#pragma once

#include <cstddef>

#include "Common.hpp"

namespace jmnel::matrix {

    template <MatrixStorageType storageTypeT,
              MatrixStorageOrder storageOrderT,
              MatrixDensity innerDensityT,
              MatrixDensity outerDensityT,
              ptrdiff_t innerStrideT,
              ptrdiff_t outerStrideT,
              bool hasNamedMembersT>
    class MatrixOptions {
    public:
        static constexpr MatrixStorageType storageType = storageTypeT;
        static constexpr MatrixStorageOrder storageOrder = storageOrderT;
        static constexpr MatrixDensity innerDensity = innerDensityT;
        static constexpr MatrixDensity outerDensity = outerDensityT;
        static constexpr ptrdiff_t innerStride = innerStrideT;
        static constexpr ptrdiff_t outerStride = outerStrideT;
        static constexpr bool hasNamedMembers = hasNamedMembersT;
    };

    using MatrixOptionsDefault = MatrixOptions<MatrixStorageType::Static,
                                               MatrixStorageOrder::RowMajor,
                                               MatrixDensity::Dense,
                                               MatrixDensity::Dense,
                                               1,
                                               1,
                                               true>;

}  // namespace jmnel::matrix
