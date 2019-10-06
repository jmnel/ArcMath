#include <ostream>
#pragma once

#include "CoefReffs.hpp"
#include "MapAccessor.hpp"
#include "MatrixStorage.hpp"
#include "Printable.hpp"

namespace jmnel::matrix::detail {

    template <typename Derived>
    class MatrixBase : public MatrixStorage<Derived>,
                       public MapAccessor<Derived>,
                       public CoefReffs<Derived>,
                       public Printable<Derived> {
    private:
        using Scalar = typename traits<Derived>::Scalar;

    public:
        MatrixBase() noexcept : MatrixStorage<Derived>() {}
        MatrixBase( Scalar const& x ) noexcept : MatrixStorage<Derived>( x ) {}
        MatrixBase( Scalar* xPtr ) noexcept : MatrixStorage<Derived>( xPtr ) {}
    };

}  // namespace jmnel::matrix::detail
