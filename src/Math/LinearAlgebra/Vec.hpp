#pragma once

#include <array>
#include <iostream>

#include <Core/Debug/Assert.hpp>
#include <Math/CoreMath.hpp>

using std::array;

namespace jmnel {

    namespace details {
        template <bool>
        struct rule_is_greater_than_4;

        template <>
        struct rule_is_greater_than_4<true> {};

        template <>
        struct rule_is_greater_than_4<false> {};

        template <class T, size_t N, size_t M>
        class inner_storage : rule_is_greater_than_4<( M > 4 )> {
        public:
            T x, y, z, w;

        private:
            T more_data[N - 4];
        };

        template <class T, size_t N>
        class inner_storage<T, 2, N> {
        public:
            T x, y;
        };

        template <class T, size_t N>
        class inner_storage<T, 3, N> {
        public:
            T x, y, z;
        };

        template <class T, size_t N>
        class inner_storage<T, 4, N> {
        public:
            T x, y, z, w;
        };
    };  // namespace details

    /**
     *
     *  @brief <#description#>
     *
     */
    template <class T, size_t N>
    class Vec : public details::inner_storage<T, N, N> {
    public:
        static_assert( N > 1, "Size of 'n-tuple' must be > 1." );
        Vec() noexcept;

        template <class S>
        Vec( S k );
        //	for (size_t i = 0; i < N; i++) {
        //		operator[](i) = k;
        //	}
        //}

        template <class S>
        Vec( S x, S y );

        template <class S>
        Vec( S x, S y, S z );

        template <class S>
        Vec( S x, S y, S z, S w );

        template <class S>
        Vec( Vec<S, N> const &v );

        Vec( array<T, N> a ) {
            for( size_t i = 0; i < N; i++ ) {
                this->operator[]( i ) = T( a[i] );
            }
        }

        template <size_t M>
        Vec( Vec<T, M> const &v, T const &s );

        //        Vec( Vec<T, 2> v, T z );
        //        Vec( Vec<T, 2> v, T z, T w );
        //        Vec( Vec<T, 3> v, T w );

        // const size_t size();
        size_t size() const;
        T &operator[]( const size_t i );
        T const &operator[]( const size_t i ) const;
        Vec<T, N> &operator=( Vec<T, N> const &t );

        Vec<T, N> &operator+=( Vec<T, N> const &rhs );
        Vec<T, N> &operator-=( Vec<T, N> const &rhs );

        Vec<T, N> &operator*=( T rhs );

        //friend std::ostream &operator<<( std::ostream &os, Vec<T, N>
        //        const &t );

        std::string toString() const;

        static const Vec zero() {
            return Vec( 0.0 );
        }

        static const Vec<T, N> left() {
            Vec<T, N> v;
            //            v[0] = -1.0;
            v[0] = -1.0;
            return v;
            // return Vec( -1.0, 0.0 );
        }
        static const Vec<T, N> right() {
            Vec<T, N> v;
            v[0] = 1.0;
            return v;
            // return Vec( 1.0, 0.0 );
        }
        static const Vec<T, N> down() {
            Vec<T, N> v;
            v[1] = -1.0;
            return v;
            // return Vec( 0.0, -1.0 );
        }
        static const Vec<T, N> up() {
            Vec<T, N> v;
            v[1] = 1.0;
            return v;
            // return Vec( 0.0, 1.0 );
        }
        static const Vec<T, N> forward() {
            static_assert( N == 3 );
            Vec<T, N> v;
            v[2] = 1.0;
            return v;
        }
        static const Vec<T, N> back() {
            static_assert( N == 3 );
            Vec<T, N> v;
            v[2] = -1.0;
            return v;
        }
    };

    template <class T, size_t N>
    Vec<T, N> operator+( Vec<T, N> const &t );

    template <class T, size_t N>
    Vec<T, N> operator-( Vec<T, N> const &t );

    template <class T, size_t N>
    Vec<T, N> operator+( Vec<T, N> const &t1, Vec<T, N> const &t2 );

