#include <iostream>

//#include <QApplication>
//#include <QPushButton>

#include <GUI/Application/Application.hpp>
//#include <GUI/Widgets/GraphicsWindow.hpp>

#include <GUI/Notebook/Notebook.hpp>
#include <Math/CoreMath.hpp>
#include <Math/LinearAlgebra/Vec.hpp>
#include <Plot/Plots/ListPlot.hpp>

//#include <Widgets/Window.hpp>

using arc::math::Vec2f;
using std::cout;
using std::endl;

using namespace arc;
using namespace math;

int main( int argc, char* argv[] ) {

    gui::Application app( argc, argv );

    auto nb = gui::Notebook::make();
    vector<Vec2f> xy;
    for( int i = -50; i < 50; i++ ) {
        const auto x = i * 0.05 * Pi;
        const auto y = sin( x );
        Vec2f a( x, y );
        xy.emplace_back( x, y );
    }
    auto p = plot::listPlot( xy );
    //    auto p2 = plot::listPlot();
    p->show();

    //    gui::GraphicsWindow* gWindow = new gui::GraphicsWindow();
    //    gWindow->show();

    return app.exec();
}
