#pragma once

#include <cstddef>

#include "common.hpp"

namespace jmnel {

    template <typename T, size_t M, size_t N, typename Policies>
    class matrix;

    template <typename T, size_t M, size_t N, typename Policies>
    class matrixMap;

    template <storage_policies Storage,
              order_policies Order,
              density_policies InnerDensity,
              density_policies OuterDensity,
              ptrdiff_t InnerStride,
              ptrdiff_t OuterStride>
    struct policies;

    namespace detail {
        template <typename derived>
        struct traits;

    }  // namespace detail

}  // namespace jmnel
