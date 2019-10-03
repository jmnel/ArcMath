#pragma once

#include <array>

#include <Math/LinearAlgebra/CoeffRefs.hpp>
#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

using std::array;

namespace arc::detail {

    template <typename Derived,
              typename MemoryTypeT = typename traits<Derived>::MemoryType,
              typename DensityInnerT = typename traits<Derived>::DensityInner,
              typename DensityOuterT = typename traits<Derived>::DensityOuter>

    //              typename DensityInnerT = get_storage_density<Derived, matrix_inner_tag>,
    //              typename DensityOuterT = get_storage_density<Derived, matrix_outer_tag>>
    class MatrixStorageImplementation {
        // Only static memory type is supported.
        static_assert( std::is_same<MemoryTypeT, matrix_storage_static_tag>::value );

        // Only dense storage is supported.
        static_assert( std::is_same<DensityInnerT, matrix_storage_dense_tag>::value );
        static_assert( std::is_same<DensityOuterT, matrix_storage_dense_tag>::value );
    };

    // Dense static storage implementation
    template <typename Derived>
    class MatrixStorageImplementation<Derived,
                                      matrix_storage_static_tag,
                                      matrix_storage_dense_tag,
                                      matrix_storage_dense_tag> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef typename traits<Derived>::Index Index;
        static constexpr Index Rows = traits<Derived>::Rows;
        static constexpr Index Cols = traits<Derived>::Cols;
        //        array<Scalar, Rows * Cols> m_storage{};

    private:
    };

    template <class Derived>
    class MatrixStorageBase : public CoeffRefs<Derived> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef typename traits<Derived>::Index Index;
        static constexpr Index Size = traits<Derived>::Size;
        array<Scalar, Size> m_storage;
    };

    //    template <typename Derived>
    //    class MatrixStorageBase : public MatrixStorageImplementation<Derived,
    //                                                                 matrix_storage_static_tag,
    //                                                                 matrix_storage_dense_tag,
    //                                                                 matrix_storage_dense_tag>,
    //                              public CoeffRefs<Derived> {
    //                array<double, 5> m_storage{};
    //    };

};  // namespace arc::detail
