#include <QLabel>
#include <QLayout>

#include <GUI/Notebook/NotebookModel.hpp>

#include <GUI/Notebook/NotebookView.hpp>

namespace arc::gui {

    NotebookView::NotebookView( NotebookModel &model, QWidget *parent ) noexcept
        : m_model( model ),
          QWidget( parent ) {
        m_title = new QLabel( "<h1>Notebook 1.1:</h1>" );
        m_title->setAlignment( Qt::AlignHCenter );
        m_title->setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Minimum );

        auto mainWidget = new QWidget( this );

        //this->setStyleSheet("background-color: yellow;");
        //    QSizePolicy po;

        QSizePolicy po;
        po.setHorizontalPolicy( QSizePolicy::Preferred );
        po.setVerticalPolicy( QSizePolicy::Preferred );
        po.setVerticalStretch( 1 );
        po.setHorizontalStretch( 1 );

        this->setSizePolicy( po );
        mainWidget->setSizePolicy( po );

        //        mainWidget->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

        mainWidget->setMinimumWidth( 1400 );
        mainWidget->setMinimumHeight( 1000 );
        m_layout = new QVBoxLayout;
        m_layout->setContentsMargins( 70, 70, 70, 70 );
        m_layout->addWidget( m_title );
        //        m_layout->removeWidget( m_title );
        mainWidget->setLayout( m_layout );
    }

    void NotebookView::rebuildWidgets() noexcept {
        auto children = m_model.getChildren();
        for( auto c : children ) {
            assert( c->hasView() );
            m_layout->addWidget( c->getView(), Qt::AlignCenter );
            c->getView()->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
        }
        //        m_layout->addWidget( m_children.back().
        //        m_layout->child
    }

}  // namespace arc::gui
