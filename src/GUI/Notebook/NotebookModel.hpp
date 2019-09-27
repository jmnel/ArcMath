#pragma once

#include <memory>
#include <vector>

#include <GUI/ObjectModel/Object.hpp>

using std::shared_ptr;
using std::vector;

namespace arc::gui {

    class NotebookModel {
    private:
        vector<shared_ptr<Object>> &m_children;

    public:
        explicit NotebookModel( vector<shared_ptr<Object>> &children ) noexcept;

        vector<shared_ptr<Object>> &getChildren();
    };

}  // namespace arc::gui
