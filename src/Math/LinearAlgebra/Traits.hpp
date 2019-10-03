#pragma once

namespace arc::detail {

    template <typename T>
    struct traits;

    template <typename T>
    struct traits<const T> : traits<T> {};

    // -- Trait tags --
    struct matrix_row_major_tag {};  /// @todo remove this
    struct matrix_col_major_tag {};  /// @todo remove this

    struct matrix_storage_row_major_tag {};
    struct matrix_storage_col_major_tag {};
    struct matrix_storage_static_tag {};
    struct matrix_storage_dynamic_tag {};
    struct matrix_storage_pointer_ref_tag {};
    struct matrix_storage_dense_tag {};
    struct matrix_storage_sparse_tag {};
    struct matrix_inner_tag {};
    struct matrix_outer_tag {};

    struct matrix_vector_type_tag {};
    struct matrix_matrix_type_tag {};

    // This tests if matrix is vector
    template <typename T,
              bool isVectorT = ( traits<T>::Rows == 1 && traits<T>::Cols != 1 ) ||
                               ( traits<T>::Rows != 1 && traits<T>::Cols == 1 )>
    struct get_matrix_type;

    template <typename T>
    struct get_matrix_type<T, true> {
        typedef matrix_vector_type_tag type;
    };

    template <typename T>
    struct get_matrix_type<T, false> {
        typedef matrix_matrix_type_tag type;
    };

    // Get inner or outer matrix storage density.
    template <typename T, typename InnerOrOuterT>
    struct get_storage_density;

    template <typename T>
    struct get_storage_density<T, matrix_inner_tag> {
        typedef typename traits<T>::DensityInner type;
    };

    template <typename T>
    struct get_storage_density<T, matrix_outer_tag> {
        typedef typename traits<T>::DensityOuter type;
    };

    // Get matrix storage memory implementation type.
    template <typename T>
    struct get_storage_type {
        typedef typename traits<T>::MemoryType type;
    };

    // Get matrix storage order.
    template <typename T>
    struct get_storage_order {
        typedef typename traits<T>::StorageOrder type;
    };

    template <typename T>
    struct isRowMajor;

    template <typename T, bool _isRowMajor = isRowMajor<T>::value>
    struct matrix_storage_order {};

    template <typename T>
    struct isVectorType;

}  // namespace arc::detail
