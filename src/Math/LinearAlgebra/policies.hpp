#include <functional>
#pragma once

#include <cstddef>

#include "common.hpp"
#include "forward_declare.hpp"

namespace jmnel {

    template <storage_policies Storage,
              order_policies Order,
              density_policies InnerDensity,
              density_policies OuterDensity,
              ptrdiff_t InnerStride,
              ptrdiff_t OuterStride>
    struct policies {
        static constexpr auto storage_policy() { return Storage; }
        static constexpr auto order_policy() { return Order; }
        static constexpr auto inner_density_policy() { return InnerDensity; }
        static constexpr auto outer_density_policy() { return OuterDensity; }
        static constexpr auto inner_stride_policy() { return InnerStride; }
        static constexpr auto outer_stride_policy() { return OuterStride; }
    };

}  // namespace jmnel
