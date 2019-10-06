#include <algorithm>

#include <Core/Debug/Assert.hpp>

#include "Common.hpp"
#include "MatrixOptions.hpp"
#include "Traits.hpp"
namespace jmnel::matrix::detail {

    template <typename Derived,
              MatrixDimension dimensionT = traits<Derived>::dimension,
              MatrixDensity innerDensityT = traits<Derived>::innerDensity,
              MatrixDensity outerDensityT = traits<Derived>::outerDensity>
    class MapAccessor;

    // -- Map accessor partial specialization for dense matrices of type vector --
    template <typename Derived>
    class MapAccessor<Derived, MatrixDimension::One, MatrixDensity::Dense, MatrixDensity::Dense> {
    private:
        using Scalar = typename traits<Derived>::Scalar;
        static constexpr auto baseSize = traits<Derived>::size;
        static constexpr auto baseInnerStride = traits<Derived>::innerStride;
        static constexpr auto baseOuterStride = traits<Derived>::outerStride;
        static constexpr bool baseHasNamedMembers = traits<Derived>::hasNamedMembers;

    public:
        template <size_t lengthT>
        auto subset( const size_t offset = 0 ) {
            static_assert( lengthT <= baseSize );
            assertf( offset + lengthT <= baseSize );
            using ReturnOptions = MatrixOptions<MatrixStorageType::PointerReference,
                                                MatrixStorageOrder::RowMajor,
                                                MatrixDensity::Dense,
                                                MatrixDensity::Dense,
                                                baseInnerStride,
                                                baseOuterStride,
                                                baseHasNamedMembers>;

            return Matrix<Scalar, 1, baseSize, ReturnOptions>(
                &static_cast<Derived*>( this )->coeffs( offset ) );
        }
    };

    // -- Map accessor partial specialization for dense matrices of dimension 2 --
    template <typename Derived>
    class MapAccessor<Derived, MatrixDimension::Two, MatrixDensity::Dense, MatrixDensity::Dense> {
    private:
        using Scalar = typename traits<Derived>::Scalar;
        static constexpr auto baseRows = traits<Derived>::rows;
        static constexpr auto baseCols = traits<Derived>::cols;
        static constexpr size_t baseSize = traits<Derived>::size;
        static constexpr auto baseInnerStride = traits<Derived>::innerStride;
        static constexpr auto baseOuterStride = traits<Derived>::outerStride;
        static constexpr bool baseHasNamedMembers = traits<Derived>::hasNamedMembers;
        static constexpr MatrixStorageOrder baseStorageOrder = traits<Derived>::storageOrder;

    public:
        auto row( const size_t i ) {
            assertf( i <= baseRows );

            if constexpr( baseStorageOrder == MatrixStorageOrder::RowMajor ) {
                using ReturnOptions = MatrixOptions<MatrixStorageType::PointerReference,
                                                    MatrixStorageOrder::RowMajor,
                                                    MatrixDensity::Dense,
                                                    MatrixDensity::Dense,
                                                    baseInnerStride,
                                                    baseOuterStride * baseCols,  // Doesn't matter
                                                    baseHasNamedMembers>;
                return Matrix<Scalar, 1, baseCols, ReturnOptions>(
                    &( static_cast<Derived*>( this )->coeffs( i, 0 ) ) );
            }
        }

        auto col( const size_t j ) {
            assertf( j <= baseCols );

            if constexpr( baseStorageOrder == MatrixStorageOrder::RowMajor ) {
                using ReturnOptions = MatrixOptions<
                    MatrixStorageType::PointerReference,
                    MatrixStorageOrder::RowMajor,
                    MatrixDensity::Dense,
                    MatrixDensity::Dense,
                    1 * baseCols,
                    1,
                    //                                                    baseOuterStride *
                    //                                                    baseRows, baseInnerStride,
                    //                                                    // Doesn't matter
                    baseHasNamedMembers>;
                return Matrix<Scalar, 1, baseRows, ReturnOptions>(
                    &( static_cast<Derived*>( this )->coeffs( 0, j ) ) );
            }
        }

        auto row( const size_t i ) const {
            assertf( i <= baseRows );

            if constexpr( baseStorageOrder == MatrixStorageOrder::RowMajor ) {
                using ReturnOptions = MatrixOptions<MatrixStorageType::PointerReference,
                                                    MatrixStorageOrder::RowMajor,
                                                    MatrixDensity::Dense,
                                                    MatrixDensity::Dense,
                                                    baseInnerStride,
                                                    baseOuterStride * baseCols,  // Doesn't matter
                                                    baseHasNamedMembers>;
                return Matrix<Scalar, 1, baseCols, ReturnOptions>(
                    &( static_cast<const Derived*>( this )->coeffs( i, 1 ) ) );
            }
        }

        auto col( const size_t j ) const {
            assertf( j <= baseCols );

            if constexpr( baseStorageOrder == MatrixStorageOrder::RowMajor ) {
                using ReturnOptions = MatrixOptions<
                    MatrixStorageType::PointerReference,
                    MatrixStorageOrder::RowMajor,
                    MatrixDensity::Dense,
                    MatrixDensity::Dense,
                    baseInnerStride * baseCols,
                    1,
                    //                                                    baseOuterStride *
                    //                                                    baseRows, baseInnerStride,
                    //                                                    // Doesn't matter
                    baseHasNamedMembers>;
                return Matrix<Scalar, 1, baseRows, ReturnOptions>(
                    &( static_cast<const Derived*>( this )->coeffs( 1, j ) ) );
            }
        }
    };

}  // namespace jmnel::matrix::detail
