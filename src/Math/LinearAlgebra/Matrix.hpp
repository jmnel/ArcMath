#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <type_traits>
#include <utility>

#include "Common.hpp"
#include "MatrixBase.hpp"
#include "MatrixOptions.hpp"

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

        template <typename T>
        void init1(
            T* const x,
            std::enable_if_t<std::is_same<T, Scalar>::value &&
                                 Options::storageType == MatrixStorageType::PointerReference,
                             void>* = 0 ) {
            cout << "init with pointer" << endl;
            this->initStorage( x );
        }

        template <typename T>
        void init1( T const& x, std::enable_if_t<std::is_convertible_v<T, Scalar>, void>* = 0 ) {
            assertf( false );
        }

    public:
        Matrix() noexcept {}

        explicit Matrix( const Scalar x ) noexcept : Base( x ) { cout << "other value." << endl; }

        template <typename T>
        explicit Matrix( const T value ) noexcept {
            init1( value );
        }

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
                for( size_t i = 0; i < rows; ++i ) {
                    for( size_t j = 0; j < cols; ++j ) {
                        this->coeffs( i, j ) = lambda( i * cols + j );
                    }
                }
            }
        }

        // Should not be available for vector types.
        /// @todo Move to algorithm base class.
        void fill( std::function<Scalar( size_t i, size_t j )> const& lambda ) {
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
    };

}  // namespace jmnel::matrix
