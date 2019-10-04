#include <iomanip>
#include <iostream>

#include <Core/Debug/Assert.hpp>

#include <Math/CoreMath.hpp>
#include <Math/LinearAlgebra/Matrix.hpp>
//#include <Math/Solvers/RevSimplex.hpp>

#include <Math/LinearAlgebra/MatrixStorage.hpp>

using std::cout;
using std::endl;

using namespace arc;

using Index = size_t;

int main( int, char *[] ) {

    Matrix<double, 5, 5> a;

    assertf( !detail::traits<decltype( a )>::isVectorType() );

    //    typedef int Index;

    for( int i = 0; i < 5; ++i ) {
        for( int j = 0; j < 5; ++j ) {
            a.coeffs( i, j ) = double( i * 5 + j );
        }
    }
    cout << "a=" << endl << a << endl;

    cout << a.subCol<3>( 4, 2 ) << endl;
}
