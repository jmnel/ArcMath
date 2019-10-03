#pragma once

#include <Core/Debug/Assert.hpp>

//#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

namespace arc::detail {

    template <typename Derived,
              typename MatrixVectorTypeT = typename get_matrix_type<Derived>::type,
              typename StorageOrderT = typename get_storage_order<Derived>::type,
              typename DensityInnerT = typename traits<Derived>::DensityInner,
              typename DensityOuterT = typename traits<Derived>::DensityOuter>
    class CoeffRefs {
    };

    // Coefficient reference for dense vector type.
    // Storage order and outer density do not matter.
    template <typename Derived, typename StorageOrderT, typename DensityOuterT>
    class CoeffRefs<Derived,
                    matrix_vector_type_tag,
                    StorageOrderT,
                    matrix_storage_dense_tag,
                    DensityOuterT> {

    private:
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef Scalar CoeffRefsReturnType;
        typedef typename traits<Derived>::Index Index;
        static constexpr Index Size = traits<Derived>::Size;

        Scalar const &coeffs( const Index i ) const {
            massertf( i >= 0, "Matrix index out of bounds." );
            massertf( i < 2, "Matrix index out of bounds." );
            return static_cast<Derived const *>( this )->m_storage[i];
        }

        Scalar &coeffs( const Index i ) {
            massertf( i >= 0, "Matrix index out of bounds." );
            massertf( i < 2, "Matrix index out of bounds." );
            return static_cast<Derived *>( this )->m_storage[i];
        }
    };

    template <typename Derived>
    class CoeffRefs<Derived, matrix_matrix_type_tag, matrix_storage_row_major_tag> {
    private:
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef Scalar CoeffRefsReturnType;
        typedef typename traits<Derived>::Index Index;
        static constexpr Index Rows = traits<Derived>::Rows;
        static constexpr Index Cols = traits<Derived>::Cols;
        static constexpr Index Size = traits<Derived>::Size;

        Scalar const &coeffs( const Index i, const Index j ) const {
            massertf( i >= 0, "Matrix index out of bounds." );
            massertf( j >= 0, "Matrix index out of bounds." );
            massertf( i < Rows, "Matrix index out of bounds." );
            massertf( j < Cols, "Matrix index out of bounds." );
            return static_cast<Derived const *>( this )->m_storage[i * Cols + j];
        }

        Scalar &coeffs( const Index i, const Index j ) {
            massertf( i >= 0, "Matrix index out of bounds." );
            massertf( j >= 0, "Matrix index out of bounds." );
            massertf( i < Rows, "Matrix index out of bounds." );
            massertf( j < Cols, "Matrix index out of bounds." );
            return static_cast<Derived *>( this )->m_storage[i * Cols + j];
        }
    };

    //    template <typename Derived>
    //    class CoeffRefs<Derived, false, matrix_col_major_tag> {
    //    private:
    //    public:
    //        typedef typename traits<Derived>::Scalar Scalar;
    //        typedef Scalar CoeffRefsReturnType;
    //        typedef typename traits<Derived>::Index Index;
    //        static constexpr Index Rows = traits<Derived>::Rows;
    //        static constexpr Index Cols = traits<Derived>::Cols;
    //        static constexpr Index Size = traits<Derived>::Size;

    //        Scalar const &coeffs( const Index i, const Index j ) const {
    //            massertf( i >= 0, "Matrix index out of bounds." );
    //            massertf( i < 2, "Matrix index out of bounds." );
    //            return *static_cast<Derived const *>( this )->m_storage[i];
    //        }

    //        Scalar &coeffs( const Index i ) {
    //            massertf( i >= 0, "Matrix index out of bounds." );
    //            massertf( i < 2, "Matrix index out of bounds." );
    //            return *static_cast<Derived *>( this )->m_storage[i];
    //        }
    //    };

    //    template <typename Derived>

}  // namespace arc::detail
