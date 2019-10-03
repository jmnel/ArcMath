#include <QLabel>
#include <QLayout>
#include <QMenu>
#include <QMenuBar>

#include <GUI/GraphWindow/GraphWindowView.hpp>

namespace arc::gui {

    // -- Constructor --
    GraphWindowView::GraphWindowView() noexcept {

        m_mainLayout = new QVBoxLayout;
        m_titleLabel = new QLabel( tr( "Hello world. I am the title." ) );
        m_mainLayout->addWidget( m_titleLabel );

        setLayout( m_mainLayout );

        setupMenus();
    }

    // -- setupMenus function --
    void GraphWindowView::setupMenus() noexcept {
        QMenuBar* menuBar = new QMenuBar();

        auto fileMenu = menuBar->addMenu( tr( "&File" ) );
        fileMenu->addAction( tr( "&New" ) );
        fileMenu->addAction( tr( "&Open" ) );
        fileMenu->addAction( tr( "&Close" ) );
        fileMenu->addSeparator();
        fileMenu->addAction( tr( "&Save" ) );
        fileMenu->addAction( tr( "&Save as" ) );
        fileMenu->addSeparator();
        fileMenu->addAction( tr( "&Exit" ) );

        auto editMenu = menuBar->addMenu( tr( "&Edit" ) );
        auto viewMenu = menuBar->addMenu( tr( "&View" ) );
        auto toolsMenu = menuBar->addMenu( tr( "&Tools" ) );

        auto helpMenu = menuBar->addMenu( tr( "&Help" ) );
        helpMenu->addAction( tr( "&About" ) );

        m_mainLayout->setMenuBar( menuBar );
    }

}  // namespace arc::gui
