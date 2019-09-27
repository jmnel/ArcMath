#include <GUI/Widgets/GraphicsWindowController.hpp>
#include <GUI/Widgets/GraphicsWindowModel.hpp>
#include <GUI/Widgets/GraphicsWindowView.hpp>

#include <GUI/Widgets/GraphicsWindow.hpp>

namespace arc::gui {

    // -- Constructor --
    GraphicsWindow::GraphicsWindow() noexcept {
        m_model = std::make_shared<GraphicsWindowModel>();
        m_view = std::make_shared<GraphicsWindowView>();
        m_controller = std::make_shared<GraphicsWindowController>();
    }

    // -- show function --
    void GraphicsWindow::show() {
        m_view->show();
    }

}  // namespace arc::gui
