#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>

#include <Core/Debug/Assert.hpp>

using std::cout;
using std::endl;

namespace jmnel {

    template <typename T, std::size_t N>
    class HeapArray final {
    private:
        T* m_storage = nullptr;

    public:
        typedef T value_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef value_type& reference;
        typedef value_type const& const_reference;
        typedef value_type* pointer;
        typedef value_type const* const_pointer;
        class iterator;
        class const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        class iterator {
        private:
        public:
            typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T const& const_reference;
            typedef T* pointer;
            typedef T const* const_pointer;
            typedef std::random_access_iterator_tag iterator_category;
            typedef ptrdiff_t difference_type;
            iterator( pointer address ) : address( address ) {}

            self_type operator++() {
                self_type i = *this;
                address++;
                return i;
            }

            self_type operator++( int ) {
                address++;
                return *this;
            }

            self_type operator--() {
                self_type i = *this;
                address--;
                return i;
            }

            self_type operator--( int ) {
                address--;
                return *this;
            }

            self_type operator+( const difference_type difference ) {
                address += difference;
                return *this;
            }

            self_type operator-( const difference_type difference ) {
                address -= difference;
                return *this;
            }

            reference operator*() { return *address; };

            const_reference operator*() const { return *address; }

            pointer operator->() { return address; };

            const_pointer operator->() const { return address; }

            bool operator<( self_type const& rhs ) { return address < rhs.address; }

            bool operator>( self_type const& rhs ) { return address > rhs.address; }

            bool operator<=( self_type const& rhs ) { return address <= rhs.address; }
            bool operator>=( self_type const& rhs ) { return address >= rhs.address; }

            bool operator==( self_type const& rhs ) { return address == rhs.address; }

            bool operator!=( self_type const& rhs ) { return address != rhs.address; }

        private:
            pointer address = nullptr;
        };

        class const_iterator {
        private:
        public:
            typedef iterator self_type;
            typedef T value_type;
            typedef T* pointer;
            typedef T const* const_pointer;
            typedef T const& const_reference;
            typedef std::random_access_iterator_tag iterator_category;
            typedef ptrdiff_t difference_type;
            const_iterator( const_pointer address ) : address( address ) {}

            self_type operator++() {
                self_type i = *this;
                address++;
                return i;
            }

            self_type operator++( int ) {
                address++;
                return *this;
            }

            self_type operator--() {
                self_type i = *this;
                address--;
                return i;
            }

            self_type operator--( int ) {
                address--;
                return *this;
            }

            self_type operator+( const difference_type difference ) {
                address += difference;
                return *this;
            }

            self_type operator-( const difference_type difference ) {
                address -= difference;
                return *this;
            }

            const_reference operator*() const { return *address; }

            const_pointer operator->() const { return address; }

            bool operator<( self_type const& rhs ) { return address < rhs.address; }

            bool operator>( self_type const& rhs ) { return address > rhs.address; }

            bool operator<=( self_type const& rhs ) { return address <= rhs.address; }
            bool operator>=( self_type const& rhs ) { return address >= rhs.address; }

            bool operator==( self_type const& rhs ) { return address == rhs.address; }

            bool operator!=( self_type const& rhs ) { return address != rhs.address; }

        private:
            pointer address;
        };

    public:
        // -- Constructors --
        HeapArray() noexcept { m_storage = new T[N]; }

        void fill( T const& v ) {
            for( auto it = begin(); it != end(); ++it ) {
                *it = v;
            }
        }

        HeapArray( std::initializer_list<T> const& list ) noexcept {
            assertf( list.size() < N );
            m_storage = new T[N];
            auto it = begin();
            for( auto v : list ) {
                *( it++ ) = v;
            }
        }

        HeapArray( HeapArray&& ) = delete;

        HeapArray( HeapArray const& other ) noexcept {
            m_storage = new T[N];
            assertf( other.m_storage );
            assertf( m_storage );
            std::copy( other.m_storage, other.size(), m_storage() );
        }

        ~HeapArray() noexcept {
            assertf( m_storage );
            delete[] m_storage;
            m_storage = nullptr;
            cout << "HeapArray destroy" << endl;
        }

        HeapArray& operator=( HeapArray& other ) noexcept {
            assertf( false );
            assert( other.m_storage );
            assertf( m_storage );
            std::copy( other.m_storage, other.size(), m_storage() );
        }

        HeapArray& operator=( HeapArray&& other ) = delete;

        T const& at( const size_t i ) const noexcept {
            assertf( i >= 0 );
            assertf( i < N );
            return m_storage[i];
        }

        T& at( const size_t i ) noexcept {
            assertf( i >= 0 );
            assertf( i < N );
            return m_storage[i];
        }

        T const& operator[]( const size_t i ) const noexcept {
            assertf( i >= 0 );
            assertf( i < N );
            return m_storage[i];
        }

        T& operator[]( const size_t i ) noexcept {
            assertf( i >= 0 );
            assertf( i < N );
            return m_storage[i];
        }

        T const& front() const noexcept {
            assertf( m_storage );
            return m_storage[0];
        }

        T& front() noexcept {
            assertf( m_storage );
            return m_storage[0];
        }

        T const& back() const noexcept {
            assertf( m_storage );
            return m_storage[N - 1];
        }

        T& back() noexcept {
            assertf( m_storage );
            return m_storage[N - 1];
        }

        const_pointer data() const { return m_storage; }

        pointer data() { return m_storage; }

        // -- Standard iterators --
        iterator begin() { return iterator{&m_storage[0]}; }

        const_iterator cbegin() { return const_iterator{&m_storage[0]}; }

        iterator end() { return iterator{&m_storage[N]}; }

        const_iterator cend() { return const_iterator{&m_storage[N]}; }

        // -- Reverse iterators --
        reverse_iterator rbegin() { return reverse_iterator( iterator{&m_storage[N - 1]} ); }

        const_reverse_iterator crbegin() {
            return const_reverse_iterator( const_iterator{&m_storage[N - 1]} );
        }

        reverse_iterator rend() { return reverse_iterator( iterator{&m_storage[0] - 1} ); }

        const_reverse_iterator crend() {
            return reverse_iterator( const_iterator{&m_storage[0] - 1} );
        }

        bool empty() const { return N == 0; }

        size_t size() const { return N; }

        void swap( HeapArray& other ) { std::swap( m_storage, other.m_storage ); }

    };  // namespace arc

}  // namespace jmnel
