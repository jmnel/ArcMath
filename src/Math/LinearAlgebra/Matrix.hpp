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

    template <typename IndexT,
              typename MemoryTypeT,
              typename DensityInnerT,
              typename DensityOuterT,
              typename StorageOrderT,
              int StrideInnerT,
              int StrideOuterT,
              typename HasNamedMembersT>
    struct MatrixOptions {
        typedef IndexT Index;
        typedef DensityInnerT DensityInner;
        typedef DensityOuterT DensityOuter;
        typedef StorageOrderT StorageOrder;
        static constexpr Index StrideInner = StrideInnerT;
        static constexpr Index StrideOuter = StrideOuterT;
        typedef HasNamedMembersT HasNamedMembers;
    };

    namespace detail {

        template <typename ScalarT,
                  int RowsT,
                  int ColsT,
                  typename OptionsT>
        struct traits<Matrix<ScalarT,
                             RowsT,
                             ColsT,
                             OptionsT>> {

        public:
            typedef ScalarT Scalar;
            typedef Matrix<ScalarT, RowsT, ColsT, OptionsT> Derived;
            typedef OptionsT Options;
            typedef typename OptionsT::Index Index;
            static constexpr Index Rows = RowsT;
            static constexpr Index Cols = ColsT;
            static constexpr Index Size = Rows * Cols;
        };

        //        template <typename

        template <typename T>
        static constexpr void staticAssertVectorSize( const int size ) {
            static_assert( matrix_is_vector_type<T>::value, "Matrix is not vector." );
            static_assert( size < traits<T>::Size, "Vector type size assert failed." );
        }

    }  // namespace detail

    template <typename ScalarT,
              int RowsT,
              int ColsT,
              typename OptionsT>
    class Matrix : public detail::MatrixBase<Matrix<ScalarT,
                                                    RowsT,
                                                    ColsT,
                                                    OptionsT>> {
    public:
        typedef ScalarT Scalar;
        typedef detail::MatrixBase<Matrix> Base;
        typedef OptionsT Options;
        typedef typename OptionsT::Index Index;

    private:
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
