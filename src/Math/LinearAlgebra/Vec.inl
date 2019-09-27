#include <sstream>
#include <string>

namespace arc {

    template <class T, size_t N>
    Vec<T, N>::Vec() noexcept {
        for( size_t i = 0; i < N; i++ ) {
            operator[]( i ) = T( 0 );
        }
    }

    template <class T, size_t N>
    template <class S>
    Vec<T, N>::Vec( S k ) {
        for( size_t i = 0; i < N; i++ ) {
            operator[]( i ) = (T)k;
        }
    }

    template <class T, size_t N>
    template <class S>
    Vec<T, N>::Vec( S x, S y ) {
        static_assert( N == 2, "This constructor is reserved for 2-tuples." );
        this->x = T( x );
        this->y = T( y );
    }

    template <class T, size_t N>
    template <class S>
    Vec<T, N>::Vec( S x, S y, S z ) {
        static_assert( N == 3, "This constructor is reserved for 3-tuples." );
        this->x = (T)x;
        this->y = (T)y;
        this->z = (T)z;
    }

    template <class T, size_t N>
    template <class S>
    Vec<T, N>::Vec( S x, S y, S z, S w ) {
        static_assert( N == 4, "This constructor is reserved for 4-tuples." );
        this->x = (T)x;
        this->y = (T)y;
        this->z = (T)z;
        this->w = (T)w;
    }

    template <class T, size_t N>
    template <class S>
    Vec<T, N>::Vec( Vec<S, N> const &v ) {
        for( size_t i = 0; i < N; i++ ) {
            this->operator[]( i ) = T( v[i] );
        }
    }
    template <class T, size_t N>
    Vec<T, N> &Vec<T, N>::operator+=( Vec<T, N> const &rhs ) {
        *this = *this + rhs;
        return *this;
    }

    template <class T, size_t N>
    Vec<T, N> &Vec<T, N>::operator-=( Vec<T, N> const &rhs ) {
        *this = *this - rhs;
        return *this;
    }

    template <class T, size_t N>
    Vec<T, N> &Vec<T, N>::operator*=( T rhs ) {
        for( auto i = 0; i < size(); i++ ) {
            operator[]( i ) *= rhs;
        }
        return *this;
    }

    template <class T, size_t N>
    template <size_t M>
    Vec<T, N>::Vec( Vec<T, M> const &v, T const &s ) {
        static_assert( N == M + 1 );
        for( size_t i = 0; i < M; i++ ) {
            operator[]( i ) = v[i];
        }
        operator[]( M ) = s;
    }
    /*
    template <class T, size_t N>
    const size_t Vec<T, N >::size() {
       return N;
    }
    */

    template <class T, size_t N>
    size_t Vec<T, N>::size() const {
        return N;
    }

    template <class T, size_t N>
    T &Vec<T, N>::operator[]( const size_t i ) {
        assert( i < N );
        return ( &( this->x ) )[i];
    }

    template <class T, size_t N>
    T const &Vec<T, N>::operator[]( const size_t i ) const {
        assert( i < N );
        return ( &( this->x ) )[i];
    }

    template <class T, size_t N>
    std::string Vec<T, N>::toString() const {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }

    template <class T, size_t N>
    Vec<T, N> &Vec<T, N>::operator=( Vec<T, N> const &t ) {
        for( size_t i = 0; i < size(); i++ ) {
            this->operator[]( i ) = t[i];
        }
        return *this;
    }

    template <class T, size_t N>
    Vec<T, N> operator+( Vec<T, N> const &t ) {
        return t;
    }

    template <class T, size_t N>
    Vec<T, N> operator-( Vec<T, N> const &t ) {
        return t * T( -1.0 );
    }

    template <class T, size_t N>
    Vec<T, N> operator+( Vec<T, N> const &t1, Vec<T, N> const &t2 ) {
        Vec<T, N> sum;
        for( size_t i = 0; i < N; i++ ) {
            sum[i] = t1[i] + t2[i];
        }
        return sum;
    }

    template <class T, size_t N>
    Vec<T, N> operator-( Vec<T, N> const &t1, Vec<T, N> const &t2 ) {
        Vec<T, N> difference;
        for( size_t i = 0; i < N; i++ ) {
            difference[i] = t1[i] - t2[i];
        }
        return difference;
    }

    // -- Multiplication operator overload : component-wise --
    template <class T, size_t N>
    Vec<T, N> operator*( Vec<T, N> const &v1, Vec<T, N> const &v2 ) {
        Vec<T, N> product( T( 0.0 ) );
        for( size_t i = 0; i < N; i++ ) {
            product[i] = v1[i] * v2[i];
        }
        return product;
    }

    // -- Multiplication operator overload : vector times scalar --
    template <class S, class T, size_t N>
    Vec<T, N> operator*( Vec<T, N> const &t, S const &s ) {
        Vec<T, N> product;
        for( size_t i = 0; i < N; i++ ) {
            product[i] = t[i] * T( s );
        }
        return product;
    }

    // -- Multiplication operator overload : scalar times vector --
    template <class S, class T, size_t N>
    Vec<T, N> operator*( S const &s, Vec<T, N> const &t ) {
        Vec<T, N> product;
        for( size_t i = 0; i < N; i++ ) {
            product[i] = t[i] * s;
        }
        return product;
    }

    // -- Division operator overload : vector divided by scalar --
    template <class S, class T, size_t N>
    Vec<T, N> operator/( Vec<T, N> const &t, S const &s ) {
        assert( s != T( 0.0 ) );
        Vec<T, N> quotient;
        T denom = T( 1.0 ) / s;
        for( size_t i = 0; i < N; i++ ) {
            quotient[i] = t[i] * denom;
        }
        return quotient;
    }

    // -- Equality operator overload --
    template <class T, size_t N>
    bool operator==( Vec<T, N> const &t1, Vec<T, N> const &t2 ) {
        for( size_t i = 0; i < N; i++ ) {
            if( t1[i] != t2[i] ) {
                return false;
            }
        }
        return true;
    }

    // -- Not equals operator overload --
    template <class T, size_t N>
    bool operator!=( Vec<T, N> const &t1, Vec<T, N> const &t2 ) {
        return !( t1 == t2 );
    }

    // -- Stream operator --
    template <class T, size_t N>
    inline std::ostream &operator<<( std::ostream &os, Vec<T, N> const &t ) {
        os << "( ";
        for( size_t i = 0; i < N; i++ ) {
            os << t[i];
            if( i < t.size() - 1 ) {
                os << ", ";
            }
        }
        os << " )";
        return os;
    }

}  // namespace arc
