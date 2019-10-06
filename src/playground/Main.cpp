#include <iomanip>
#include <iostream>

#include <Core/Debug/Assert.hpp>

#include <Math/LinearAlgebra/Matrix>
#include "/home/jacques/repos/jmnel/ArcMath/src/Math/LinearAlgebra/MatrixOptions.hpp"

using std::array;
using std::cout;
using std::endl;

using namespace jmnel;

int main( int, char *[] ) {

    Mat3x3d a = Mat3x3d::identiy();
    Mat3x3d b = {{1, 2, 3}, {4, 5, 6}, {7, 8, 8}};
    //    Matrix<double, 1, 5, MatrixOptions<>> a( 1.0 );
    //    Matrix<double, 5, 1, MatrixOptions<>> b( -3.0 );

    //    _ARC_DEBUG_BREAK();
    auto c = normalize( a.row( 0 ) );
    cout << c << endl;
    //    cout << Mat3x3d::identiy() << endl;

    //    auto c = a.row( 0 );
}
