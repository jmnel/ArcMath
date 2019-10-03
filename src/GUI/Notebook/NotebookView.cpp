#include <QLabel>
#include <QLayout>
#include <QMenuBar>
#include <QWindow>

#include <GUI/Notebook/NotebookModel.hpp>

#include <GUI/Notebook/NotebookView.hpp>

namespace arc::gui {

    NotebookView::NotebookView( NotebookModel &model, QWidget *parent ) noexcept
        : m_model( model ),
          QMainWindow( parent ) {

        auto w = new QWidget();
        w->show();

        setupMenus();

        //        auto topLayout = new QVBoxLayout;
        auto centralWidget = new QWidget( this );
        setCentralWidget( centralWidget );
        //        topLayout->addWidget( centralWidge
        m_title = new QLabel( "<h1>Notebook 1.1:</h1>", centralWidget );
        m_layout = new QVBoxLayout;
        m_layout->setContentsMargins( 70, 70, 70, 70 );
        m_layout->addWidget( m_title, 0, Qt::AlignHCenter | Qt::AlignTop );
        centralWidget->setLayout( m_layout );
    }

    void NotebookView::rebuildWidgets() noexcept {
        auto children = m_model.getChildren();
        for( auto c : children ) {
            assert( c->hasView() );
            m_layout->addWidget( c->getView(), 2 );
        }
    }

    void NotebookView::setupMenus() {
        auto fileMenu = menuBar()->addMenu( tr( "&File" ) );
        fileMenu->addAction( new QAction( "&New" ) );
        fileMenu->addAction( new QAction( "&Open" ) );
        fileMenu->addAction( new QAction( "&Close" ) );
        fileMenu->addSeparator();
        fileMenu->addAction( new QAction( "&Save" ) );
        fileMenu->addAction( new QAction( "&Save As" ) );
        fileMenu->addSeparator();
        fileMenu->addAction( new QAction( "&Quit" ) );

        auto editMenu = menuBar()->addMenu( tr( "&Edit" ) );
        auto viewMenu = menuBar()->addMenu( tr( "&View" ) );
        auto toolsMenu = menuBar()->addMenu( tr( "&Tools" ) );
        auto optionsMenu = menuBar()->addMenu( tr( "&Options" ) );

        auto helpMenu = menuBar()->addMenu( tr( "&Help" ) );
        helpMenu->addAction( new QAction( "&About" ) );
    }

}  // namespace arc::gui
