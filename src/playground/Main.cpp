#include <iostream>

//#include <QApplication>
//#include <QPushButton>

#include <GUI/Application/Application.hpp>
#include <GUI/Widgets/GraphicsWindow.hpp>

//#include <Widgets/Window.hpp>

using std::cout;
using std::endl;

using namespace arc;

int main( int argc, char* argv[] ) {

    gui::Application app( argc, argv );

    gui::GraphicsWindow* gWindow = new gui::GraphicsWindow();
    gWindow->show();

    return app.exec();
}
