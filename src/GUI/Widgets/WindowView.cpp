#include <GUI/Widgets/WindowView.hpp>

namespace arc::gui {

    // -- Constructor --
    WindowView::WindowView( QWidget* parent ) noexcept
        : QWidget( parent ) {
    }

    // -- show function --
    void WindowView::show() noexcept {
        QWidget::show();
    }

}  // namespace arc::gui
