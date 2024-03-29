#include <cstddef>
#include "/usr/lib64/gcc/x86_64-pc-linux-gnu/8.3.0/include/g++-v8/x86_64-pc-linux-gnu/bits/c++config.h"
#pragma once

#include <type_traits>

#include <Core/Debug/Assert.hpp>

#include "Common.hpp"
#include "Traits.hpp"

using std::cout;
using std::endl;

namespace jmnel::matrix::detail {

    template <typename Derived, bool isVectorTypeT = traits<Derived>::isVectorType()>
    class CoefReffs;

    // -- Vector type coefficient reference specialization --
    template <typename Derived>
    class CoefReffs<Derived, true> {
    private:
        using Scalar = typename traits<Derived>::Scalar;
        static constexpr ptrdiff_t innerStride = traits<Derived>::innerStride;

    public:
        Scalar const& coeffs( const size_t i ) const {
            assertf( i < traits<Derived>::size );
            if( innerStride != 1 ) {
                //                cout << "innerStride=" << innerStride << endl;
                //                assertf( false );
            }
            return static_cast<Derived const*>( this )->storageAt( i * innerStride );
        }

        Scalar& coeffs( const size_t i ) {
            assertf( i < traits<Derived>::size );
            return static_cast<Derived*>( this )->storageAt( i * innerStride );
        }
    };

    // -- Matrix type coefficient reference specialization --
    template <typename Derived>
    class CoefReffs<Derived, false> {
    private:
        using Scalar = typename traits<Derived>::Scalar;
        static constexpr size_t rows = traits<Derived>::rows;
        static constexpr size_t cols = traits<Derived>::cols;
        static constexpr ptrdiff_t innerStride = traits<Derived>::innerStride;
        static constexpr ptrdiff_t outerStride = traits<Derived>::outerStride;
        static constexpr MatrixStorageOrder storageOrder = traits<Derived>::storageOrder;

    public:
        static_assert( traits<Derived>::storageOrder == MatrixStorageOrder::RowMajor,
                       "Column major storage not yet supported." );

        Scalar const& coeffs( const size_t i,
                              const size_t j,
                              std::enable_if_t<std::is_same_v<Scalar, double>, void>* = 0 ) const {
            assertf( i < traits<Derived>::rows );
            assertf( j < traits<Derived>::cols );
            assertf( outerStride == 1 );
            assertf( innerStride == 1 );
            return static_cast<Derived const*>( this )->storageAt( j * innerStride +
                                                                   i * outerStride * cols );
        }

        Scalar& coeffs( const size_t i, const size_t j ) {
            assertf( i < traits<Derived>::rows );
            assertf( j < traits<Derived>::cols );
            //            cout << "storage @" << i << ", " << j << endl;
            //            auto k = j * innerStride + j *
            assertf( innerStride == 1 );
            assertf( outerStride == 1 );
            return static_cast<Derived*>( this )->storageAt( j * innerStride +
                                                             i * outerStride * cols );
        }
    };

}  // namespace jmnel::matrix::detail
