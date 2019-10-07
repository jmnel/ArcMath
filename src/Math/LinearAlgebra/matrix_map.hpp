#pragma once

#include "forward_declare.hpp"
#include "matrix_map_base.hpp"

namespace jmnel {

    template <typename T, size_t M, size_t N, typename Policies>
    class matrix_map : public detail::matrix_map_base<matrix_map<T, M, N, Policies>> {};

}  // namespace jmnel
