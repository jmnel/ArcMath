#pragma once

#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/MatrixBinaryOperators.hpp>
#include <Math/LinearAlgebra/MatrixMapBase.hpp>

namespace arc {

    namespace detail {

        // -- Define Matrix Map type traits --
        template <typename ScalarT, int RowsT, int ColsT, typename OptionsT>
        struct traits<MatrixMap<ScalarT, RowsT, ColsT, OptionsT>> {
            typedef ScalarT Scalar;
            typedef Matrix<ScalarT, RowsT, ColsT, OptionsT> Derived;
            typedef OptionsT Options;
            typedef typename OptionsT::Index Index;

            static constexpr Index rows() { return RowsT; }
            static constexpr Index cols() { return ColsT; }
            static constexpr Index size() { return RowsT * ColsT; }

            static constexpr Index strideInner() { return Options::strideInner(); }

            static constexpr Index strideOuter() { return Options::strideOuter(); }

            static constexpr bool isVectorType() {
                return ( rows() == 1 && cols() != 1 ) || ( rows() != 1 && cols() == 1 );
            }

            static constexpr bool isNamedMamberRefsEnabled() {
                return std::is_same_v<typename Options::HasNamedMembers,
                                      matrix_has_named_members_tag>;
            }

            static constexpr bool isRowMajor() {
                return std::is_same_v<typename Options::StorageOrder, matrix_row_major_tag>;
            }
        };
    }  // namespace detail

    template <typename ScalarT, int RowsT, int ColsT, typename OptionsT>
    class MatrixMap : public detail::MatrixMapBase<MatrixMap<ScalarT, RowsT, ColsT, OptionsT>> {
    public:
        typedef MatrixMap<ScalarT, RowsT, ColsT, OptionsT> Derived;
        typedef ScalarT Scalar;
        typedef detail::MatrixMapBase<Derived> Base;
        typedef OptionsT Options;
        typedef typename Options::Index Index;

    private:
        //        template <typename T>
        //        void init1( Scalar* ptr, typename std::enable_if < std::is_same <);

    public:
        explicit MatrixMap( Scalar* startPointer ) : Base( startPointer ) {
            assertf( startPointer );
        }

        static constexpr Index size() { return rows() * cols(); }

        static constexpr Index rows() { return RowsT; }
        static constexpr Index cols() { return ColsT; }

        static constexpr Index strideInner() { return Options::strideInner(); }

        static constexpr Index strideOuter() { return Options::strideOuter(); }
    };

}  // namespace arc
