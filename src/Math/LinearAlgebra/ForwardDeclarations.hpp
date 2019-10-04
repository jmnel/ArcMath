#pragma once

#include <cstddef>

#include <Math/LinearAlgebra/Constants.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

namespace arc {

    template <typename IndexT,
              typename MemoryTypeT,
              typename InnerDensityT,
              typename OuterDensityT,
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
        MatrixDefaultOptions;

    template <typename ScalarT, int RowsT, int ColsT, typename OptionsT>
    class MatrixMap;

    namespace detail {

        template <typename Derived>
        class MatrixStorage;

        //        template <typename Derived, typename MatrixTypeT = get_matrix_type<Derived>>
        //        class MatrixPrinter;

    }  // namespace detail

    template <typename ScalarT, int RowsT, int ColsT, typename OptionsT = MatrixDefaultOptions>
    class Matrix;

}  // namespace arc
