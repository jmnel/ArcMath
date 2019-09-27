#pragma once

#include <memory>

#include <QLabel>
#include <QMainWindow>
#include <QWidget>

#include <GUI/Widgets/ListPlotView.hpp>

#include <GUI/Widgets/IGraphicsWindowView.hpp>

using std::shared_ptr;

namespace arc::gui {

    class GraphicsWindowView : public QMainWindow, public IGraphicsWindowView {
    private:
        Q_OBJECT

        //        ListPlotView* m_plotView;

    signals:
    public:
        explicit GraphicsWindowView( QWidget* parent = 0 ) noexcept;
        //        ~GraphicsWindowView() final = default;

        void show() final;
        virtual void paintEvent( QPaintEvent* );

    private slots:
        void about();
    };

}  // namespace arc::gui
