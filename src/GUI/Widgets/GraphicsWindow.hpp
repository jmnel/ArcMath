#pragma once

#include <memory>

using std::shared_ptr;

namespace arc::gui {

    class IGraphicsWindowModel;
    class IGraphicsWindowController;
    class IGraphicsWindowView;

    class GraphicsWindow {
    private:
        shared_ptr<IGraphicsWindowModel> m_model;
        shared_ptr<IGraphicsWindowView> m_view;
        shared_ptr<IGraphicsWindowController> m_controller;

    public:
        explicit GraphicsWindow() noexcept;

        void show();
    };

}  // namespace arc::gui
