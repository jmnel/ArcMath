#include <memory>
#pragma once

#include <type_traits>

#include "Common.hpp"
#include "ForwardDeclare.hpp"
#include "Traits.hpp"

namespace jmnel::matrix::detail {

    template <typename Derived, bool isVectorType = traits<Derived>::isVectorType()>
    class AccessOperators;

    template <typename Derived>
    class AccessOperators<Derived, true> {
    private:
        using Scalar = typename traits<Derived>::Scalar;
        static constexpr auto baseSize = traits<Derived>::size;
        static constexpr auto baseInnerStride = traits<Derived>::innerStride;
        static constexpr auto baseOuterStride = traits<Derived>::outerStride;
        static constexpr bool baseHasNamedMembers = traits<Derived>::hasNamedMembers;
        static constexpr MatrixStorageOrder baseStorageOrder = traits<Derived>::storageOrder;

    public:
        auto &operator[]( const size_t i ) {
            assertf( i < baseSize );
            return static_cast<Derived *>( this )->coeffs( i );
        }

        auto const &operator[]( const size_t i ) const {
            assertf( i < baseSize );
            return static_cast<const Derived *>( this )->coeffs( i );
        }

        auto &operator()( const size_t i ) {
            assertf( i < baseSize );
            return static_cast<Derived *>( this )->coeffs( i );
        }

        auto const &operator()( const size_t i ) const {
            assertf( i < baseSize );
            return static_cast<const Derived *>( this )->coeffs( i );
        }
    };

    template <typename Derived>
    class AccessOperators<Derived, false> {
    private:
        using Scalar = typename traits<Derived>::Scalar;
        static constexpr auto baseRows = traits<Derived>::rows;
        static constexpr auto baseCols = traits<Derived>::cols;
        static constexpr auto baseInnerStride = traits<Derived>::innerStride;
        static constexpr auto baseOuterStride = traits<Derived>::outerStride;
        static constexpr bool baseHasNamedMembers = traits<Derived>::hasNamedMembers;
        static constexpr MatrixStorageOrder baseStorageOrder = traits<Derived>::storageOrder;

    public:
        auto &operator[]( const size_t i ) {

            assertf( i < baseRows );
            using ReturnOptions = MatrixOptions<MatrixStorageType::PointerReference,
                                                MatrixStorageOrder::RowMajor,
                                                MatrixDensity::Dense,
                                                MatrixDensity::Dense,
                                                baseInnerStride,
                                                baseOuterStride * baseCols,  // Doesn't matter
                                                baseHasNamedMembers>;
            return Matrix<Scalar, 1, baseCols, ReturnOptions>(
                &( static_cast<Derived *>( this )->coeffs( i, 0 ) ) );
        }

        auto const &operator[]( const size_t i ) const {

            using ReturnOptions = MatrixOptions<MatrixStorageType::PointerReference,
                                                MatrixStorageOrder::RowMajor,
                                                MatrixDensity::Dense,
                                                MatrixDensity::Dense,
                                                baseInnerStride,
                                                baseOuterStride * baseCols,  // Doesn't matter
                                                baseHasNamedMembers>;
            assertf( i < baseRows );
            return Matrix<Scalar, 1, baseCols, ReturnOptions>(
                &( static_cast<const Derived *>( this )->coeffs( i, 0 ) ) );
        }

        auto &operator()( const size_t i ) {

            assertf( i < baseRows );
            using ReturnOptions = MatrixOptions<MatrixStorageType::PointerReference,
                                                MatrixStorageOrder::RowMajor,
                                                MatrixDensity::Dense,
                                                MatrixDensity::Dense,
                                                baseInnerStride,
                                                baseOuterStride * baseCols,  // Doesn't matter
                                                baseHasNamedMembers>;
            return Matrix<Scalar, 1, baseCols, ReturnOptions>(
                &( static_cast<Derived *>( this )->coeffs( i, 0 ) ) );
        }

        auto const &operator()( const size_t i ) const {

            using ReturnOptions = MatrixOptions<MatrixStorageType::PointerReference,
                                                MatrixStorageOrder::RowMajor,
                                                MatrixDensity::Dense,
                                                MatrixDensity::Dense,
                                                baseInnerStride,
                                                baseOuterStride * baseCols,  // Doesn't matter
                                                baseHasNamedMembers>;
            assertf( i < baseRows );
            return Matrix<Scalar, 1, baseCols, ReturnOptions>(
                &( static_cast<const Derived *>( this )->coeffs( i, 0 ) ) );
        }

        auto const &operator()( const size_t i, const size_t j ) const {
            assertf( i < baseRows );
            assertf( j < baseCols );
            return static_cast<Derived const *>( this )->coeffs( i, j );
        }

        auto &operator()( const size_t i, const size_t j ) {
            assertf( i < baseRows );
            assertf( j < baseCols );
            return static_cast<Derived *>( this )->coeffs( i, j );
        }
    };

}  // namespace jmnel::matrix::detail
