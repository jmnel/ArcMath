#pragma once

#include "MatrixMapBase.hpp"

namespace arc::matrix::detail {

    template <typename ScalarT, size_t rowsT, size_t colsT, typename OptionsT>
    class MatrixMap : public MatrixMapBase<MatrixMap<ScalarT, rowsT, colsT, OptionsT>> {
    private:
        using SelfType = MatrixMap<ScalarT, rowsT, colsT, OptionsT>;
        using Base = MatrixMapBase<SelfType>;
        using Scalar = ScalarT;

    public:
        explicit MatrixMap( Scalar const* const storage ) noexcept : Base( storage ) {}

        MatrixMap( MatrixMap const& ) = delete;
        MatrixMap( MatrixMap&& ) = delete;
    };

}  // namespace arc::matrix::detail
