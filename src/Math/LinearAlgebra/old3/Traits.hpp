#pragma once

#include <type_traits>

using std::remove_const_t;
using std::remove_reference_t;

namespace arc::detail {

    enum class MatrixStorageOrder { RowMajor, RowMinor };

    template <typename T>
    struct traits;

    template <typename T>
    struct traits<const T> : traits<T> {};

    template <typename T>
    struct get_traits {
        using type = traits<remove_reference_t<remove_const_t<T>>>;
    };

    template <typename T>
    using get_traits_t = typename get_traits<T>::type;

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
    struct matrix_has_named_members_tag {};

    struct matrix_vector_type_tag {};
    struct matrix_matrix_type_tag {};

    // Remove this.
    template <typename T, bool isVectorT = traits<T>::isVectorType()>
    struct get_matrix_type;

    template <typename T>
    struct get_matrix_type<T, true> {
        typedef matrix_vector_type_tag type;
    };

    template <typename T>
    struct get_matrix_type<T, false> {
        typedef matrix_matrix_type_tag type;
    };

    // Tests if matrix is vector.
    //    template <typename T>
    //    struct matrix_is_vector_type {
    //        static constexpr bool value =
    //            std::is_same<get_matrix_type<T>, matrix_vector_type_tag>::value;
    //    };

    // Get inner or outer matrix storage density.
    template <typename T, typename InnerOrOuterT>
    struct get_storage_density;

    template <typename T>
    struct get_storage_density<T, matrix_inner_tag> {
        typedef typename traits<T>::Options::DensityInner type;
    };

    template <typename T>
    struct get_storage_density<T, matrix_outer_tag> {
        typedef typename traits<T>::Options::DensityOuter type;
    };

    // Get matrix storage memory implementation type.
    template <typename T>
    struct get_storage_type {
        typedef typename traits<T>::Options::MemoryType type;
    };

    // Get matrix storage order.
    template <typename T>
    struct get_storage_order {
        typedef typename traits<T>::Options::StorageOrder type;
    };

    // Get if matrix has named members.
    //    template <typename T>
    //    struct get_named_member_refs_enabled {
    //        static constexpr bool value =
    //            std::is_same<get_named_member_refs_enabled<T>,
    //            matrix_has_named_members_tag>::value;
    //    };

    //    template <typename T>
    //    struct isRowMajor;

    //    template <typename T, bool isRowMajorT = isRowMajor<T>::value>
    //    struct matrix_storage_order {};

    //    template <typename T>
    //    struct isVectorType;

}  // namespace arc::detail
