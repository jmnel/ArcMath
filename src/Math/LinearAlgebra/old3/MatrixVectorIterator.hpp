#pragma once

#include <iterator>

#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

namespace arc::matrix {

    class Iterators {
    private:
        using dense_tag = detail::matrix_storage_dense_tag;
        using row_major_tag = detail::matrix_row_major_tag;
        using pointer_ref_tag = detail::matrix_storage_pointer_ref_tag;

        template <typename Derived>
        using traits = detail::traits<Derived>;

    public:
        //    template <typename ScalarT, int RowsT, int ColsT, typename OptionsT>

        template <typename Derived,
                  typename InnerDensityT = typename traits<Derived>::InnerDensity,
                  typename OuterDensityT = typename traits<Derived>::OuterDensity,
                  typename StorageOrderT = typename traits<Derived>::StorageOrder>
        class MatrixVectorIterator;

        template <typename Derived>
        class MatrixVectorIterator<Derived, dense_tag, dense_tag, row_major_tag> {

        private:
            using Index = typename traits<Derived>::Index;
            using Scalar = typename traits<Derived>::Scalar;

            // Helper utlitiy.
            template <Index N, Index MinT, Index MaxT, typename TypeT = Index>
            struct in_range {
                static_assert( N >= MinT && N <= MaxT, "in_range assert failed." );
                static constexpr std::enable_if_t<N >= MinT && N <= MaxT, TypeT> value = N;
            };

            static constexpr Index rows() { return traits<Derived>::rows(); };
            static constexpr Index cols() { return traits<Derived>::cols(); };
            static constexpr Index strideOuter() {
                return traits<Derived>::Options::strideOuter();
            };
            static constexpr Index strideInner() {
                return traits<Derived>::Options::strideInner();
            };

            // Row type for matrix map.
            template <Index subRowLengthT>
            using RowType =
                MatrixMap<Scalar,
                          1,
                          in_range<subRowLengthT, 0, cols()>::value,
                          MatrixOptions<Index,
                                        pointer_ref_tag,
                                        dense_tag,
                                        dense_tag,
                                        row_major_tag,
                                        1,
                                        strideOuter() * cols(),
                                        typename traits<Derived>::Options::HasNamedMembers>>;

            // Column type for matrix map.
            template <Index subColLengthT>
            using ColumnType =
                MatrixMap<Scalar,
                          in_range<subColLengthT, 0, rows()>::value,
                          1,
                          MatrixOptions<Index,
                                        pointer_ref_tag,
                                        dense_tag,
                                        dense_tag,
                                        row_major_tag,
                                        strideOuter() * cols(),
                                        1,
                                        typename traits<Derived>::Options::HasNamedMembers>>;

        public:
            using value_type = Scalar;
            typedef MatrixVectorIterator self_type;
            typedef value_type& reference;
            typedef value_type const& const_reference;
            typedef value_type* pointer;
            typedef value_type const* const_pointer;
            typedef std::random_access_iterator_tag iterator_category;
            typedef ptrdiff_t difference_type;

        private:
            pointer m_address = nullptr;

        public:
            MatrixVectorIterator( pointer address ) : m_address( address ) {}

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
        class ConstMatrixVectorIterator;

        template <typename ScalarT,
                  int RowsT,
                  int ColsT,
                  typename IndexT,
                  typename MemoryTypeT,
                  int StrideInnerT,
                  int StrideOuterT,
                  typename HasNamedMembersT>

        class ConstMatrixVectorIterator<ScalarT,
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
            typedef ConstMatrixVectorIterator self_type;
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
            ConstMatrixVectorIterator( pointer address ) : m_address( address ) {}

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
    };

}  // namespace arc::matrix
