#pragma once

#include <array>
#include <iostream>

#include <Math/CoreMath.hpp>
#include <Math/LinearAlgebra/Mat.hpp>
#include <Math/LinearAlgebra/Vec.hpp>

using std::array;
using std::cout;
using std::endl;

namespace arc {

    void simplexSolveRev( Mat<Real, 3, 5> matA,
                          Vec<Real, 3> b,
                          Vec<Real, 5> c,
                          array<int, 3> basisJ,
                          array<int, 2> noneK );

    void testSimplex();

}  // namespace arc
