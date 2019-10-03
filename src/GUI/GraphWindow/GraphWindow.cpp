#include <iostream>

#include <QWidget>

#include <Core/Debug/Assert.hpp>
#include <GUI/GraphWindow/GraphWindowView.hpp>

#include <GUI/GraphWindow/GraphWindow.hpp>

using std::cout;
using std::endl;

namespace arc::gui {

    // -- Constructor --
    GraphWindow::GraphWindow() noexcept
        : m_view( new GraphWindowView ) {

        cout << "GraphWindow created." << endl;
    }

    // -- show function --
    void GraphWindow::show() noexcept {
        assertf( m_view );
        static_cast<GraphWindowView*>( m_view )->show();
    }

    // -- hasView function --
    bool GraphWindow::hasView() const noexcept {
        return true;
    }

    // -- getView function --
    QWidget* GraphWindow::getView() const noexcept {
        assertf( m_view );
        return ( static_cast<GraphWindowView*>( m_view ) );
    }

    shared_ptr<GraphWindow> display() noexcept {
        if( !gGraphWindow ) {
            gGraphWindow = std::make_shared<GraphWindow>();
        }
        return gGraphWindow;
    }

    shared_ptr<GraphWindow>
        gGraphWindow;

}  // namespace arc::gui
