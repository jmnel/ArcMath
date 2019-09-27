#include "MainWidget.hpp"
#include <QtWidgets>

MainWidget::MainWidget( QWidget* parent )
    : QWidget( parent ) {
    button_ = new QPushButton( tr( "Push Me!" ) );

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget( button_, 0, 0 );
    setLayout( mainLayout );
    setWindowTitle( tr( "Testing" ) );
}

MainWidget::~MainWidget() {
    delete button_;
}
