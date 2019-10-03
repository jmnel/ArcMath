#pragma once

#include <Core/Debug/Assert.hpp>

#include <Math/LinearAlgebra/Traits.hpp>

namespace arc::detail {

    enum class MatrixDimension { One,
                                 Two };

    template <typename Derived, bool hasAccessors, MatrixDimension dimensions>
    class MatrixAccessors {
    };

    template <typename Derived>
    class MatrixAccessors<Derived, true, MatrixDimension::One> {
    public:
        typedef typename MatrixTraits<Derived>::ScalarType ScalarType;
        static constexpr size_t Rows = MatrixTraits<Derived>::Rows;
        static constexpr size_t Columns = MatrixTraits<Derived>::Columns;

        // Do some sanity checks.
        static_assert( Columns == 1 );
        static_assert( Rows > 1 );

        ScalarType const &operator[]( const size_t i ) const {
            massertf( i < Columns, "Matrix access index past bounds." );
            auto const &derived = *static_cast<Derived *>( this );
            assertf( derived.m_rows.size() == 1 );
            return derived.m_rows[0][i];
            //            return static_cast<Derived *>( this )->m_rows[0][i];
        }

        ScalarType &operator[]( const size_t i ) {
            massertf( i < Columns, "Matrix access index past bounds." );
            auto const &derived = *static_cast<Derived *>( this );
            assertf( derived.m_rows.size() == 1 );
            return derived.m_rows[0][i];
        }

        ScalarType const &operator()( const size_t i ) const {
            massertf( i < Columns, "Matrix access index past bounds." );
            auto const &derived = *static_cast<Derived *>( this );
            assertf( derived.m_rows.size() == 1 );
            return derived.m_rows[0][i];
        }

        ScalarType &operator()( const size_t i ) {
            massertf( i < Columns, "Matrix access index past bounds." );
            auto const derived = *static_cast<Derived *>( this );
            assertf( derived.m_rows.size() == 1 );
            return derived.m_rows[0][i];
        }
    };

    template <typename Derived>
    class MatrixAccessors<Derived, true, MatrixDimension::Two> {
    public:
        typedef typename MatrixTraits<Derived>::ScalarType ScalarType;
        typedef typename MatrixTraits<Derived>::RowType RowType;
        static constexpr size_t Rows = MatrixTraits<Derived>::Rows;
        static constexpr size_t Columns = MatrixTraits<Derived>::Columns;

        // Do some sanity checks.
        static_assert( Rows > 1 );
        static_assert( Columns > 1 );

        ScalarType const &operator()( const size_t i, const size_t j ) const {
            massertf( i < Rows, "Matrix access index past bounds." );
            massertf( j < Columns, "Matrix access index past bounds." );
            auto const &derived = *static_cast<Derived *>( this );
            return derived.m_rows[i][j];
        }

        ScalarType &operator()( const size_t i, const size_t j ) {
            massertf( i < Rows, "Matrix access index past bounds." );
            massertf( j < Columns, "Matrix access index past bounds." );
            auto &derived = *static_cast<Derived *>( this );
            return derived.m_rows[i][j];
        }
    };

}  // namespace arc::detail
