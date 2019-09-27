#include <QGroupBox>
#include <QLayout>
#include <QMenuBar>
#include <QMessageBox>
#include <QPainter>
#include <QPushButton>
#include <QStatusBar>
#include <QToolBar>

#include <GUI/Widgets/GraphicsWindowView.hpp>

namespace arc::gui {

    void GraphicsWindowView::about() {
        QMessageBox::about( this, "title", "foobar" );
    }

    // -- Constructor --
    GraphicsWindowView::GraphicsWindowView( QWidget* parent ) noexcept
        : QMainWindow( nullptr )
    //          m_title( tr( "Title" ), this ) {
    {

        /*
        m_plotView = new ListPlotView;
        //        m_plotView = std::make_shared<ListPlotView>( this );

        auto widget = new QWidget;
        setCentralWidget( widget );

        auto topFiller = new QWidget;
        topFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
        //        auto infoLabel = new QLabel( tr( "<i>Bla bla bla</i>" ) );
        auto bottomFiller = new QWidget;
        bottomFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

        //        auto middleFiller = new QWidget;
        //        middleFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

        QVBoxLayout* layout = new QVBoxLayout;
        layout->setContentsMargins( 5, 5, 5, 5 );
        layout->addWidget( topFiller );
        //        layout->addWidget( infoLabel );
        //        layout->addWidget( middleFiller );
        layout->addWidget( m_plotView, Qt::AlignCenter );
        layout->addWidget( bottomFiller );
        widget->setLayout( layout );
        statusBar()->showMessage( "hi i am the status bar" );

        //        auto menuBar = new QMenuBar( this );
        QMenu* fileMenu = menuBar()->addMenu( tr( "&File" ) );
        QAction* aboutAct = fileMenu->addAction( tr( "About" ), this, &GraphicsWindowView::about );

        */
        //        QPushButton* button = new QPushButton( "button", this );
        //        setCentralWidget( button );
        //        QWidget* centralWidget = new QWidget;
        //        setCentralWidget( centralWidget );

        //        auto menu = menuBar();

        //                menu->addMenu( new QMenu( "this" ) );
        //        auto tb = addToolBar( tr( "toolbar" ) );
        //                tb->addMenu( new QAction( tr( "&File" ) ) );

        //        auto fileMenu = menuBar->addMenu( tr( "file" ) );

        //        auto title = new QLabel( tr( "title" ), this );
        //        auto line21 = new QLabel( tr( "21" ), this );
        //        auto line22 = new QLabel( tr( "22" ), this );

        //        QVBoxLayout* mainLayout = new QVBoxLayout;
        //        mainLayout->setMenuBar( menuBar );

        //        QGridLayout* layout = new QGridLayout();
        //        layout->addWidget( menuBar, 0, 0, 1, 2 );
        //        mainLayout->addWidget( title );
        //        layout->addWidget( line21, 2, 0 );
        //        layout->addWidget( line22, 2, 1 );

        //        layout->setAlignment( title, Qt::AlignCenter );

        //        QGroupBox* box = new QGroupBox( this );
        //        box->setLayout( layout );
        //        setCentralWidget( box );

        //        setLayout( mainLayout );
    }

    // -- Destructor --
    //    GraphicsWindowView::~GraphicsWindowView() {
    //    }

    // -- show function --
    void GraphicsWindowView::show() {
        //        assert( this );
        //        show();
        QWidget::show();
    }

    // -- paintEvent function --
    void GraphicsWindowView::paintEvent( QPaintEvent* ) {
        //        QPainter painter( this );
        //        painter.setPen( Qt::blue );
        //        painter.setFont( QFont( "InputMono", 30 ) );
        //        painter.drawText( rect(), Qt::AlignCenter, "Blue" );
    }

}  // namespace arc::gui
