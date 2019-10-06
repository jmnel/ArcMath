#include <type_traits>
#pragma once

#include <cstddef>

namespace arc {

    template <typename T>
    static constexpr auto checkInRange( const T v, const T vMin, const T vMax ) {
        static_assert( v >= vMin && v <= vMax );
        if constexpr( v >= vMin && v <= vMax ) {
            return v;
        } else {
            return std::false_type{};
        }
    }

}  // namespace arc
