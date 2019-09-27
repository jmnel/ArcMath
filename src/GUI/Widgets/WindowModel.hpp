#pragma once

#include <GUI/Widgets/IWindowModel.hpp>

namespace arc::gui {

    class WindowModel : public IWindowModel {
    private:
    public:
        explicit WindowModel() noexcept;
        ~WindowModel() final;
    };

}  // namespace arc::gui
