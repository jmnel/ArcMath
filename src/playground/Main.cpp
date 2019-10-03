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

    detail::MatrixStorage<double,
                          5,
                          1,
                          0,
                          size_t,
                          detail::matrix_storage_static_tag,
                          detail::matrix_storage_dense_tag,
                          detail::matrix_storage_dense_tag,
                          detail::matrix_storage_row_major_tag,
                          5,
                          5>
        foo;

    foo.coeffs( 1 ) = 0;
    //    foo.m_data[0] = 5;

    Matrix<double, 5, 5> a;
}
