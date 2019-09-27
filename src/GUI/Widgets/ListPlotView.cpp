#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
//#include <tuple>

#include <QLabel>
#include <QLayout>
#include <QPainter>

#include <Plot/Plots/ListPlotModel.hpp>

#include <GUI/Widgets/ListPlotView.hpp>

using std::array;
using std::cout;
using std::endl;

namespace arc::gui {

    ListPlotView::ListPlotView( plot::ListPlotModel &model, QWidget *parent ) noexcept
        : m_model( model ),
          QWidget( parent ) {
        m_title = new QLabel();
        const auto qString = QString::fromUtf8( model.title().c_str() );
        m_title->setText( qString );
        m_title->setSizePolicy( QSizePolicy( QSizePolicy::Minimum, QSizePolicy::Minimum ) );
        m_title->setAlignment( Qt::AlignHCenter );

        //        const auto w = width();
        //        const auto h = height();
        //        setMaximumWidth( 800 );
        //        setMinimumWidth( 800 );
        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->setContentsMargins( 70, 70, 70, 70 );
        mainLayout->addWidget( m_title );
        auto topFiller = new QWidget;
        topFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
        mainLayout->addWidget( topFiller );

        setLayout( mainLayout );
        //        layout->wi
    }

    void ListPlotView::paintEvent( QPaintEvent * ) {
        QPainter painter( this );
        QPen pen;
        QBrush brush;
        brush.setStyle( Qt::Dense4Pattern );
        brush.setColor( Qt::cyan );
        pen.setColor( Qt::black );
        pen.setWidth( 5 );
        painter.setPen( pen );
        //        painter.setBrush( brush );
        //        painter.setFont( QFont( "InputMono", 30 ) );
        //        painter.drawText( rect(), Qt::AlignCenter, "Blue" );

        //        float xMin = std::max_element(

        float xMin;
        float yMin;
        float xMax;
        float yMax;
        float xScale;
        float yScale;
        float xOffset;
        float yOffset;
        QTransform trans;

        const int topHeader = m_title->height() + 100;
        auto const &data = m_model.data();
        for( size_t iPlot = 0; iPlot < data.size(); iPlot++ ) {
            auto const &xy = data[iPlot];
            vector<float> xList;
            vector<float> yList;
            std::transform( xy.begin(),
                            xy.end(),
                            std::back_inserter( xList ),
                            []( auto const &p ) { return p.x; } );
            std::transform( xy.begin(),
                            xy.end(),
                            std::back_inserter( yList ),
                            []( auto const &p ) { return p.y; } );
            xMin = *std::min_element( xList.begin(), xList.end() );
            yMin = *std::min_element( yList.begin(), yList.end() );

            xMax = *std::max_element( xList.begin(), xList.end() );
            yMax = *std::max_element( yList.begin(), yList.end() );

            int margin = 50;

            xScale = (float)( width() - 2 * margin ) / ( xMax - xMin );
            yScale = (float)( height() - 2 * margin - topHeader ) / ( yMax - yMin );
            xOffset = -xMin * xScale + margin;
            yOffset = -yMin * yScale + margin + topHeader;

            trans.translate( xOffset, yOffset );
            trans.scale( xScale, yScale );

            pen.setColor( Qt::black );
            pen.setWidth( 2 );
            painter.setPen( pen );
            painter.drawLine( trans.map( QPointF{xMin, 0.0f} ),
                              trans.map( QPointF{
                                  xMax, 0.0f} ) );
            painter.drawLine( trans.map( QPointF{0.0f, yMin} ), trans.map( QPointF{0.0f, yMax} ) );

            pen.setColor( Qt::blue );
            pen.setWidth( 4 );
            painter.setPen( pen );
            for( auto const &p : xy ) {
                const auto pQ = trans.map( QPointF{p.x, p.y} );
                painter.drawPoint( pQ );
            }

            pen.setColor( Qt::red );
            pen.setWidth( 2 );
            painter.setPen( pen );
            for( size_t i = 0; i + 1 < xy.size(); i++ ) {
                auto const &p0 = trans.map( QPointF{xy[i].x, xy[i].y} );
                auto const &p1 = trans.map( QPointF{xy[i + 1].x, xy[i + 1].y} );

                painter.drawLine( p0, p1 );
            }
        }

        pen.setColor( Qt::black );
        pen.setWidth( 2 );
        painter.setPen( pen );

        //        QRect rec = geometry();
        //        auto t = painter.combinedTransform();

        QTransform t;
        t.translate( xOffset, yOffset );
        t.scale( xScale, yScale );

        //        auto r = QRect( xMin, yMin, xMax, yMax );
        auto r = QRect( 0, topHeader, width(), height() - topHeader );
        painter.drawRect( painter.combinedTransform().mapRect( ( r ) ) );

        QFont font( "InputMono", 10 );
        font.setItalic( true );
        painter.setFont( font );
        auto xLoc = t.map( QPointF{xMax, 0.0f} );
        auto yLoc = t.map( QPointF{0.0f, yMax} );
        xLoc.rx() += 20.0f;
        yLoc.ry() += 20.0f;
        QRectF xBox{-100.0f, -100.0f, 200.0f, 200.0f};
        QRectF yBox{-100.0f, -100.0f, 200.0f, 200.0f};
        xBox.moveTo( xLoc - QPointF{100.0f, 100.0f} );
        yBox.moveTo( yLoc - QPointF{100.0f, 100.0f} );
        painter.drawText( xBox, Qt::AlignCenter, "x" );
        painter.drawText( yBox, Qt::AlignCenter, "y" );
    }

}  // namespace arc::gui