    template <class T, size_t N>
    Vec<T, N> operator-( Vec<T, N> const &t1, Vec<T, N> const &t2 );

    template <class T, size_t N>
    Vec<T, N> operator*( Vec<T, N> const &v1, Vec<T, N> const &v2 );

    template <class S, class T, size_t N>
    Vec<T, N> operator*( S const &s, Vec<T, N> const &t2 );

    template <class S, class T, size_t N>
    Vec<T, N> operator*( Vec<T, N> const &t1, S const &s );

    template <class S, class T, size_t N>
    Vec<T, N> operator/( Vec<T, N> const &t1, S const &s );

    template <class T, size_t N>
    bool operator==( Vec<T, N> const &t1, Vec<T, N> const &t2 );

    template <class T, size_t N>
    bool operator!=( Vec<T, N> const &t1, Vec<T, N> const &t2 );

    template <class T, size_t N>
    inline std::ostream &operator<<( std::ostream &os, Vec<T, N> const &t );

    using Vec2f = Vec<float, 2>;
    using Vec2d = Vec<double, 2>;
    using Vec3f = Vec<float, 3>;
    using Vec3d = Vec<double, 3>;
    using Vec4f = Vec<float, 4>;
    using Vec4d = Vec<double, 4>;
    using Vec2 = Vec<Real, 2>;
    using Vec3 = Vec<Real, 3>;
    using Vec4 = Vec<Real, 4>;

    template <size_t N>
    using Vecf = Vec<float, N>;

    template <size_t N>
    using Vecd = Vec<double, N>;

    /**
     *  @brief Calculate vector dot product.
     *
     *  @details Standard inner dot product of vectors \f$\vec{a}\f$ and
     * \f$\vec{b}\f$.
     *
     *  @param v1 Vector a
     *  @param v2 Vector b
     *  @return Result of 2D dot product
     *
     */
    template <class T, size_t N>
    T dot( Vec<T, N> const &v1, Vec<T, N> const &v2 ) {
        T product = T( 0.0 );
        for( size_t i = 0; i < N; i++ ) {
            product = product + v1[i] * v2[i];
        }
        return product;
    }

    template <class T, size_t N>
    T dot2( Vec<T, N> const &v ) {
        auto product = T( 0.0 );
        for( size_t i = 0; i < N; i++ ) {
            product += v[i] * v[i];
        }
        return product;
    }

    template <class T>
    T cross( Vec<T, 2> const &v1, Vec<T, 2> const &v2 ) {
        return v1.x * v2.y - v1.y * v2.x;
    }

    template <class T>
    Vec<T, 3> cross( Vec<T, 3> const &v1, Vec<T, 3> const &v2 ) {
        Vec<T, 3> result = {
            v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};

        return result;
    }

    /**
     *  @brief Calculate length squared of 2D vector.
     *
     *  @details Simply returns dot product of vector with itself. Uses function
     * [dot](@ref dot).
     *
     *  @param v Vector to calculate length squared of
     *
     *  @return Returns length squared of vector
     *
     */
    template <class T, size_t N>
    T lengthSquared( Vec<T, N> const &v ) {
        T sum = T( 0.0 );
        for( size_t i = 0; i < N; i++ ) {
            sum = sum + v[i] * v[i];
        }
        return sum;
    }

    /**
     *  @brief Calculate length of vector.
     *
     *  @details Gives the square root of [lengthSquared](@ref lengthSquared) to
     * calculate length of vector.
     *
     *  @param v Vector to calculate length of
     *
     *  @return Returns length of vector
     *
     */
    template <class T, size_t N>
    T length( Vec<T, N> const &v ) {
        return std::sqrt( lengthSquared( v ) );
    }

    /**
     *  @brief Calculates normalized unit vector of input vector.
     *
     *  @details Divides vector by length.
     *
     *  @param v Vector to normalize
     *
     *  @return Returns normalized vector
     *
     */
    template <class T, size_t N>
    Vec<T, N> normalize( Vec<T, N> const &v ) {
        T dist = length( v );
        assertf( dist > 0.0 );

        return v / dist;
    }
}  // namespace arc

#include "Vec.inl"
