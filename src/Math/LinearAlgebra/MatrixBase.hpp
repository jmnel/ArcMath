#pragma once

#include <array>
#include <iostream>
#include <string>

#include <Core/Debug/Assert.hpp>
#include <Math/LinearAlgebra/Constants.hpp>
//#include <Math/LinearAlgebra/MatrixAccessors.hpp>
#include <Math/LinearAlgebra/CoeffRefs.hpp>
#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/MatrixNamedMemberRefs.hpp>
#include <Math/LinearAlgebra/MatrixStorage.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

using std::array;
using std::cout;
using std::endl;
using std::string;

namespace arc::detail {

    template <typename Derived>
    class MatrixBase : public MatrixStorage<Derived>,
                       public MatrixNamedMemberRefs<Derived> {
        //                       public CoeffRefs<Derived> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef typename traits<Derived>::Index Index;

        static constexpr Index Rows = traits<Derived>::Rows;
        static constexpr Index Cols = traits<Derived>::Cols;
        static constexpr Index Size = traits<Derived>::Size;

        //        array<Scalar, Size> m_storage{};

        inline static constexpr void checkTemplateParams() {
            static_assert( Rows > 0, "Matrix rows must be > 0." );
            static_assert( Cols > 0, "Matrix columns must be > 0." );
            static_assert( Size > 1, "Matrix can not be scalar type." );
        }

        static constexpr Index size() {
            return Size;
        }

    public:
        MatrixBase() noexcept {
            checkTemplateParams();
        }

        explicit MatrixBase( std::initializer_list<std::initializer_list<Scalar>> const& list ) {
            cout << "initializer_list constructor called." << endl;
            if( list.size() == 1 ) {
                auto const& inner = *list.begin();
                if( inner.size() == 1 ) {
                    //                    m_storage[0] = 5;
                    //                    m_storage.fill( *inner.begin() );
                } else {
                    massertf( inner.size() == Size, "Matrix initializer_list size wrong." );
                    static_assert( isRowMajor<Derived>::value );
                    //                    std::copy( inner.begin(), inner.end(), m_storage.begin() );
                }
            } else {
                static_assert( isRowMajor<Derived>::value );
                massertf( list.size() == Rows, "Matrix initializer_list size wrong." );
                for( Index i = 0; i < list.size(); ++i ) {
                    auto const& inner = *list.begin();
                    massertf( inner.size() == Cols, "Matrix initializer_list size wrong." );
                    auto itList = inner.begin();
                    for( Index j = 0; j < inner.size(); ++j ) {
                        //                        m_storage[i * Cols + j] = *itList;
                        ++itList;
                    }
                }
            }
        }
    };

    template <typename Derived>
    std::ostream& operator<<( std::ostream& os, MatrixBase<Derived> const& m ) {
        for( size_t i = 0; i < m.Rows; ++i ) {
            os << "( " << m.coeffs( i, 0 );
            for( size_t j = 1; j < m.Cols; ++j ) {
                os << ", " << m.coeffs( i, j );
            }
            os << " )" << endl;
        }
        return os;
    }

}  // namespace arc::detail

//}  // namespace arc::detail
