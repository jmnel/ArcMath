#pragma once

#include <QLabel>
#include <QWidget>

namespace arc::plot {

    class ListPlotModel;
}

namespace arc::gui {

    class ListPlotView : public QWidget {
    private:
        Q_OBJECT

        QLabel *m_title = nullptr;
        plot::ListPlotModel &m_model;
    signals:
    public:
        explicit ListPlotView( plot::ListPlotModel &model, QWidget *parent = 0 ) noexcept;

        virtual void paintEvent( QPaintEvent * );

    private slots:
    };

}  // namespace arc::gui
