#pragma once

namespace jmnel::matrix {

    enum class MatrixStorageOrder { RowMajor, ColMajor };
    enum class MatrixDensity { Dense, Sparse };
    enum class MatrixStorageType { Static, Dynamic, PointerReference };
    enum class MatrixDimension { One, Two };

}  // namespace jmnel::matrix
