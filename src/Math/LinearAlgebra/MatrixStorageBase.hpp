#include "MatrixStorage.hpp"
#pragma once

#include <array>

#include <Core/Debug/Assert.hpp>

#include "Common.hpp"
#include "Traits.hpp"

using std::array;

namespace jmnel::matrix::detail {

    template <typename Derived,
              MatrixStorageType storageTypeT = traits<Derived>::storageType,
              MatrixDensity innerDensityT = traits<Derived>::innerDensity,
              MatrixDensity outerDensityT = traits<Derived>::outerDensity>
    class MatrixStorageBase;

    // -- Static type partial specialization of StorageBase --
    template <typename Derived>
    class MatrixStorageBase<Derived,
                            MatrixStorageType::Static,
                            MatrixDensity::Dense,
                            MatrixDensity::Dense> {

    private:
        using Scalar = typename traits<Derived>::Scalar;
        static constexpr size_t size = traits<Derived>::size;

        array<Scalar, size> m_storage{};

    public:
        MatrixStorageBase() noexcept {};
        MatrixStorageBase( Scalar const &x ) noexcept { m_storage.fill( x ); }

        Scalar const &storageAt( const size_t i ) const noexcept { return m_storage[i]; }

        Scalar &storageAt( const size_t i ) noexcept { return m_storage[i]; }
    };

    // -- PointerReference type partial specialization of StorageBase --
    template <typename Derived>
    class MatrixStorageBase<Derived,
                            MatrixStorageType::PointerReference,
                            MatrixDensity::Dense,
                            MatrixDensity::Dense> {

    private:
        using Scalar = typename traits<Derived>::Scalar;
        static constexpr size_t size = traits<Derived>::size;

        Scalar *m_storage = nullptr;

    protected:
        void initStorage( Scalar *x ) {
            assertf( x );
            m_storage = x;
        }

        void initStorage( const Scalar *const x ) {
            assertf( x );
            m_storage = x;
        }

    public:
        MatrixStorageBase() noexcept {};

        /// @todo: Should this take reference instead?
        //        MatrixStorageBase( Scalar *xPointer ) noexcept : m_storage( xPointer ) {}

        Scalar const &storageAt( const size_t i ) const noexcept {
            assertf( m_storage );
            return m_storage[i];
        }

        Scalar &storageAt( const size_t i ) noexcept {
            assertf( m_storage );
            return m_storage[i];
        }
    };

}  // namespace jmnel::matrix::detail
