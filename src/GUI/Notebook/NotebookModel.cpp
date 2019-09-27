#include <GUI/Notebook/NotebookModel.hpp>

namespace arc::gui {

    // -- Constructor --
    NotebookModel::NotebookModel( vector<shared_ptr<Object>>& children ) noexcept
        : m_children( children ) {
    }

    vector<shared_ptr<Object>>& NotebookModel::getChildren() {
        return m_children;
    }

}  // namespace arc::gui
