#pragma once

#include <QLabel>
#include <QLayout>
#include <QMainWindow>
//#include <QWidget>

namespace arc::gui {

    class NotebookModel;

    class NotebookView : public QMainWindow {
    private:
        Q_OBJECT

        NotebookModel& m_model;

        QLabel* m_title = nullptr;
        QVBoxLayout* m_layout = nullptr;
    signals:
    public:
        explicit NotebookView( NotebookModel& model, QWidget* parent = 0 ) noexcept;

        void rebuildWidgets() noexcept;

    private slots:
    private:
        void setupMenus();
    };

}  // namespace arc::gui
