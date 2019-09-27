#pragma once

#include <QWidget>

#include <GUI/Widgets/IWindowView.hpp>

namespace arc::gui {

    class WindowView : public QWidget, public IWindowView {
    private:
        Q_OBJECT
    signals:
    public:
        explicit WindowView( QWidget *parent = 0 ) noexcept;
        ~WindowView() final = default;

        virtual void show() noexcept final;
    public slots:
    };

}  // namespace arc::gui
