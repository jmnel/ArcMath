#include <type_traits>
#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "Common.hpp"
#include "Traits.hpp"

using std::endl;

namespace jmnel::matrix::detail {

    template <typename Derived>
    class Printable {
    private:
    public:
        std::string toString() const {
            std::stringstream ss;
            if constexpr( traits<Derived>::dimension == MatrixDimension::One ) {
                static constexpr size_t size = traits<Derived>::size;
                ss << "( " << static_cast<Derived const *>( this )->coeffs( 0 );
                for( size_t i = 1; i < size; ++i ) {
                    ss << ", " << static_cast<Derived const *>( this )->coeffs( i );
                }
                ss << " )";
            } else {
                static constexpr size_t rows = traits<Derived>::rows;
                static constexpr size_t cols = traits<Derived>::cols;
                for( size_t i = 0; i < rows; ++i ) {
                    ss << "( " << static_cast<Derived const *>( this )->coeffs( i, 0 );
                    for( size_t j = 1; j < cols; ++j ) {
                        ss << ", " << static_cast<Derived const *>( this )->coeffs( i, j );
                    }
                    ss << " )";
                    ss << endl;
                }
            }
            return ss.str();
        }
    };

    template <typename Derived>
    std::ostream &operator<<( std::ostream &os, Printable<Derived> const &printable ) {
        os << printable.toString();
        return os;
    }

}  // namespace jmnel::matrix::detail
