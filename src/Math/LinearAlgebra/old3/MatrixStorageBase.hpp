#pragma once

#include <array>
#include <iostream>

#include <Core/Collections/HeaphArray.hpp>
//#include <Math/LinearAlgebra/CoeffRefs.hpp>
#include <Math/LinearAlgebra/ForwardDeclarations.hpp>
#include <Math/LinearAlgebra/Traits.hpp>

using std::array;
using std::cout;
using std::endl;

namespace arc::detail {

    template <typename Derived,
              typename MemoryTypeT = typename traits<Derived>::Options::MemoryType,
              typename InnerDensityT = typename traits<Derived>::Options::InnerDensity,
              typename OuterDensityT = typename traits<Derived>::Options::OuterDensity>
    class MatrixStorageImplementation;

    // -- Statck allocated dense storage implementation --
    template <typename Derived>
    class MatrixStorageImplementation<Derived,
                                      matrix_storage_static_tag,
                                      matrix_storage_dense_tag,
                                      matrix_storage_dense_tag> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef typename traits<Derived>::Options::Index Index;

        static constexpr Index rows() {
            return traits<Derived>::rows();
        }
        static constexpr Index cols() {
            return traits<Derived>::cols();
        }
        static constexpr Index size() {
            return traits<Derived>::size();
        }

        array<Scalar, size()> m_storage{};

    private:
    };

    // -- Dynamic allocated dense storage implementation --
    template <typename Derived>
    class MatrixStorageImplementation<Derived,
                                      matrix_storage_dynamic_tag,
                                      matrix_storage_dense_tag,
                                      matrix_storage_dense_tag> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef typename traits<Derived>::Options::Index Index;
        static constexpr Index rows() {
            return traits<Derived>::rows();
        }
        static constexpr Index cols() {
            return traits<Derived>::cols();
        }
        static constexpr Index size() {
            return traits<Derived>::size();
        }

        HeapArray<Scalar, size()> m_storage;

        MatrixStorageImplementation() noexcept {
            m_storage.fill( 0.0 );
        }
    };

    // -- Pointer reference dense outer and inner storage implementation --
    template <typename Derived>
    class MatrixStorageImplementation<Derived,
                                      matrix_storage_pointer_ref_tag,
                                      matrix_storage_dense_tag,
                                      matrix_storage_dense_tag> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef typename traits<Derived>::Options::Index Index;

        static constexpr Index rows() {
            return traits<Derived>::rows();
        }
        static constexpr Index cols() {
            return traits<Derived>::cols();
        }
        static constexpr Index size() {
            return traits<Derived>::size();
        }

        static constexpr Index strideInner() {
            return traits<Derived>::strideInner();
        }
        static constexpr Index strideOuter() {
            return traits<Derived>::strideOuter();
        }
        Scalar* m_storage = nullptr;

    private:
        Scalar* m_start = nullptr;

    public:
        MatrixStorageImplementation() noexcept {
        }

        template <typename T>
        void init1( T* v,
                    std::enable_if<std::is_same<typename traits<Derived>::Options::MemoryType,
                                                matrix_storage_pointer_ref_tag>::value>* = 0 ) {
            assertf( v );
            m_start = v;
            m_storage = v;
            //            cout << "init1" << endl;
        }
    };

    // -- MatrixStorageBase class definition --
    template <class Derived>
    class MatrixStorageBase : public MatrixStorageImplementation<Derived> {
    public:
        typedef typename traits<Derived>::Scalar Scalar;
        typedef typename traits<Derived>::Options::Index Index;

        static constexpr Index rows() {
            return traits<Derived>::rows();
        }
        static constexpr Index cols() {
            return traits<Derived>::cols();
        }
        static constexpr Index size() {
            return traits<Derived>::size();
        }

        MatrixStorageBase() {
        }
    };

};  // namespace arc::detail
