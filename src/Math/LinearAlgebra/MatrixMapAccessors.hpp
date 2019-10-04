#pragma once

#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/MatrixMap.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

namespace arc::detail {

    template <typename Derived,
              typename MatrixVectorTypeT = typename get_matrix_type<Derived>::type,
              typename StorageOrderT = typename get_storage_order<Derived>::type,
              typename InnerDensityT = typename traits<Derived>::Options::InnerDensity,
              typename OuterDensityT = typename traits<Derived>::Options::OuterDensity>
    class MatrixMapAccessors {};

    // -- Matrix map accessor for dense matrix type with row order --
    template <typename Derived>
    class MatrixMapAccessors<Derived,
                             matrix_matrix_type_tag,
                             matrix_storage_row_major_tag,
                             matrix_storage_dense_tag,
                             matrix_storage_dense_tag> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef typename traits<Derived>::Options::Index Index;

    private:
        static constexpr Index rows() { return traits<Derived>::rows(); };
        static constexpr Index cols() { return traits<Derived>::cols(); };
        static constexpr Index strideOuter() { return traits<Derived>::Options::strideOuter(); };
        static constexpr Index strideInner() { return traits<Derived>::Options::strideInner(); };

        template <Index N, Index MinT, Index MaxT, typename TypeT = Index>
        struct in_range {
            static_assert( N >= MinT && N <= MaxT, "in_range assert failed." );
            static constexpr std::enable_if_t<N >= MinT && N <= MaxT, TypeT> value = N;
        };

    public:
        // Row type for matrix map.
        template <Index subRowLengthT>
        using RowType =
            MatrixMap<Scalar,
                      1,
                      in_range<subRowLengthT, 0, cols()>::value,
                      MatrixOptions<Index,
                                    matrix_storage_pointer_ref_tag,
                                    matrix_storage_dense_tag,
                                    matrix_storage_dense_tag,
                                    matrix_storage_row_major_tag,
                                    1,
                                    strideOuter() * cols(),
                                    typename traits<Derived>::Options::HasNamedMembers>>;

        // Column type for matrix map.
        template <Index subColLengthT>
        using ColumnType =
            MatrixMap<Scalar,
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

        // -- row function --
        RowType<cols()> row( const Index i ) {
            assertf( i >= 0 );
            assertf( i < rows() );

            static constexpr auto rowStrideOuter = RowType<cols()>::strideOuter();
            auto startPtr = &static_cast<Derived*>( this )->m_storage[i * rowStrideOuter];
            return RowType<cols()>( startPtr );
        }

        // -- subRow function --
        template <Index LengthT>
        RowType<LengthT> subRow( const Index iRow, const Index offset = 0 ) {
            assertf( iRow >= 0 );
            assertf( iRow < rows() );
            assertf( offset + LengthT <= cols() );

            static constexpr auto rowStrideOuter = RowType<LengthT>::strideOuter();
            static constexpr auto rowStrideInner = RowType<LengthT>::strideInner();
            auto startPtr = &static_cast<Derived*>( this )
                                 ->m_storage[iRow * rowStrideOuter + offset * rowStrideInner];
            return RowType<LengthT>( startPtr );
        }

        // -- col function --
        ColumnType<rows()> col( const Index i ) {
            assertf( i >= 0 );
            assertf( i < cols() );

            static constexpr auto colStrideOuter = ColumnType<rows()>::strideOuter();
            auto startPtr = &static_cast<Derived*>( this )->m_storage[i * colStrideOuter];
            return ColumnType<rows()>( startPtr );
        }

        // -- subCol function --
        template <Index LengthT>
        ColumnType<LengthT> subCol( const Index iCol, const Index offset = 0 ) {
            assertf( iCol >= 0 );
            assertf( iCol < cols() );
            assertf( offset + LengthT <= rows() );

            static constexpr auto colStrideOuter = ColumnType<LengthT>::strideOuter();
            static constexpr auto colStrideInner = ColumnType<LengthT>::strideInner();
            auto startPtr = &static_cast<Derived*>( this )
                                 ->m_storage[iCol * colStrideOuter + offset * colStrideInner];
            return ColumnType<LengthT>( startPtr );
        }
    };

}  // namespace arc::detail
