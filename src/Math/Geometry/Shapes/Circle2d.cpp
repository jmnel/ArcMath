#include <Math/Geometry/Shapes/Circle2d.hpp>

namespace arc::math {

    Circle2d::Circle2d() noexcept {
    }

    Circle2d::Circle2d( Vec2f const &center, const float radius ) noexcept
        : m_center( center ), m_radius( radius ) {
    }

}  // namespace arc::math
