#include <Geometry/Shapes/Plane.hpp>

namespace arc {

    Plane::Plane() noexcept {
    }

    Plane::Plane( Vec3f const &p, Vec3f const &n ) noexcept
        : m_p( p ), m_n( n ) {
    }

}  // namespace arc
