#pragma once

#include <ostream>
#include <sstream>
#include <type_traits>

#include <Math/LinearAlgebra/Traits.hpp>

using std::endl;
using std::string;

namespace arc::detail {

    //    class <typename Derived, typename Matrix

    template <typename Derived, typename MatrixTypeT = typename get_matrix_type<Derived>::type>
    class MatrixPrinter {
    private:
        using Index = typename traits<Derived>::Index;

    public:
        string toString() const {
            Derived const& m = static_cast<Derived const&>( *this );
            if constexpr( traits<Derived>::isVectorType() ) {
                std::stringstream ss;
                ss << "( " << m.coeffs( 0 );
                for( Index i = 1; i < m.size(); ++i ) {
                    ss << ", " << m.coeffs( i );
                }
                ss << " )";
                return ss.str();
            } else {
                std::stringstream ss;
                for( Index i = 0; i < m.rows(); i++ ) {
                    ss << "( " << m.coeffs( i, 0 );
                    for( Index j = 1; j < m.cols(); j++ ) {
                        ss << ", " << m.coeffs( i, j );
                    }
                    ss << " )" << endl;
                }
                return ss.str();
            }
        }
    };

    template <typename Derived>
    std::ostream& operator<<( std::ostream& os, MatrixPrinter<Derived> const& m ) {
        os << m.toString();
        return os;
    }

}  // namespace arc::detail
