#include <Math/Geometry/Shapes/Sphere.hpp>

namespace arc::math {

    Sphere::Sphere() noexcept {
    }

    Sphere::Sphere( Vec3f const &p, const float r ) noexcept
        : m_p( p ), m_r( r ) {
    }

}  // namespace arc::math
