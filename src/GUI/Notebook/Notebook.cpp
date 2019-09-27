#include <GUI/Notebook/NotebookView.hpp>

#include <GUI/Notebook/Notebook.hpp>

namespace arc::gui {

    shared_ptr<Notebook> gNotebook;

    // -- Constructor --
    Notebook::Notebook() noexcept
        : m_model( m_children ) {
        m_view = new NotebookView( m_model );
    }

    // -- make function --
    shared_ptr<Notebook> Notebook::make() noexcept {
        gNotebook = std::make_shared<Notebook>();
        return gNotebook;
    }

    // -- show function --
    void Notebook::show() {
        m_view->rebuildWidgets();
        m_view->show();
    }

    // -- hasView function --
    bool Notebook::hasView() const {
        return true;
    };

    // -- getView function --
    QWidget* Notebook::getView() const {
        assert( m_view );
        return m_view;
    };

}  // namespace arc::gui
