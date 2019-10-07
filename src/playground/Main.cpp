#include <array>
#include <iomanip>
#include <iostream>

#include <Core/Debug/Assert.hpp>
//#include <Math/LinearAlgebra/matrix.hpp>
//#include <Math/LinearAlgebra/ostream_helpers.hpp>
//#include <Math/LinearAlgebra/qr_decompose.hpp>
//#include <Math/LinearAlgebra/span.hpp>
#include <Math/LinearAlgebra/back_substitution.hpp>
#include <Math/LinearAlgebra/linprog_simplex_rev.hpp>
#include "/home/jacques/repos/jmnel/ArcMath/src/Math/LinearAlgebra/matrix.hpp"

using std::array;
using std::cout;
using std::endl;

using namespace jmnel;

int main( int, char *[] ) {

    mat3x3d mat_r = {{1, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    vec3d b = {{1, 1, 1}};

    solve_back_substitution( mat_r, b );

    //    test();

    //    mat3x3d a = {{1, 2, 0}, {-1, 0, 1}, {1, 1, 1}};

    //    auto [q, r] = qr_decompose( a );

    //    cout << "a=" << endl << a << endl;
    //    cout << "q=" << endl << q << endl;
    //    cout << "r=" << endl << r << endl;
}
