#pragma once

#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/MatrixStorageBase.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

namespace arc::detail {

    template <typename Derived>
    class MatrixStorage : public MatrixStorageBase<Derived> {
    public:
    private:
        static_assert( traits<Derived>::Rows > 0 );
        static_assert( traits<Derived>::Cols > 0 );
    };

}  // namespace arc::detail
