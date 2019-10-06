#pragma once

#include "Traits.hpp"

namespace arc::matrix::detail {

    template <typename Derived,
              size_t sizeT = traits<Derived>::size,
              bool isVectorTypeT = traits<Derived>::isVectorType()>
    class NamedMambers {};

    template <typename Derived>
    class NamedMambers<Derived, 2, true> {
    private:
        using Scalar = typename traits<Derived>::Scalar;

    public:
        Scalar& x = static_cast<Derived>( this )->at( 0 );
        Scalar& y = static_cast<Derived>( this )->at( 1 );
    };

    template <typename Derived>
    class NamedMambers<Derived, 3, true> {
    private:
        using Scalar = typename traits<Derived>::Scalar;

    public:
        Scalar& x = static_cast<Derived>( this )->at( 0 );
        Scalar& y = static_cast<Derived>( this )->at( 1 );
        Scalar& z = static_cast<Derived>( this )->at( 2 );
    };

    template <typename Derived>
    class NamedMambers<Derived, 4, true> {
    private:
        using Scalar = typename traits<Derived>::Scalar;

    public:
        Scalar& x = static_cast<Derived>( this )->at( 0 );
        Scalar& y = static_cast<Derived>( this )->at( 1 );
        Scalar& z = static_cast<Derived>( this )->at( 2 );
        Scalar& w = static_cast<Derived>( this )->at( 3 );
    };

}  // namespace arc::matrix::detail
