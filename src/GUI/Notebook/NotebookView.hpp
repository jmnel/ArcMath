#pragma once

#include <QLabel>
#include <QLayout>
#include <QWidget>

namespace arc::gui {

    class NotebookModel;

    class NotebookView : public QWidget {
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
    };

}  // namespace arc::gui
