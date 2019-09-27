#include <iostream>

#include <GUI/Notebook/Notebook.hpp>
#include <GUI/Widgets/ListPlotView.hpp>

#include <Plot/Plots/ListPlot.hpp>

using std::cout;
using std::endl;
using std::make_shared;

namespace arc::plot {

    // -- Constructor: default.
    ListPlot::ListPlot() noexcept {
        if( gui::gNotebook ) {
            assert( gui::gNotebook->hasView() );
            m_view = new gui::ListPlotView( m_model, gui::gNotebook->getView() );
        }
    }

    // -- Destructor --
    ListPlot::~ListPlot() {
    }

    // -- listPlot function --
    shared_ptr<ListPlot> listPlot() noexcept {
        auto p = std::make_shared<ListPlot>();
        if( gui::gNotebook ) {
            gui::gNotebook->addChild( p );
        }
        return p;
    }

    // -- listPlot function: with single xy list --
    shared_ptr<ListPlot> listPlot( vector<Vec2f> const &xy ) noexcept {
        auto p = std::make_shared<ListPlot>();
        p->m_model = ListPlotModel( xy );
        if( gui::gNotebook ) {
            gui::gNotebook->addChild( p );
        }
        return p;
    }

    // -- listPlot function: with seperate x and y lists --
    shared_ptr<ListPlot> listPlot( vector<float> const &x, vector<float> const &y ) noexcept {
        auto p = std::make_shared<ListPlot>();
        p->m_model = ListPlotModel( x, y );
        if( gui::gNotebook ) {
            gui::gNotebook->addChild( p );
        }
        return p;
    }

    // -- hasView function --
    bool ListPlot::hasView() const {
        return true;
    };

    // -- getView function --
    QWidget *ListPlot::getView() const {
        assert( m_view );
        return m_view;
    };

    // -- show funciton --
    void ListPlot::show() {
        gui::gNotebook->show();
    }

}  // namespace arc::plot
