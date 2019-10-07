#pragma once

#include "forward_declare.hpp"
#include "matrix_accessors.hpp"
#include "matrix_storage.hpp"

namespace jmnel::detail {

    template <typename Derived>
    class matrix_base : public matrix_storage<Derived>, public matrix_accessors<Derived> {};

}  // namespace jmnel::detail
