#pragma once

#include "CoefReffs.hpp"
#include "MapAccessor.hpp"
#include "MatrixStorage.hpp"

namespace arc::matrix::detail {

    template <class Derived>
    class MatrixMapBase : public MatrixStorage<Derived>,
                          public MapAccessor<Derived>,
                          public CoefReffs<Derived> {
    private:
        using Scalar = typename traits<Derived>::Scalar;

    public:
        MatrixMapBase( Scalar* xPointer ) noexcept;
    };

}  // namespace arc::matrix::detail
