#pragma once

#include <Math/LinearAlgebra/Vec.hpp>

namespace arc::math {

    class Plane {
    public:
        Vec3f m_p{0.0f};
        Vec3f m_n{1.0f, 0.0f, 0.0f};

        Plane() noexcept;
        Plane( Vec3f const &p, Vec3f const &n ) noexcept;
    };

}  // namespace arc::math
