#include <Math/CoreMath.hpp>

#include <Plot/Plots/ListPlotModel.hpp>

using arc::math::min;

namespace arc::plot {

    // -- Default constructor --
    ListPlotModel::ListPlotModel() noexcept {
    }

    // -- Constructor: with seperate x and y lists.
    ListPlotModel::ListPlotModel( vector<float> const &x, vector<float> const &y ) noexcept {
        assertf( x.size() == y.size() );
        for( size_t i = 0; i < min( x.size(), y.size() ); i++ ) {
            m_data.emplace_back( x[i], y[i] );
        }
    }

    // -- Constructor: with single xy list.
    ListPlotModel::ListPlotModel( vector<Vec2f> const &xy ) noexcept {
        for( auto const &p : xy ) {
            m_data.emplace_back( xy );
        }
    }

    // -- title function --
    string const &ListPlotModel::title() const {
        return m_title;
    }

    // -- setTitle function --
    void ListPlotModel::setTitle( string const &title ) {
        m_title = title;
    }

    // -- data function --
    vector<vector<Vec2f>> const &ListPlotModel::data() const {
        return m_data;
    }

    // -- setData function --
    void ListPlotModel::setData( vector<vector<Vec2f>> const &data ) {
        m_data.clear();
        std::copy( data.begin(), data.end(), m_data.begin() );
    }

}  // namespace arc::plot
