#pragma once

#include <Core/Debug/Assert.hpp>

//#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

namespace arc::detail {

    template <typename Derived,
              typename MatrixVectorTypeT = typename get_matrix_type<Derived>::type,
              typename StorageOrderT = typename get_storage_order<Derived>::type,
              typename InnerDensityT = typename traits<Derived>::Options::InnerDensity,
              typename OuterDensityT = typename traits<Derived>::Options::OuterDensity>
    class CoeffRefs {

        // Only row major oder is supported right now.
        static_assert( std::is_same<StorageOrderT, matrix_storage_row_major_tag>::value );

        // Only dense storage is supported right now.
        static_assert( std::is_same<InnerDensityT, matrix_storage_dense_tag>::value );
        static_assert( std::is_same<OuterDensityT, matrix_storage_dense_tag>::value );
    };

    // Coefficient reference for dense vector type.
    // AFFECTED BY:
    // Storage order and outer density do not matter.
    template <typename Derived, typename StorageOrderT, typename OuterDensityT>
    class CoeffRefs<Derived,
                    matrix_vector_type_tag,
                    StorageOrderT,
                    matrix_storage_dense_tag,
                    OuterDensityT> {

    private:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef Scalar CoeffRefsReturnType;
        typedef typename traits<Derived>::Index Index;
        static constexpr Index rows() { return traits<Derived>::rows(); }
        static constexpr Index cols() { return traits<Derived>::cols(); }
        static constexpr Index size() { return traits<Derived>::size(); }
        static constexpr Index strideInner() { return traits<Derived>::strideInner(); }

    public:
        Scalar const &coeffs( const Index i ) const {
            const auto iMapped = i * strideInner();
            massertf( iMapped >= 0, "Matrix index out of bounds." );
            massertf( i < size(), "Matrix index out of bounds." );
            return static_cast<Derived const *>( this )->m_storage[iMapped];
        }

        Scalar &coeffs( const Index i ) {
            const auto iMapped = i * strideInner();
            massertf( iMapped >= 0, "Matrix index out of bounds." );
            massertf( i < size(), "Matrix index out of bounds." );
            return static_cast<Derived *>( this )->m_storage[iMapped];
        }
    };

    // Coefficient reference for dense matrix type.
    // DEPENDS ON: storage order, inner density, outer density
    template <typename Derived>
    class CoeffRefs<Derived, matrix_matrix_type_tag, matrix_storage_row_major_tag> {
    private:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef Scalar CoeffRefsReturnType;
        typedef typename traits<Derived>::Index Index;

        static constexpr Index rows() { return traits<Derived>::rows(); }
        static constexpr Index cols() { return traits<Derived>::cols(); }
        static constexpr Index size() { return traits<Derived>::size(); }

    public:
        Scalar const &coeffs( const Index i, const Index j ) const {
            massertf( i >= 0, "Matrix index out of bounds." );
            massertf( j >= 0, "Matrix index out of bounds." );
            massertf( i < rows(), "Matrix index out of bounds." );
            massertf( j < cols(), "Matrix index out of bounds." );
            return static_cast<Derived const *>( this )->m_storage[i * cols() + j];
        }

        Scalar &coeffs( const Index i, const Index j ) {
            massertf( i >= 0, "Matrix index out of bounds." );
            massertf( j >= 0, "Matrix index out of bounds." );
            massertf( i < rows(), "Matrix index out of bounds." );
            massertf( j < cols(), "Matrix index out of bounds." );
            return static_cast<Derived *>( this )->m_storage[i * cols() + j];
        }
    };

}  // namespace arc::detail
