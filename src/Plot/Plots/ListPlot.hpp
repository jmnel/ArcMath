#pragma once

#include <memory>
#include <vector>

#include <GUI/ObjectModel/Object.hpp>
//#include <GUI/Widgets/ListPlotView.hpp>
#include <Math/LinearAlgebra/Vec.hpp>
#include <Plot/Graphics/Graphic.hpp>
#include <Plot/Plots/ListPlotModel.hpp>

using arc::math::Vec2f;
using std::shared_ptr;
using std::vector;

namespace arc::gui {
    class ListPlotView;
}

namespace arc::plot {

    class ListPlot : public Graphic, public gui::Object {
    private:
        gui::ListPlotView *m_view;
        ListPlotModel m_model;

    public:
        explicit ListPlot() noexcept;
        //        explicit ListPlot( vector<Vec2f> const &xy ) noexcept;
        //        explicit ListPlot( vector<float> const &x, vector<float> const &y ) noexcept;
        virtual ~ListPlot();

        bool hasView() const final;
        QWidget *getView() const final;

        void show();

        friend shared_ptr<ListPlot> listPlot() noexcept;
        friend shared_ptr<ListPlot> listPlot( vector<Vec2f> const & ) noexcept;
        friend shared_ptr<ListPlot> listPlot( vector<float> const &, vector<float> const & ) noexcept;
    };

    shared_ptr<ListPlot> listPlot() noexcept;
    shared_ptr<ListPlot> listPlot( vector<Vec2f> const &xy ) noexcept;
    shared_ptr<ListPlot> listPlot( vector<float> const &x, vector<float> const &y ) noexcept;

}  // namespace arc::plot
