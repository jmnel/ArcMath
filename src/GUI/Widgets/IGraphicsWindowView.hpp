#pragma once

namespace arc::gui {

    class IGraphicsWindowView {
    private:
    public:
        virtual ~IGraphicsWindowView() = default;

        virtual void show() = 0;
    };

}  // namespace arc::gui
