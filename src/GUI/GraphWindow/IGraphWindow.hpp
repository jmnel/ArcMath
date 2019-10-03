#pragma once

namespace arc::gui {

    class IGraphWindow {
    private:
    public:
        virtual ~IGraphWindow() = default;

        virtual void show() noexcept = 0;
    };

}  // namespace arc::gui
