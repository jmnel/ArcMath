#pragma once

namespace arc::gui {

    class IWindowView {
    private:
    public:
        virtual ~IWindowView() = default;

        virtual void show() noexcept = 0;
    };

}  // namespace arc::gui
