#pragma once

#include <memory>

#include <GUI/GraphWindow/GraphWindowController.hpp>
#include <GUI/GraphWindow/GraphWindowModel.hpp>

#include <GUI/GraphWindow/IGraphWindow.hpp>

using std::shared_ptr;

class QWidget;

namespace arc::plot {
    class IGraphic;
}

namespace arc::gui {

    class IGraphWindowView;

    class GraphWindow : public IGraphWindow {
    private:
        GraphWindowModel m_model;
        IGraphWindowView* m_view = nullptr;
        GraphWindowController m_controller;

    public:
        GraphWindow() noexcept;
        ~GraphWindow() noexcept final = default;

        void show() noexcept final;

        bool hasView() const noexcept;
        QWidget* getView() const noexcept;

        void setChildView( plot::IGraphic* child );
    };

    shared_ptr<GraphWindow> display() noexcept;

    extern shared_ptr<GraphWindow> gGraphWindow;

}  // namespace arc::gui
