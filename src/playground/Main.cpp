#include <iomanip>
#include <iostream>

#include <Math/CoreMath.hpp>
#include <Math/LinearAlgebra/Matrix.hpp>
//#include <Math/Solvers/RevSimplex.hpp>

#include <Math/LinearAlgebra/MatrixStorage.hpp>

using std::cout;
using std::endl;

using namespace arc;

int main( int, char *[] ) {

    Matrix<double,
           5,
           5,
           MatrixDeaultOptions>
        a;

    a.coeffs( 3, 3 ) = 5;

    cout << a << endl;
}
