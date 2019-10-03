#pragma once

#include <array>

#include <Math/LinearAlgebra/CoeffRefs.hpp>
#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

using std::array;

namespace arc::detail {

    template <typename Derived,
              typename MemoryTypeT,
              typename DensityInnerT = get_storage_density<Derived, matrix_inner_tag>,
              typename DensityOuterT = get_storage_density<Derived, matrix_outer_tag>>
    class MatrixStorageImplementation {};

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
        array<int, Rows * Cols> m_data{};

    private:
    };

    template <typename Derived>
    class MatrixStorageBase : public MatrixStorageImplementation<Derived,
                                                                 matrix_storage_static_tag,
                                                                 matrix_storage_dense_tag,
                                                                 matrix_storage_dense_tag> {
    };

};  // namespace arc::detail
