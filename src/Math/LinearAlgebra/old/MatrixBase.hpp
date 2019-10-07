#include <ostream>
#include <type_traits>
#pragma once

#include "AccessOperators.hpp"
#include "BinaryOperators.hpp"
#include "CoefReffs.hpp"
#include "MapAccessor.hpp"
#include "MatrixIteratorAccess.hpp"
#include "MatrixStorage.hpp"
#include "Printable.hpp"

namespace jmnel::matrix::detail {

    template <typename Derived>
    class MatrixBase : public MatrixStorage<Derived>,
                       public MapAccessor<Derived>,
                       public CoefReffs<Derived>,
                       public Printable<Derived>,
                       public IteratorAccess<Derived>,
                       public AccessOperators<Derived> {
    private:
        using Scalar = typename traits<Derived>::Scalar;
        static constexpr auto size = traits<Derived>::size;
        static constexpr auto rows = traits<Derived>::rows;
        static constexpr auto cols = traits<Derived>::cols;

    public:
        MatrixBase() noexcept : MatrixStorage<Derived>() {}
        MatrixBase( Scalar const& x ) noexcept : MatrixStorage<Derived>( x ) {}
        MatrixBase( Scalar* xPtr ) noexcept : MatrixStorage<Derived>( xPtr ) {}

        MatrixBase( std::initializer_list<std::initializer_list<Scalar>> const& list ) {
            if( list.size() == 1 ) {
                auto const& inner = *list.begin();
                if( inner.size() == 1 ) {
                    static_cast<Derived*>( this )->fill( *inner.begin() );
                } else {
                    assertf( inner.size() == size );
                    auto itElem = this->beginElement();
                    auto it = inner.begin();
                    for( ; itElem != this->endElement(); ++itElem ) {
                        *itElem = *it;
                        it++;
                    }
                }
                //                this->fill( 1 );
            } else {

                if constexpr( traits<Derived>::isVectorType() ) {
                    assertf( list.size() == size );
                    for( size_t i = 0; i < size; ++i ) {
                        this->coeffs( i ) = 0.0;
                    }
                    //                    auto itElem = this->beginElement();
                    //                    auto it = list.begin();
                    //                    for( ; itElem != this->endElement(); ++itElem ) {
                    //                        *itElem = *it;
                    //                        it++;
                    //                    }
                } else {
                    auto itList = list.begin();
                    for( size_t i = 0; i < rows; ++i ) {
                        auto itListInner = itList->begin();
                        for( size_t j = 0; j < cols; ++j ) {
                            this->coeffs( i, j ) = *itListInner;
                            ++itListInner;
                        }
                        ++itList;
                    }
                }
            }
        }
    };

}  // namespace jmnel::matrix::detail
