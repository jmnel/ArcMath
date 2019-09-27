#include <GUI/ObjectModel/Object.hpp>

namespace arc::gui {

    // -- add child function --
    void Object::addChild( shared_ptr<Object> child ) {
        m_children.push_back( child );
    }

}  // namespace arc::gui
