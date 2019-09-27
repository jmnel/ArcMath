#pragma once

#include <Math/LinearAlgebra/Vec.hpp>

namespace arc::math {

    class Sphere {
    public:
        Vec3f m_p{0.0f};
        float m_r = 0.3f;

        Sphere() noexcept;
        Sphere( Vec3f const &p, const float r ) noexcept;
    };

}  // namespace arc::math
