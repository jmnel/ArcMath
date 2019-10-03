#pragma once

#include <cstddef>

#include <Math/LinearAlgebra/Constants.hpp>

namespace arc {

    namespace detail {

        template <typename ScalarT, int RowsT, int ColsT, typename IndexT>
        class MatrixMap;

        template <typename ScalarT,
                  int RowsT,
                  int ColsT,
                  int OptionsT,
                  typename IndexT,
                  typename MemoryTypeT,
                  typename DenseInnerT,
                  typename DenseOuterT,
                  typename OrderT,
                  int StrideInner = 1,
                  int StrideOuter = 1>
        class MatrixStorage;

    }  // namespace detail

    template <typename ScalarT,
              int RowsT,
              int ColsT,
              int OptionsT = ( ( RowsT == 1 && ColsT != 1 )
                                   ? detail::RowMajor
                                   : ( RowsT != 1 && ColsT == 1 )
                                         ? detail::ColMajor
                                         : detail::DefaultMatrixStorageOrder ),
              typename _Index = size_t>
    class Matrix;

}  // namespace arc
