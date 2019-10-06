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
        static constexpr size_t baseSize = traits<Derived>::size;
        static constexpr size_t baseInnerStride = traits<Derived>::innerStride;
        static constexpr size_t baseOuterStride = traits<Derived>::outerStride;
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
        static constexpr size_t baseRows = traits<Derived>::rows;
        static constexpr size_t baseCols = traits<Derived>::cols;
        static constexpr size_t baseSize = traits<Derived>::size;
        static constexpr size_t baseInnerStride = traits<Derived>::innerStride;
        static constexpr size_t baseOuterStride = traits<Derived>::outerStride;
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
                    &( static_cast<Derived*>( this )->coeffs( i, 1 ) ) );
            }
        }

        auto col( const size_t j ) {
            assertf( j <= baseCols );

            if constexpr( baseStorageOrder == MatrixStorageOrder::RowMajor ) {
                using ReturnOptions = MatrixOptions<MatrixStorageType::PointerReference,
                                                    MatrixStorageOrder::RowMajor,
                                                    MatrixDensity::Dense,
                                                    MatrixDensity::Dense,
                                                    baseOuterStride * baseRows,
                                                    baseInnerStride,  // Doesn't matter
                                                    baseHasNamedMembers>;
                return Matrix<Scalar, 1, baseCols, ReturnOptions>(
                    &( static_cast<Derived*>( this )->coeffs( 1, j ) ) );
            }
        }
    };

}  // namespace jmnel::matrix::detail
