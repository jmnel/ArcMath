#pragma once

#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/MatrixStorageBase.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

namespace arc::detail {

    template <typename ScalarT,
              int RowsT,
              int ColsT,
              int OptionsT,
              typename IndexT,
              typename MemoryTypeT,
              typename DenseInnerT,
              typename DenseOuterT,
              typename StorageOrderT,
              int StrideInnerT,
              int StrideOuterT>
    struct traits<MatrixStorage<ScalarT,
                                RowsT,
                                ColsT,
                                OptionsT,
                                IndexT,
                                MemoryTypeT,
                                DenseInnerT,
                                DenseOuterT,
                                StorageOrderT,
                                StrideInnerT,
                                StrideOuterT>> {

        typedef ScalarT Scalar;
        typedef IndexT Index;
        typedef DenseInnerT DensityInner;
        typedef DenseOuterT DensityOuter;
        typedef StorageOrderT StorageOrder;
        static constexpr Index Rows = RowsT;
        static constexpr Index Cols = ColsT;
        static constexpr Index Options = OptionsT;
        static constexpr Index StrideInner = StrideInnerT;
        static constexpr Index StridgeOuter = StrideOuterT;
    };

    template <typename ScalarT,
              int RowsT,
              int ColsT,
              int OptionsT,
              typename IndexT,
              typename MemoryTypeT,
              typename DenseInnerT,
              typename DenseOuterT,
              typename StorageOrderT,
              int StrideInner,
              int StrideOuter>
    class MatrixStorage : public MatrixStorageBase<MatrixStorage<ScalarT,
                                                                 RowsT,
                                                                 ColsT,
                                                                 OptionsT,
                                                                 IndexT,
                                                                 MemoryTypeT,
                                                                 DenseInnerT,
                                                                 DenseOuterT,
                                                                 StorageOrderT,
                                                                 StrideInner,
                                                                 StrideOuter>> {

        static_assert( RowsT > 0 );
        static_assert( ColsT > 0 );
    };

}  // namespace arc::detail
