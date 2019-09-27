#include <array>
#include <cmath>
//#include <tuple>

#include <QLabel>
#include <QLayout>
#include <QPainter>

#include <GUI/Widgets/ListPlotView.hpp>

using std::array;

namespace arc::gui {

    ListPlotView::ListPlotView( QWidget *parent ) noexcept
        : QWidget( parent ) {
        QLabel *title = new QLabel( "Figure 1.1:" );
        title->setAlignment( Qt::AlignHCenter );

        QVBoxLayout *layout = new QVBoxLayout;
        layout->setContentsMargins( 70, 70, 70, 70 );
        layout->addWidget( title, Qt::AlignCenter );
        setLayout( layout );
        //        layout->wi
    }

    void ListPlotView::paintEvent( QPaintEvent * ) {
        QPainter painter( this );
        QPen pen;
        pen.setColor( Qt::black );
        pen.setWidth( 2 );
        painter.setPen( pen );
        painter.setFont( QFont( "InputMono", 30 ) );
        painter.drawText( rect(), Qt::AlignCenter, "Blue" );

        QPen pen2;
        pen2.setWidth( 4 );
        pen2.setColor( Qt::red );

        const auto w = width();
        const auto h = height();

        painter.drawLine( QLineF( 30, h / 2, w - 30, h / 2 ) );
        painter.drawLine( QLineF( w / 2, 30, w / 2, h - 30 ) );

        for( int i = 0; i <= ( w - 100 ) / 20; i++ ) {
            auto j = i * 20;
            painter.drawLine( QLineF( j + 50, h / 2 - 10, j + 50, h / 2 + 10 ) );

            painter.setPen( pen2 );

            float y = sin( j / 100.0f ) * 200 + h / 2;

            painter.drawPoint( QPoint{j, (int)y} );

            painter.setPen( pen );
        }

        painter.drawRoundedRect( QRect{20, 20, w - 40, h - 40}, 50, 50 );
    }

}  // namespace arc::gui
