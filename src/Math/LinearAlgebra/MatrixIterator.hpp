#pragma once

#include <iterator>

#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

namespace arc::detail {

    template <typename ScalarT, int RowsT, int ColsT, typename OptionsT>
    class MatrixIterator;

    template <typename ScalarT,
              int RowsT,
              int ColsT,
              typename IndexT,
              typename MemoryTypeT,
              int StrideInnerT,
              int StrideOuterT,
              typename HasNamedMembersT>

    class MatrixIterator<ScalarT,
                         RowsT,
                         ColsT,
                         MatrixOptions<IndexT,
                                       MemoryTypeT,
                                       matrix_storage_dense_tag,
                                       matrix_storage_dense_tag,
                                       matrix_row_major_tag,
                                       StrideInnerT,
                                       StrideOuterT,
                                       HasNamedMembersT>> {

    public:
        typedef MatrixIterator self_type;
        typedef ScalarT value_type;
        typedef value_type& reference;
        typedef value_type const& const_reference;
        typedef value_type* pointer;
        typedef value_type const* const_pointer;
        typedef std::random_access_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;

    private:
        typedef IndexT Index;
        pointer m_address = nullptr;
        static constexpr Index strideInner() { return StrideInnerT; };

    public:
        MatrixIterator( pointer address ) : m_address( address ) {}

        self_type operator++() {
            self_type i = *this;
            m_address += strideInner();
            return i;
        };

        self_type operator++( int ) {
            m_address += strideInner();
            return *this;
        };

        self_type operator--() {
            self_type i = *this;
            m_address -= strideInner();
            return i;
        };

        self_type operator--( int ) {
            m_address -= strideInner();
            return *this;
        };

        self_type operator+( const difference_type difference ) {
            m_address += difference;
            return *this;
        }

        self_type operator-( const difference_type difference ) {
            m_address -= difference;
            return *this;
        }

        reference operator*() { return *m_address; };

        const_reference operator*() const { return *m_address; }

        pointer operator->() { return m_address; };

        const_pointer operator->() const { return m_address; }

        bool operator<( self_type const& rhs ) { return m_address < rhs.address; }

        bool operator>( self_type const& rhs ) { return m_address > rhs.address; }

        bool operator<=( self_type const& rhs ) { return m_address <= rhs.address; }
        bool operator>=( self_type const& rhs ) { return m_address >= rhs.address; }

        bool operator==( self_type const& rhs ) { return m_address == rhs.address; }

        bool operator!=( self_type const& rhs ) { return m_address != rhs.address; }
    };

    template <typename ScalarT, int RowsT, int ColsT, typename OptionsT>
    class ConstMatrixIterator;

    template <typename ScalarT,
              int RowsT,
              int ColsT,
              typename IndexT,
              typename MemoryTypeT,
              int StrideInnerT,
              int StrideOuterT,
              typename HasNamedMembersT>

    class ConstMatrixIterator<ScalarT,
                              RowsT,
                              ColsT,
                              MatrixOptions<IndexT,
                                            MemoryTypeT,
                                            matrix_storage_dense_tag,
                                            matrix_storage_dense_tag,
                                            matrix_row_major_tag,
                                            StrideInnerT,
                                            StrideOuterT,
                                            HasNamedMembersT>> {

    public:
        typedef ConstMatrixIterator self_type;
        typedef ScalarT value_type;
        typedef value_type& reference;
        typedef value_type const& const_reference;
        typedef value_type* pointer;
        typedef value_type const* const_pointer;
        typedef std::random_access_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;

    private:
        typedef IndexT Index;
        pointer m_address = nullptr;
        static constexpr Index strideInner() { return StrideInnerT; };

    public:
        ConstMatrixIterator( pointer address ) : m_address( address ) {}

        self_type operator++() {
            self_type i = *this;
            m_address += strideInner();
            return i;
        };

        self_type operator++( int ) {
            m_address += strideInner();
            return *this;
        };

        self_type operator--() {
            self_type i = *this;
            m_address -= strideInner();
            return i;
        };

        self_type operator--( int ) {
            m_address -= strideInner();
            return *this;
        };

        self_type operator+( const difference_type difference ) {
            m_address += difference;
            return *this;
        }

        self_type operator-( const difference_type difference ) {
            m_address -= difference;
            return *this;
        }

        const_reference operator*() const { return *m_address; }

        const_pointer operator->() const { return m_address; }

        bool operator<( self_type const& rhs ) { return m_address < rhs.address; }

        bool operator>( self_type const& rhs ) { return m_address > rhs.address; }

        bool operator<=( self_type const& rhs ) { return m_address <= rhs.address; }
        bool operator>=( self_type const& rhs ) { return m_address >= rhs.address; }

        bool operator==( self_type const& rhs ) { return m_address == rhs.address; }

        bool operator!=( self_type const& rhs ) { return m_address != rhs.address; }
    };

}  // namespace arc::detail
