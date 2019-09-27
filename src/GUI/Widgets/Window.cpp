#include <GUI/Widgets/WindowView.hpp>

#include <GUI/Widgets/Window.hpp>

namespace arc::gui {

    // -- Constructor --
    Window::Window() noexcept
        : m_windowView( std::make_shared<WindowView>() ) {
    }

    void Window::show() noexcept {
        m_windowView->show();
    }

}  // namespace arc::gui
