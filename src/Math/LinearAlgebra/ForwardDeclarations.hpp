#pragma once

#include <cstddef>

#include <Math/LinearAlgebra/Constants.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

namespace arc {

    template <typename IndexT,
              typename MemoryTypeT,
              typename DensityInnerT,
              typename DensityOuterT,
              typename StorageOrderT,
              int StrideInnerT,
              int StrideOuterT,
              typename HasNamedMembersT>
    struct MatrixOptions;

    typedef MatrixOptions<size_t,
                          detail::matrix_storage_static_tag,
                          detail::matrix_storage_dense_tag,
                          detail::matrix_storage_dense_tag,
                          detail::matrix_storage_row_major_tag,
                          1,
                          1,
                          detail::matrix_has_named_members_tag>
        MatrixDeaultOptions;

    namespace detail {

        template <typename ScalarT, int RowsT, int ColsT, typename IndexT>
        class MatrixMap;

        template <typename Derived>
        class MatrixStorage;

    }  // namespace detail

    template <typename ScalarT,
              int RowsT,
              int ColsT,
              typename OptionsT = MatrixDeaultOptions>
    class Matrix;

}  // namespace arc
