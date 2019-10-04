#pragma once

#include <array>
#include <iostream>
#include <string>

#include <Core/Debug/Assert.hpp>
#include <Math/LinearAlgebra/Constants.hpp>
//#include <Math/LinearAlgebra/MatrixAccessors.hpp>
#include <Math/LinearAlgebra/CoeffRefs.hpp>
#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/MatrixMapAccessors.hpp>
#include <Math/LinearAlgebra/MatrixNamedMemberRefs.hpp>
#include <Math/LinearAlgebra/MatrixPrinter.hpp>
#include <Math/LinearAlgebra/MatrixStorage.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

using std::array;
using std::cout;
using std::endl;
using std::string;

namespace arc::detail {

    template <typename Derived>
    class MatrixBase : public MatrixStorage<Derived>,
                       public MatrixNamedMemberRefs<Derived>,
                       public MatrixMapAccessors<Derived>,
                       public CoeffRefs<Derived>,
                       public MatrixPrinter<Derived> {

    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef typename traits<Derived>::Index Index;
        //        typedef MatrixStorage<Derived> Storage;

        static constexpr Index rows() { return traits<Derived>::rows(); };
        static constexpr Index cols() { return traits<Derived>::cols(); };
        static constexpr Index size() { return traits<Derived>::size(); };

        inline static constexpr void checkTemplateParams() {
            static_assert( rows() > 0, "Matrix rows must be > 0." );
            static_assert( cols() > 0, "Matrix columns must be > 0." );
            static_assert( size() > 1, "Matrix can not be scalar type." );
        }

    public:
        MatrixBase() noexcept { checkTemplateParams(); }

        [[deprecated]] explicit MatrixBase(
            std::initializer_list<std::initializer_list<Scalar>> const& list ) {
            cout << "initializer_list constructor called." << endl;
            if( list.size() == 1 ) {
                auto const& inner = *list.begin();
                if( inner.size() == 1 ) {
                    this->m_storage.fill( *inner.begin() );
                } else {
                    massertf( inner.size() == size(), "Matrix initializer_list size wrong." );
                    static_assert( traits<Derived>::isRowMajor() );
                }
            } else {
                static_assert( traits<Derived>::isRowMajor() );
                massertf( list.size() == rows(), "Matrix initializer_list size wrong." );
                for( Index i = 0; i < list.size(); ++i ) {
                    auto const& inner = *list.begin();
                    massertf( inner.size() == cols(), "Matrix initializer_list size wrong." );
                    auto itList = inner.begin();
                    for( Index j = 0; j < inner.size(); ++j ) {
                        this->m_storage[i * cols() + j] = *itList;
                        ++itList;
                    }
                }
            }
        }
    };

    //    template <typename Derived>
    //    std::ostream& operator<<( std::ostream& os, MatrixBase<Derived> const& m ) {
    //        for( size_t i = 0; i < m.Rows; ++i ) {
    //            os << "( " << m.coeffs( i, 0 );
    //            for( size_t j = 1; j < m.Cols; ++j ) {
    //                os << ", " << m.coeffs( i, j );
    //            }
    //            os << " )" << endl;
    //        }
    //        return os;
    //    }

}  // namespace arc::detail

//}  // namespace arc::detail
