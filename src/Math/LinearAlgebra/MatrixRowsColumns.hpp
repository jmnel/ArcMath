#pragma once

#include <type_traits>

#include <Math/LinearAlgebra/MatrixMap.hpp>

namespace arc::detail {

    template <typename ScalarT, int ColsT, int SubRowLengthT, typename OptionsT>
    //    template < Index subRowLengthT>
    using MatrixRowType = MatrixMap<
        ScalarT,
        1,
        in_range<typename OptionsT::Index, SubRowLengthT, 0, ColsT, typename OptionsT::Index>::
            value,
        MatrixOptions<typename OptionsT::Index,
                      matrix_storage_pointer_ref_tag,
                      matrix_storage_dense_tag,
                      matrix_storage_dense_tag,
                      matrix_storage_row_major_tag,
                      1,
                      strideOuter() * cols(),
                      typename traits<Derived>::Options::HasNamedMembers>>;

    // Column type for matrix map.
    template <Index subColLengthT>
    using ColumnType = MatrixMap<Scalar,
                                 in_range<subColLengthT, 0, rows()>::value,
                                 1,
                                 MatrixOptions<Index,
                                               matrix_storage_pointer_ref_tag,
                                               matrix_storage_dense_tag,
                                               matrix_storage_dense_tag,
                                               matrix_storage_row_major_tag,
                                               strideOuter() * cols(),
                                               1,
                                               typename traits<Derived>::Options::HasNamedMembers>>;

}  // namespace arc::detail
