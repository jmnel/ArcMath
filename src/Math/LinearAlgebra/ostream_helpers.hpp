#pragma once

#include <array>
#include <cstddef>
#include <ostream>
#include <type_traits>
#include <vector>

#include "matrix_accessors.hpp"
#include "span.hpp"

namespace jmnel {

    // -- ostream output stream iterator for std::array --
    template <typename T, size_t N>
    std::ostream &operator<<( std::ostream &os, std::array<T, N> const &a ) {
        os << "{ " << a.front();
        for( auto it = a.cbegin() + 1; it != a.cend(); ++it ) {
            os << ", " << *it;
        }
        os << " }";
        return os;
    }

    // -- ostream output stream iterator for std::vector --
    template <typename T, size_t N>
    std::ostream &operator<<( std::ostream &os, std::vector<T> const &v ) {
        os << "{ " << v.front();
        for( auto it = v.cbegin() + 1; it != v.cend(); ++it ) {
            os << ", " << *it;
        }
        os << " }";
        return os;
    }

    // -- ostream output stream iterator for jmnel::span --
    template <typename T, size_t N, ptrdiff_t Stride>
    std::ostream &operator<<( std::ostream &os, span<T, N, Stride> const &s ) {
        os << "{ " << s.front();
        for( auto it = s.cbegin() + 1; it != s.cend(); ++it ) {
            os << ", " << *it;
        }
        os << " }";
        return os;
    }

    namespace detail {
        template <typename Derived>
        std::ostream &operator<<( std::ostream &os, matrix_accessors<Derived> const &m ) {
            if constexpr( traits<Derived>::is_vector_type() ) {
                os << "{ " << m.at( 0 );
                for( size_t k = 1; k < m.size(); ++k ) {
                    os << ", " << m.at( k );
                }
                os << " }";
            } else {

                for( size_t i = 0; i < m.rows(); ++i ) {
                    os << "{ " << m.at( i, 0 );
                    for( size_t j = 1; j < m.cols(); ++j ) {
                        os << ", " << m.at( i, j );
                    }
                    os << " }" << std::endl;
                }
            }
            return os;
        }  // namespace detail
    }      // namespace detail

}  // namespace jmnel
