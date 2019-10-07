#pragma once

#include <functional>
#include <type_traits>

#include <Core/Debug/Assert.hpp>

#include "common.hpp"
#include "forward_declare.hpp"
#include "policies.hpp"

using std::cout;
using std::endl;

namespace jmnel::detail {

    template <typename Derived>
    class matrix_accessors {
    private:
        static constexpr auto is_vector_type() { return traits<Derived>::is_vector_type(); }
        //    template <typename Derived>
        //    class matrix_accessors<Derived, true> {
    public:
        using value_type = typename traits<Derived>::value_type;
        using reference = value_type &;
        using const_reference = value_type const &;

        static constexpr auto rows() { return traits<Derived>::rows(); }
        static constexpr auto cols() { return traits<Derived>::cols(); }
        static constexpr auto size() { return traits<Derived>::size(); }

        using row_type = matrix<value_type,
                                cols(),
                                1,
                                policies<storage_policies::static_store,
                                         order_policies::row_major,
                                         density_policies::dense,
                                         density_policies::dense,
                                         1,
                                         1>>;

        using col_type = matrix<value_type,
                                rows(),
                                1,
                                policies<storage_policies::static_store,
                                         order_policies::row_major,
                                         density_policies::dense,
                                         density_policies::dense,
                                         1,
                                         1>>;

        value_type &at( const size_t i, const size_t j = 0 ) {
            if constexpr( is_vector_type() ) {
                assertf( i < size() );
                return static_cast<Derived *>( this )->storage_at( i );
            } else {
                assertf( i < rows() );
                assertf( j < cols() );
                return static_cast<Derived *>( this )->storage_at( i * cols() + j );
            }
        }

        value_type const &at( const size_t i, const size_t j = 0 ) const {
            if constexpr( is_vector_type() ) {
                assertf( i < size() );
                return static_cast<Derived const *>( this )->storage_at( i );
            } else {
                assertf( i < rows() );
                assertf( j < cols() );
                return static_cast<Derived const *>( this )->storage_at( i * cols() + j );
            }
        }

        value_type &operator()( const size_t i, const size_t j = 0 ) {
            if constexpr( is_vector_type() ) {
                assertf( i < size() );
                return static_cast<Derived *>( this )->storage_at( i );
            } else {
                assertf( i < rows() );
                assertf( j < cols() );
                return static_cast<Derived *>( this )->storage_at( i * cols() + j );
            }
        }

        value_type const &operator()( const size_t i, const size_t j = 0 ) const {
            if constexpr( is_vector_type() ) {
                assertf( i < size() );
                return static_cast<Derived const *>( this )->storage_at( i );
            } else {
                assertf( i < rows() );
                assertf( j < cols() );
                return static_cast<Derived const *>( this )->storage_at( i * cols() + j );
            }
        }

        row_type row( size_t i ) const {
            static_assert( !is_vector_type() );
            assertf( i < rows() );
            row_type new_row{};
            for( size_t j = 0; j < cols(); ++j ) {
                new_row( j ) = this->at( i, j );
            }
            return new_row;
        }

        col_type col( size_t j ) const {
            static_assert( !is_vector_type() );
            assertf( j < cols() );
            col_type new_col{};
            for( size_t i = 0; i < rows(); ++i ) {
                new_col( i ) = this->at( i, j );
            }
            return new_col;
        }
    };

};  // namespace jmnel::detail
