#pragma once

#include <LinearAlgebra/Vec.hpp>

namespace arc {

    class Arc2d {
    public:
        Vec2f m_center{0.0f};
        float m_radius = 1.0f;
        float m_theta0 = 0.0f;
        float m_theta1 = Pi / 2.0f;

        Arc2d() noexcept;
        Arc2d( Vec2f const &center,
               const float radius,
               const float theta0,
               const float theta1 ) noexcept;
    };

}  // namespace arc
