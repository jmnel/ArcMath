#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <type_traits>
#include <utility>

//#include "BinaryOperators.hpp"
//#include "Common.hpp"
//#include "MatrixBase.hpp"
//#include "MatrixOptions.hpp"

using std::cout;
using std::enable_if;
using std::endl;
using std::is_same;

namespace jmnel::matrix {

    template <typename ScalarT, size_t rowsT, size_t colsT, typename OptionsT>
    class Matrix : public detail::MatrixBase<Matrix<ScalarT, rowsT, colsT, OptionsT>> {
    private:
        using Scalar = ScalarT;
        using SelfType = Matrix<ScalarT, rowsT, colsT, OptionsT>;
        using Base = detail::MatrixBase<SelfType>;
        using Options = OptionsT;
        static constexpr auto rows = rowsT;
        static constexpr auto cols = colsT;
        static constexpr auto size = rowsT * colsT;
        static constexpr auto dimension = detail::traits<SelfType>::dimension;
        static constexpr bool isVectorType = detail::traits<SelfType>::isVectorType;

        template <typename T>
        void init1( T const& x,
                    typename std::enable_if_t<std::is_convertible_v<T, Scalar>>* = 0 ) noexcept {
            fill( x );
        }

        template <typename T>
        void init1(
            T const x,
            typename std::enable_if_t<std::is_same_v<T, array<Scalar, size>>>* = 0 ) noexcept {
            //            auto it = x.begin();
            //            for( itElem = this->beginElement();
            //            assertf( false );
            std::copy( x.begin(), x.end(), this->beginElement() );
        }

        template <typename T>
        void init1(
            T const x,
            typename std::enable_if_t<std::is_same_v<T, array<array<Scalar, cols>, rows>>>* =
                0 ) noexcept {
            //            static_assert( !isVectorType );
            if constexpr( detail::traits<SelfType>::isVectorType() ) {
                for( size_t k = 0; k < size; ++k ) {
                    auto i = ( k / cols );
                    auto j = ( k % cols );
                    this->coeffs( k ) = x[i][j];
                }
            } else {

                for( size_t i = 0; i < rows; ++i ) {
                    for( size_t j = 0; j < cols; ++j ) {
                        this->coeffs( i, j ) = x[i][j];
                    }
                }
            }
        }

        template <typename T>
        void init1(
            T* const x,
            std::enable_if_t<std::is_same<T, Scalar>::value &&
                                 Options::storageType == MatrixStorageType::PointerReference,
                             void>* = 0 ) {
            this->initStorage( x );
        }

        template <typename T>
        void init1(
            const T* const x,
            std::enable_if_t<std::is_same<T, Scalar>::value &&
                                 Options::storageType == MatrixStorageType::PointerReference,
                             void>* = 0 ) {
            this->initStorage( x );
        }

        //        template <typename T>
        //        void init1( T const& x, std::enable_if_t<std::is_convertible_v<T, Scalar>,
        //        void>* = 0 ) {
        //            assertf( false );
        //        }

    public:
        // -- Constructors --
        Matrix() noexcept {}

        //        explicit Matrix( const Scalar x ) noexcept : Base( x ) {}

        explicit Matrix( Matrix const& x ) noexcept {}

        template <typename T>
        explicit Matrix( T const& x ) noexcept {
            init1( x );
        }

        // With Rvalue references
        static_assert( std::is_nothrow_move_assignable<Scalar>::value );
        Matrix( Matrix&& other ) noexcept : Base( std::move( other ) ) {}

        Matrix& operator=( Matrix&& other ) noexcept {
            Base( std::move( other ) );
            //            other.swap( *this );
            return *this;
        }

        // -- Variadic constructor --
        template <typename... ArgTypes>
        Matrix( const Scalar a0,
                const Scalar a1,
                const Scalar a2,
                const Scalar a3,
                const ArgTypes... args )
            : Base( a0, a1, a2, a3, args... ) {}

        // -- Initializer list constructor --
        Matrix( std::initializer_list<std::initializer_list<Scalar>> const& list ) : Base( list ) {}

        void fill( const Scalar x ) {
            if constexpr( dimension == MatrixDimension::One ) {
                for( size_t i = 0; i < size; ++i ) {
                    this->coeffs( i ) = x;
                }
            } else {
                for( size_t i = 0; i < rows; ++i ) {
                    for( size_t j = 0; j < cols; ++j ) {
                        this->coeffs( i, j ) = x;
                    }
                }
            }
        }

        void fill( std::function<Scalar( size_t i )> const& lambda ) {
            if constexpr( dimension == MatrixDimension::One ) {
                for( size_t i = 0; i < size; ++i ) {
                    this->coeffs( i ) = lambda( i );
                }
            } else {
                for( size_t k = 0; k < size; ++k ) {
                    const auto i = k / cols;
                    const auto j = k % cols;
                    this->coeffs( i, j ) = lambda( k );
                }
            }
        }

        // Should not be available for vector types.
        /// @todo Move to algorithm base class.
        enable_if<detail::traits<Matrix>::isVectorType()> fill(
            std::function<Scalar( size_t i, size_t j )> const& lambda ) {
            if constexpr( dimension == MatrixDimension::One ) {
                assertf( false );
            } else {
                for( size_t i = 0; i < rows; ++i ) {
                    for( size_t j = 0; j < cols; ++j ) {
                        this->coeffs( i, j ) = lambda( i, j );
                    }
                }
            }
        }

        static constexpr Matrix identiy() {
            array<array<Scalar, rows>, cols> values{};
            for( size_t i = 0; i < std::min( rows, cols ); ++i ) {
                values[i][i] = 1.0;
            }
            return Matrix( values );
        }

        static constexpr Matrix zero() { return Matrix{}; }

        static constexpr size_t width() { return cols; }
        static constexpr size_t height() { return rows; }
    };

}  // namespace jmnel::matrix
