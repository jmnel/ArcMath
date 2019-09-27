#pragma once

#include <GUI/Widgets/IWindowControl.hpp>

namespace arc::gui {

    class WindowControl : public IWindowControl {
    private:
    public:
        explicit WindowControl() noexcept;
        ~WindowControl() final;
    };

}  // namespace arc::gui
