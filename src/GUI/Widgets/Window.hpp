#pragma once

#include <memory>

//#include <QWidget>

using std::shared_ptr;

namespace arc::gui {

    class WindowView;

    class Window {
    private:
        shared_ptr<WindowView> m_windowView;

    public:
        explicit Window() noexcept;

        void show() noexcept;
    };

}  // namespace arc::gui
