#pragma once

#include <cstddef>

#include <Math/LinearAlgebra/Traits.hpp>

namespace arc::detail {

    // Forward declare traits.
    template <typename T>
    struct traits;

    template <typename Derived,
              bool hasNamedMemberRefsT = get_named_member_refs_enabled<Derived>::value,
              size_t SizeT = traits<Derived>::Size>
    class MatrixNamedMemberRefs {
    };

    template <typename Derived>
    class MatrixNamedMemberRefs<Derived, true, 2> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        Scalar& x = static_cast<Derived*>( this )->m_storage[0];
        Scalar& y = static_cast<Derived*>( this )->m_storage[1];
    };

    template <typename Derived>
    class MatrixNamedMemberRefs<Derived, true, 3> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        Scalar& x = static_cast<Derived*>( this )->m_storage[0];
        Scalar& y = static_cast<Derived*>( this )->m_storage[1];
        Scalar& z = static_cast<Derived*>( this )->m_storage[2];
    };

    template <typename Derived>
    class MatrixNamedMemberRefs<Derived, true, 4> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        Scalar& x = static_cast<Derived*>( this )->m_storage[0];
        Scalar& y = static_cast<Derived*>( this )->m_storage[1];
        Scalar& z = static_cast<Derived*>( this )->m_storage[2];
        Scalar& w = static_cast<Derived*>( this )->m_storage[3];
    };

}  // namespace arc::detail
