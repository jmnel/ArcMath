#include <cmath>
#pragma once
#include <cstddef>

#include <type_traits>

#include <Core/Debug/Assert.hpp>
#include "Common.hpp"
#include "GenericPointerIterator.hpp"
#include "MatrixOptions.hpp"
#include "Traits.hpp"

namespace jmnel::matrix::detail {

    using namespace generics;

    template <typename Derived>
    class IteratorAccess {
    private:
        using Scalar = typename traits<Derived>::Scalar;

        static constexpr auto rows = traits<Derived>::rows;
        static constexpr auto cols = traits<Derived>::cols;
        static constexpr auto size = traits<Derived>::size;
        static constexpr auto innerStride = traits<Derived>::innerStride;
        static constexpr auto outerStride = traits<Derived>::outerStride;
        static constexpr auto isVectorType = traits<Derived>::isVectorType();
        static constexpr auto hasNamedMembers = traits<Derived>::hasNamedMembers;

        using RowReturnOptions = MatrixOptions<MatrixStorageType::PointerReference,
                                               MatrixStorageOrder::RowMajor,
                                               MatrixDensity::Dense,
                                               MatrixDensity::Dense,
                                               innerStride,
                                               outerStride,
                                               hasNamedMembers>;

        template <typename T>
        struct ConversionRule {
            using type = Matrix<Scalar, 1, cols, RowReturnOptions>;
        };
        //        template <T>
        //        struct foo {

        //        };

        using ElementIterator = GenericPointerIterator<Scalar, innerStride>;
        using ConstElementIterator = ConstGenericPointerIterator<Scalar, innerStride>;
        using RowIterator = GenericPointerIterator<Scalar, outerStride * cols, ConversionRule>;
        using ConstRowIterator =
            ConstGenericPointerIterator<Scalar, outerStride * cols, ConversionRule>;

        //        using ElementIterator = std::enable_if_t<traits<Derived>::isVectorType(),
        //                                                 GenericPointerIterator<Scalar,
        //                                                 innerStride>>;

    public:
        auto beginElement() {
            if constexpr( isVectorType ) {
                return ElementIterator( &static_cast<Derived *>( this )->coeffs( 0 ) );
            } else {
                return ElementIterator( &static_cast<Derived *>( this )->coeffs( 0, 0 ) );
            }
        }

        auto endElement() {
            if constexpr( isVectorType ) {
                //                return ElementIterator( &static_cast<Derived *>( this )->coeffs( 0
                //                ) );
                return ElementIterator( &static_cast<Derived *>( this )->coeffs( 0 ) +
                                        size * innerStride );
            } else {
                return ElementIterator( &static_cast<Derived *>( this )->coeffs( 0, 0 ) +
                                        rows * outerStride * cols );
            }
        }

        auto begin() {
            if constexpr( isVectorType ) {
                return ElementIterator( &static_cast<Derived *>( this )->coeffs( 0 ) );
            } else {
                return RowIterator( &static_cast<Derived *>( this )->coeffs( 0, 0 ) );
            }
        }

        auto end() {
            if constexpr( isVectorType ) {
                return ElementIterator( &static_cast<Derived *>( this )->coeffs( 0 ) +
                                        size * innerStride );
            } else {
                return RowIterator( &static_cast<Derived *>( this )->coeffs( 0, 0 ) +
                                    rows * outerStride * cols );
            }
        }

        auto cbeginElement() const {
            if constexpr( isVectorType ) {
                return ConstElementIterator( &static_cast<const Derived *>( this )->coeffs( 0 ) );
            } else {
                return ConstElementIterator(
                    &static_cast<const Derived *>( this )->coeffs( 0, 0 ) );
            }
        }

        auto cendElement() const {
            if constexpr( isVectorType ) {
                return ConstElementIterator( &static_cast<const Derived *>( this )->coeffs( 0 ) );
            } else {
                return ConstElementIterator(
                    &static_cast<const Derived *>( this )->coeffs( 0, 0 ) );
            }
        }

        auto cbegin() const {
            if constexpr( isVectorType ) {
                return ConstElementIterator( &static_cast<const Derived *>( this )->coeffs( 0 ) );
            } else {
                return ConstRowIterator( &static_cast<const Derived *>( this )->coeffs( 0, 0 ) );
            }
        }

        auto cend() const {
            if constexpr( isVectorType ) {
                return ConstElementIterator( &static_cast<const Derived *>( this )->coeffs( 0 ) +
                                             size * innerStride );
            } else {
                //        assertf( false );
                return ConstRowIterator( &static_cast<const Derived *>( this )->coeffs( 0, 0 ) +
                                         rows * outerStride * cols );
            }
        }
    };

}  // namespace jmnel::matrix::detail
