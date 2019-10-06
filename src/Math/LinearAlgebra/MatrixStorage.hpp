#pragma once

#include "Common.hpp"
#include "MatrixStorageBase.hpp"

namespace jmnel::matrix::detail {

    template <typename Derived, MatrixStorageType storageTypeT = traits<Derived>::storageType>
    class MatrixStorage;

    template <typename Derived>
    class MatrixStorage<Derived, MatrixStorageType::Static> : public MatrixStorageBase<Derived> {
    public:
        MatrixStorage() noexcept {}

        template <class T>
        MatrixStorage( T const &x ) noexcept : MatrixStorageBase<Derived>( x ) {}
    };

    template <typename Derived>
    class MatrixStorage<Derived, MatrixStorageType::PointerReference>
        : public MatrixStorageBase<Derived> {
    private:
        using Scalar = typename traits<Derived>::Scalar;

    public:
        MatrixStorage() noexcept {}
    };

};  // namespace jmnel::matrix::detail
