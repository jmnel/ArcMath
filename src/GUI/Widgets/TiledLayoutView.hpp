#pragma once

#include <QWidget>

#include <GUI/GraphWindow/GraphWindow.hpp>

namespace arc::gui {

    class TileLayoutView : public QWidget {
    private:
    public:
        explicit TileLayoutView( QWidget* parent = nullptr ) noexcept;
        ~TileLayoutView() noexcept final;
    };

}  // namespace arc::gui
