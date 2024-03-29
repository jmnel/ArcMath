#include "CoreMath.hpp"

namespace arc {

    uint nextPowerOf2( uint x ) {
        x--;
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        x++;
        return x;
    }
}  // namespace arc
