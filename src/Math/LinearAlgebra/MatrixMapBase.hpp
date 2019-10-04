#pragma once

#include <Math/LinearAlgebra/CoeffRefs.hpp>
#include <Math/LinearAlgebra/MatrixPrinter.hpp>
#include <Math/LinearAlgebra/MatrixStorage.hpp>

namespace arc::detail {

    template <typename Derived>
    class MatrixMapBase : public MatrixStorage<Derived>,
                          public CoeffRefs<Derived>,
                          public MatrixPrinter<Derived> {
    public:
        typedef MatrixStorage<Derived> Storage;
        typedef typename traits<Derived>::Scalar Scalar;

    private:
    public:
        explicit MatrixMapBase( Scalar* startPointer ) {
            static_cast<Storage*>( this )->init1( startPointer );
        }
    };

}  // namespace arc::detail
