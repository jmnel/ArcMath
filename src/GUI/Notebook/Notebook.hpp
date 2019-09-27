#pragma once

#include <memory>
#include <vector>

#include <GUI/Notebook/NotebookModel.hpp>
#include <GUI/ObjectModel/Object.hpp>

using std::shared_ptr;
using std::vector;

class QWidget;

namespace arc::gui {

    class Notebook;
    class NotebookView;
    extern shared_ptr<Notebook> gNotebook;

    class Notebook : public Object {
    private:
        NotebookModel m_model;
        NotebookView* m_view = nullptr;

    public:
        explicit Notebook() noexcept;
        ~Notebook() = default;
        static shared_ptr<Notebook> make() noexcept;

        bool hasView() const final;
        QWidget* getView() const final;

        void show();

        //        void addChild( shared_ptr<NotebookObject> child );
    };

}  // namespace arc::gui
