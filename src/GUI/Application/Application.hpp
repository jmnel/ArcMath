#pragma once

#include <QApplication>

namespace arc::gui {

    class Application {
    private:
        QApplication m_qApplication;

    public:
        Application( int &argc, char *argv[] );

        int exec();
    };

}  // namespace arc::gui
