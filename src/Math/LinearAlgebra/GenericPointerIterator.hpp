#pragma once

#include <cstddef>
#include <iterator>
#include <type_traits>

namespace jmnel::generics {

    template <typename T>
    struct identity_rule {
        using type = T;
    };

    template <typename T,
              size_t strideT = 1,
              template <typename> class DerefTypeRuleT = identity_rule>
    class GenericPointerIterator {
    public:
        using self_type = GenericPointerIterator;
        using value_type = typename DerefTypeRuleT<T>::type;
        using reference = value_type&;
        using const_reference = value_type const&;

        using pointer = T*;
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = ptrdiff_t;

        static constexpr size_t stride = strideT;

        GenericPointerIterator( pointer address ) : m_address( address ) {}

        self_type operator++() {
            self_type i = *this;
            m_address += stride;
            return i;
        }

        self_type operator++( int ) {
            m_address += stride;
            return *this;
        }

        self_type operator--() {
            self_type i = *this;
            m_address -= stride;
            return i;
        }

        self_type operator--( int ) {
            m_address -= stride;
            return *this;
        }

        self_type operator+( const difference_type difference ) {
            m_address += difference * stride;
            return *this;
        }

        self_type operator-( const difference_type difference ) {
            m_address -= difference * stride;
            return *this;
        }

        reference operator*() { return *m_address; };
        const_reference operator*() const { return *m_address; }
        bool operator<( self_type const& rhs ) { return m_address < rhs.address; }
        bool operator>( self_type const& rhs ) { return m_address > rhs.address; }
        bool operator<=( self_type const& rhs ) { return m_address <= rhs.address; }
        bool operator>=( self_type const& rhs ) { return m_address >= rhs.address; }
        bool operator==( self_type const& rhs ) { return m_address == rhs.address; }
        bool operator!=( self_type const& rhs ) { return m_address != rhs.address; }

    private:
        pointer m_address;
    };

    template <typename T,
              size_t strideT = 1,
              template <typename> class DerefTypeRuleT = identity_rule>
    class ConstGenericPointerIterator {
    public:
        using self_type = ConstGenericPointerIterator;
        using value_type = typename DerefTypeRuleT<T>::type;
        using reference = value_type&;
        using const_reference = value_type const&;
        using pointer = T*;
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = ptrdiff_t;

        static constexpr size_t stride = strideT;

        ConstGenericPointerIterator( pointer address ) : m_address( address ) {}

        self_type operator++() {
            self_type i = *this;
            m_address += stride;
            return i;
        }

        self_type operator++( int ) {
            m_address += stride;
            return *this;
        }

        self_type operator--() {
            self_type i = *this;
            m_address -= stride;
            return i;
        }

        self_type operator--( int ) {
            m_address -= stride;
            return *this;
        }

        self_type operator+( const difference_type difference ) {
            m_address += difference * stride;
            return *this;
        }

        self_type operator-( const difference_type difference ) {
            m_address -= difference * stride;
            return *this;
        }

        reference operator*() { return *m_address; };
        const_reference operator*() const { return *m_address; }
        bool operator<( self_type const& rhs ) { return m_address < rhs.address; }
        bool operator>( self_type const& rhs ) { return m_address > rhs.address; }
        bool operator<=( self_type const& rhs ) { return m_address <= rhs.address; }
        bool operator>=( self_type const& rhs ) { return m_address >= rhs.address; }
        bool operator==( self_type const& rhs ) { return m_address == rhs.address; }
        bool operator!=( self_type const& rhs ) { return m_address != rhs.address; }

    private:
        pointer m_address;
    };

}  // namespace jmnel::generics
