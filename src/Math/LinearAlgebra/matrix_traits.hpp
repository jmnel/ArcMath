#pragma once

#include <cstddef>

#include "common.hpp"
#include "forward_declare.hpp"
#include "policies.hpp"

namespace jmnel::detail {

    template <typename T, size_t M, size_t N, typename Policies>
    struct traits<matrix<T, M, N, Policies>> {
        using value_type = T;

        static constexpr auto rows() { return M; }
        static constexpr auto cols() { return N; }
        static constexpr auto size() { return M * N; }

        static constexpr auto storage_policy() { return Policies::storage_policy(); }
        static constexpr auto order_policy() { return Policies::order_policy(); }
        static constexpr auto inner_density_policy() { return Policies::inner_density(); }
        static constexpr auto outer_density_policy() { return Policies::outer_density(); }
        static constexpr auto inner_stride() { return Policies::inner_stride(); }
        static constexpr auto outer_stride() { return Policies::outer_stride(); }

        static constexpr auto is_vector_type() {
            return ( rows() == 1 && cols() != 1 ) || ( rows() != 1 && cols() == 1 );
        }
    };

}  // namespace jmnel::detail
