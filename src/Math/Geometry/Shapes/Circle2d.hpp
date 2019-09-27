#pragma once

#include <Math/LinearAlgebra/Vec.hpp>

namespace arc::math {

    class Circle2d {
    public:
        Vec2f m_center{0.0};
        float m_radius = 1.0;

        Circle2d() noexcept;
        Circle2d( Vec2f const &center, const float radius ) noexcept;
    };

}  // namespace arc::math
