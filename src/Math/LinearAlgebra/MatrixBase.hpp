#include <ostream>
#pragma once

#include "BinaryOperators.hpp"
#include "CoefReffs.hpp"
#include "MapAccessor.hpp"
#include "MatrixIteratorAccess.hpp"
#include "MatrixStorage.hpp"
#include "Printable.hpp"

namespace jmnel::matrix::detail {

    template <typename Derived>
    class MatrixBase : public MatrixStorage<Derived>,
                       public MapAccessor<Derived>,
                       public CoefReffs<Derived>,
                       public Printable<Derived>,
                       public IteratorAccess<Derived> {
    private:
        using Scalar = typename traits<Derived>::Scalar;

    public:
        MatrixBase() noexcept : MatrixStorage<Derived>() {}
        MatrixBase( Scalar const& x ) noexcept : MatrixStorage<Derived>( x ) {}
        MatrixBase( Scalar* xPtr ) noexcept : MatrixStorage<Derived>( xPtr ) {}
    };

}  // namespace jmnel::matrix::detail
