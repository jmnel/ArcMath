#include <Math/Solvers/RevSimplex.hpp>

namespace arc {

    template <typename T, size_t N>
    std::ostream &operator<<( std::ostream &os, array<T, N> const &a ) {
        static_assert( N > 1 );
        os << "( ";
        os << *a.begin();
        for( auto it = a.begin() + 1; it != a.end(); ++it ) {
            os << ", " << *it;
        }
        os << " )";
        return os;
    }

    // -- simplexSolveRev function --
    void simplexSolveRev( Mat<Real, 3, 5> matA,
                          Vec<Real, 3> b,
                          Vec<Real, 5> c,
                          array<int, 3> basisJ,
                          array<int, 2> noneK ) {

        const auto j0 = basisJ[0];
        const auto j1 = basisJ[1];
        const auto j2 = basisJ[2];

        cout << "J_1=" << basisJ << "    ";
        cout << "K_1=" << noneK << endl
             << endl;

        cout << "matA=" << endl;
        cout << matA << endl;
        cout << endl;

        //        Mat<Real, 3, 3> matAJ1 = {{
        //            Vec3d{matA[0][j0], matA[0][j1], matA[0][j2]},
        //            Vec3d{matA[1][j0], matA[1][j1], matA[1][j2]},
        //            Vec3d{matA[2][j0], matA[2][j1], matA[2][j2]},
        //        }};

        //        cout << "matAJ1=" << endl;
        //        cout << matAJ1 << endl;
    }

    // -- testSimplex function --
    void testSimplex() {
        //        Mat<Real, 3, 5> matA = {Vec<Real, 5>{20.0, 20.0, -1.0, 0.0, 0.0},
        //                                Vec<Real, 5>{15.0, 3.0, 0.0, -1.0, 0.0},
        //                                Vec<Real, 5>{5.0, 10.0, 0.0, 0.0, -1.0}};

        Vec<Real, 3> b{60.0, 15.0, 20.0};
        Vec<Real, 5> c{0.0};
        c[0] = 10.0;
        c[1] = 7.0;

        array<int, 3> basisJ = {0, 2, 3};
        array<int, 2> noneK = {1, 4};

        //        simplexSolveRev( matA, b, c, basisJ, noneK );
    }
}  // namespace arc
