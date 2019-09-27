#pragma once

#include <Math/LinearAlgebra/Vec.hpp>

#include <string>
#include <vector>

using arc::math::Vec2f;
using std::string;
using std::vector;

namespace arc::plot {

    class ListPlotModel {
    private:
        string m_title = "<b>Listplot 1.5:</b> Some nice information.";
        vector<vector<Vec2f>> m_data;

    public:
        explicit ListPlotModel() noexcept;
        explicit ListPlotModel( vector<float> const &x, vector<float> const &y ) noexcept;
        explicit ListPlotModel( vector<Vec2f> const &xy ) noexcept;

        string const &title() const;
        void setTitle( string const &title );
        vector<vector<Vec2f>> const &data() const;
        void setData( vector<vector<Vec2f>> const &data );
    };

}  // namespace arc::plot
