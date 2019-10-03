#pragma once

#include <QWidget>

#include <GUI/GraphWindow/IGraphWindowView.hpp>

class QLabel;
class QVBoxLayout;
//class QMenuBar;

namespace arc::gui {

    class GraphWindowView : public QWidget, public IGraphWindowView {
    private:
        Q_OBJECT

        QVBoxLayout* m_mainLayout = nullptr;
        QLabel* m_titleLabel = nullptr;

    signals:

    public:
        GraphWindowView() noexcept;
        ~GraphWindowView() noexcept final = default;

        //        void show() noexcept final;

    private slots:
    private:
        void setupMenus() noexcept;
    };

}  // namespace arc::gui
