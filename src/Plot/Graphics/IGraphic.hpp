#pragma once

class QWidget;

namespace arc::plot {

    class IGraphic {
    private:
    public:
        virtual ~IGraphic() = default;

        bool virtual hasView() const noexcept = 0;
        virtual QWidget* getView() const noexcept = 0;
    };

}  // namespace arc::plot
