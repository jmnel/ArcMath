#include <iostream>

#include <Core/Debug/Assert.hpp>

#include <Math/Solvers/GoldenMethod.hpp>

using std::cout;
using std::endl;
using std::make_tuple;

namespace arc {

    // Compute golden ratio and store as global consant.
    const Real PHI = ( sqrt( 5.0 ) + 1.0 ) * 0.5;

    tuple<Real, Real> solveGoldenMethod( Real a,
                                         Real b,
                                         function<Real( const Real x )> const& f,
                                         const Real tol,
                                         const Uint iterMax ) noexcept {

        // PRECONDITIONS
        massertf( a < b, "Golden Method interval is ill-formed." );
        massertf( tol > 0.0, "Tolerance must be greater than 0.0" );
        // Function f must be strictly unimodal.

        // Print debug trace output.
        cout << "Solving min f on interval I=[" << a << ", ";
        cout << b << "] using Golden Method...";
        cout << endl;

        Real c = b - ( b - a ) / PHI;
        Real d = a + ( b - a ) / PHI;

        // Main algorithm loop.
        for( Uint n = 0; n < iterMax; ++n ) {
            const bool toleranceReached = abs( c - d ) <= tol;
            if( toleranceReached ) {
                const Real xMin = ( b + a ) * 0.5;
                // Print debug trace output.
                cout << "  Tol reached after n=" << n << " iterations." << endl;
                cout << "  x=" << xMin << ", f(x)=" << f( xMin ) << endl;
                return make_tuple( xMin, f( xMin ) );
            }

            // Test f at c and d to narrow search interval.
            if( f( c ) < f( d ) ) {
                b = d;
            } else {
                a = c;
            }

            c = b - ( b - a ) / PHI;
            d = a + ( b - a ) / PHI;
        }

        // Print debug trace output.
        const Real xMin = ( b + a ) * 0.5f;
        cout << "  Failed to reach Tol=" << tol << " after " << iterMax << ".";
        cout << "  x=" << xMin << ", f(x)=" << f( xMin ) << endl;
        cout << endl;
        return {( b + a ) * 0.5, f( ( b + a ) * 0.5 )};
    }

    tuple<Real, Real> solveGoldenMethodTable( Real a,
                                              Real b,
                                              function<Real( const Real x )> const& f,
                                              const Uint maxIterations,
                                              vector<GoldenDebugRow>& table ) noexcept {

        // PRECONDITIONS
        massertf( a < b, "Golden Method interval is ill-formed." );
        // Function f must be strictly unimodal.

        Real c = b - ( b - a ) / PHI;
        Real d = a + ( b - a ) / PHI;

        // Main algorithm loop.
        for( Uint n = 0; n < maxIterations; ++n ) {

            table.emplace_back( n,
                                a,
                                b,
                                c,
                                d,
                                f( c ),
                                f( d ),
                                abs( c - d ),
                                ( b - a ) * 0.5 );

            // Test f at c and d to narrow search interval.
            if( f( c ) < f( d ) ) {
                b = d;
            } else {
                a = c;
            }

            c = b - ( b - a ) / PHI;
            d = a + ( b - a ) / PHI;
        }

        return {( b + a ) * 0.5, f( ( b + a ) * 0.5 )};
    }

}  // namespace arc
