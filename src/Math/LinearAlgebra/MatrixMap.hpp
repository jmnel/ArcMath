#pragma once

#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/MatrixMapBase.hpp>

namespace arc {

    namespace detail {

        template <typename ScalarT, int RowsT, int ColsT, typename IndexT>
        struct traits<MatrixMap<ScalarT, RowsT, ColsT, IndexT>> {
        };
    }  // namespace detail

    template <typename ScalarT, int RowsT, int ColsT, typename IndexT>
    class MatrixMap : public detail::MatrixMapBase<MatrixMap<ScalarT, RowsT, ColsT, IndexT>> {
    private:
    public:
    };

}  // namespace arc
