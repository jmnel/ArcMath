#pragma once

#include <GUI/Widgets/IGraphicsWindowModel.hpp>

namespace arc::gui {

    class GraphicsWindowModel : public IGraphicsWindowModel {
    private:
    public:
        explicit GraphicsWindowModel() noexcept;
        ~GraphicsWindowModel() final = default;
    };

}  // namespace arc::gui
