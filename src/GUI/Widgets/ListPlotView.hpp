#pragma once

//#include <QLayout>
//#include <QPainter>
#include <QWidget>

namespace arc::gui {

    class ListPlotView : public QWidget {
    private:
        Q_OBJECT
    signals:
    public:
        explicit ListPlotView( QWidget *parent = 0 ) noexcept;

        virtual void paintEvent( QPaintEvent * );

    private slots:
    };

}  // namespace arc::gui
