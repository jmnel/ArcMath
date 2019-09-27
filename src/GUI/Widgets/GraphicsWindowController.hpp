#pragma once

#include <GUI/Widgets/IGraphicsWindowController.hpp>

namespace arc::gui {

    class GraphicsWindowController : public IGraphicsWindowController {
    private:
    public:
        explicit GraphicsWindowController() noexcept;
        ~GraphicsWindowController() final = default;
    };

}  // namespace arc::gui
