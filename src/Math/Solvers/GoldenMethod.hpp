#pragma once

#include <functional>
#include <tuple>
#include <vector>

#include <Math/CoreMath.hpp>

using std::function;
using std::numeric_limits;
using std::tuple;
using std::vector;

namespace arc {

    tuple<Real, Real> solveGoldenMethod( Real a,
                                         Real b,
                                         function<Real( const double x )> const& f,
                                         const Real tol = 1e-5,
                                         const Uint iterMax =
                                             numeric_limits<Uint>::max() ) noexcept;

    struct GoldenDebugRow {
        const Uint m_n;
        const Real m_a;
        const Real m_b;
        const Real m_c;
        const Real m_d;
        const Real m_fAtC;
        const Real m_fAtD;
        const Real m_tolerance;
        const Real m_estimate;

        GoldenDebugRow( const Uint n,
                        const Real a,
                        const Real b,
                        const Real c,
                        const Real d,
                        const Real fAtC,
                        const Real fAtD,
                        const Real tolerance,
                        const Real estimate ) noexcept
            : m_n( n ), m_a( a ), m_b( b ), m_c( c ), m_d( d ),
              m_fAtC( fAtC ), m_fAtD( fAtD ),
              m_tolerance( tolerance ), m_estimate( estimate ) {
        }
    };

    tuple<Real, Real> solveGoldenMethodTable( Real a,
                                              Real b,
                                              function<Real( const double x )> const& f,
                                              const Uint iterMax,
                                              vector<GoldenDebugRow>& table ) noexcept;

}  // namespace arc
