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

    static_assert( std::is_same<detail::get_traits_t<Matrix<double, 2, 2>>::Options,
                                MatrixDefaultOptions>::value );

    //    static_assert( detail::traits<Matrix<double, 2, 2>>::isRowMajor() );
    //    assertf( detail::get_traits_t<decltype( a )>::isRowMajor() );
    //        {{0, 1}, {1, 0}};
    //    Matrix<double, 2, 2> b{{1, 2}, {3, 4}};

    //    cout << "a=" << endl;
    //    cout << a << endl;
    //    cout << "b=" << endl;
    //    cout << b << endl;
}
