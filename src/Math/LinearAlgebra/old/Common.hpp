#pragma once

namespace jmnel::matrix {

    enum class OrderPolicy { RowMajor, ColMajor };
    enum class DensityPolicy { Dense, Sparse };
    enum class StoragePolicy { Static, Dynamic, PointerReference };
    enum class MatrixDimension { One, Two };  /// @todo Get rid of this.

}  // namespace jmnel::matrix
