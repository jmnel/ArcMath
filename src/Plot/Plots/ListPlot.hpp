#pragma once

#include <Graphics/Graphic.hpp>

namespace arc::plot {

    class ListPlot : public Graphic {
    private:
    public:
        ListPlot() noexcept;
        virtual ~ListPlot() = default;
    };

}  // namespace arc::plot
