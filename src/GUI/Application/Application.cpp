#include <memory>

#include <QtCore>

#include <GUI/Application/Application.hpp>

namespace arc::gui {

    // -- Constructor --
    Application::Application( int& argc, char* argv[] )
        : m_qApplication( argc, argv ) {
    }

    // -- exec function --
    int Application::exec() {
        return m_qApplication.exec();
    }

}  // namespace arc::gui
