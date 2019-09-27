#include <Math/Geometry/Shapes/Arc2d.hpp>

namespace arc::math {

    Arc2d::Arc2d() noexcept {
    }

    Arc2d::Arc2d( Vec2f const &center,
                  const float radius,
                  const float theta0,
                  const float theta1 ) noexcept
        : m_center( center ),
          m_radius( radius ),
          m_theta0( theta0 ),
          m_theta1( theta1 ) {
    }

}  // namespace arc::math
