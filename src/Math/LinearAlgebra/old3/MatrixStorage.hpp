#pragma once

#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/MatrixStorageBase.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

namespace arc::detail {

    template <typename Derived>
    class MatrixStorage : public MatrixStorageBase<Derived> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef MatrixStorageBase<Derived> StorageBase;

    private:
    public:
        //        template <typename T>
        //        void init1( T* v,
        //                    std::enable_if<std::is_same<typename
        //                    traits<Derived>::Options::MemoryType,
        //                                                matrix_storage_pointer_ref_tag>::value>* =
        //                                                0 ) {
        //            cout << "init1" << endl;
        //        }

        //        MatrixStorage() noexcept;

        //        template <typename T>
        //        explicit MatrixStorage( T* v ) {
        //            init1( v );
        //        }

        //        MatrixStorage( T* v,
        //                       std::enable_if_t<std::is_same<typename
        //                       traits<Derived>::Options::MemoryType,
        //                                                     matrix_storage_pointer_ref_tag>::value>*
        //                                                     = 0 )
        //            : Base( v ) {
        //        }

    private:
        static_assert( traits<Derived>::rows() > 0 );
        static_assert( traits<Derived>::cols() > 0 );
    };

}  // namespace arc::detail
