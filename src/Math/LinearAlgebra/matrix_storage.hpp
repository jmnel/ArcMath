#pragma once

#include <array>

#include "common.hpp"
#include "forward_declare.hpp"
#include "policies.hpp"
#include "span.hpp"

namespace jmnel::detail {

    // -- Matrix storage --
    template <typename Derived, storage_policies StoragePolicy = traits<Derived>::storage_policy()>
    class matrix_storage {};

    // -- Static matrix storage --
    template <typename Derived>
    class matrix_storage<Derived, storage_policies::static_store> {
    public:
        using value_type = typename traits<Derived>::value_type;
        static constexpr auto &size = traits<Derived>::size;
        using data_structure = std::array<value_type, size()>;
        using iterator = typename data_structure::iterator;
        using const_iterator = typename data_structure::const_iterator;

    private:
    public:
        data_structure m_data{};
        matrix_storage() = default;
        matrix_storage( value_type const &x ) { m_data.fill( x ); }

        auto storage_begin() { return m_data.begin(); }
        auto storage_end() { return m_data.end(); }
        auto &storage_at( const size_t i ) {
            assertf( i < m_data.size() );
            return m_data.at( i );
        }
        auto const &storage_at( const size_t i ) const {
            assertf( i < m_data.size() );
            return m_data.at( i );
        }
    };

    // -- Span matrix storage --
    template <typename Derived>
    class matrix_storage<Derived, storage_policies::span_store> {
    public:
        using value_type = typename traits<Derived>::value_type;
        static constexpr auto &size = traits<Derived>::size;
        static constexpr auto stride() { return traits<Derived>::inner_stride; }
        using data_structure = span<value_type, size(), stride()>;
        using iterator = typename data_structure::iterator;
        using const_iterator = typename data_structure::const_iterator;

        data_structure m_data;

    public:
        matrix_storage( value_type const *start_address ) : m_data( start_address ) {}

        auto storage_begin() { return m_data.begin(); }
        auto storage_end() { return m_data.end(); }
        auto &storage_at( const size_t i ) {
            assertf( i < m_data.size() );
            return m_data.at( i );
        }
        auto const &storage_at( const size_t i ) const {
            assertf( i < m_data.size() );
            return m_data.at( i );
        }
    };

}  // namespace jmnel::detail
