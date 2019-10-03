#pragma once

#include <array>
#include <iostream>

#include <Math/LinearAlgebra/Constants.hpp>
#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/MatrixBase.hpp>

using std::array;
using std::cout;
using std::endl;

namespace arc {

    namespace detail {

        template <typename T>
        struct hasNamedMemberRefs {
            static constexpr bool value = false;
        };

        // Enables coefficient reference access to row major vector types.
        template <typename ScalarT, int OptionsT, typename IndexT>
        struct hasNamedMemberRefs<Matrix<ScalarT, 1, 1, OptionsT, IndexT>> {
            static constexpr bool value = false;
        };

        template <typename ScalarT, int ColsT, int OptionsT, typename IndexT>
        struct hasNamedMemberRefs<Matrix<ScalarT, 1, ColsT, OptionsT, IndexT>> {
            static constexpr bool value = OptionsT & NamedMemberRefsEnabled;
        };

        // Enables coefficient reference access to column major vector types.
        template <typename ScalarT, int RowsT, int OptionsT, typename IndexT>
        struct hasNamedMemberRefs<Matrix<ScalarT, RowsT, 1, OptionsT, IndexT>> {
            static constexpr bool value = OptionsT & NamedMemberRefsEnabled;
        };

        template <typename ScalarT, int RowsT, int ColsT, int OptionsT, typename IndexT>
        struct traits<Matrix<ScalarT, RowsT, ColsT, OptionsT, IndexT>> {
            static_assert( RowsT > 0, "Matrix rows must be > 0." );
            static_assert( ColsT > 0, "Matrix columns must be > 0." );

        private:
            static constexpr int rowMajorBit = OptionsT & RowMajor ? RowMajorBit : 0;
            static constexpr int accessorsBit = OptionsT & AccessorsEnabled ? AccessorsBit : 0;

        public:
            typedef ScalarT Scalar;
            typedef Matrix<ScalarT, RowsT, ColsT, OptionsT, IndexT> Derived;
            typedef IndexT Index;
            static constexpr IndexT Rows = RowsT;
            static constexpr IndexT Cols = ColsT;
            static constexpr IndexT Size = isVectorType<Derived>::value ? isRowMajor<Derived>::value ? Cols : Rows
                                                                        : Rows * Cols;
            static constexpr int Options = OptionsT;
            static constexpr bool accessorsEnabled = accessorsBit != 0;
            static constexpr bool namedMemberRefsEnabled = hasNamedMemberRefs<Derived>::value;
        };

        template <typename ScalarT, int RowsT, int ColsT, int OptionsT, typename IndexT>
        static constexpr void staticAssertVectorSize( const int size ) {
            static_assert( isVectorType<Matrix<ScalarT, RowsT, ColsT, OptionsT>>::value,
                           "Matrix is not vector type." );
            static_assert( size < RowsT * ColsT, "Vector type size assert failed." );
        }

    }  // namespace detail

    template <typename ScalarT, int RowsT, int ColsT, int OptionsT, typename IndexT>
    class Matrix : public detail::MatrixBase<Matrix<ScalarT, RowsT, ColsT, OptionsT, IndexT>> {
    public:
        typedef ScalarT Scalar;
        typedef detail::MatrixBase<Matrix> Base;
        typedef IndexT Index;

    private:
        static constexpr int Options = OptionsT;

        template <typename T>
        void init1( T const &x,
                    typename std::enable_if<
                        std::is_convertible<T, Scalar>::value,
                        void>::type * = 0 ) noexcept {
            this->m_storage.fill( x );
        }

        template <typename T>
        void init1( T const &x,
                    typename std::enable_if<
                        std::is_same<T, array<Scalar, detail::traits<Matrix>::Size>>::value,
                        void>::type * = 0 ) noexcept {
            std::copy( x.begin(), x.end(), this->m_storage.begin() );
        }

    public:
        // -- Default constructor --
        Matrix() noexcept
            : Base() {
        }

        template <typename T>
        explicit Matrix( T const &x ) noexcept {
            init1( x );
        };

        // -- Rvalue references --
        static_assert( std::is_nothrow_move_assignable<Scalar>::value );
        Matrix( Matrix &&other ) noexcept
            : Base( std::move( other ) ) {
        }

        Matrix &operator=( Matrix &&other ) noexcept {
            other.swap( *this );
            return *this;
        }

        // -- Variadic constructor --
        template <typename... ArgTypes>
        Matrix( const Scalar a0,
                const Scalar a1,
                const Scalar a2,
                const Scalar a3,
                const ArgTypes... args )
            : Base( a0, a1, a2, a3, args... ) {
        }

        // -- Initializer list constructor --
        explicit Matrix( std::initializer_list<std::initializer_list<Scalar>> const &list )
            : Base( list ) {
        }
    };

}  // namespace arc
