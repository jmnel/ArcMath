#pragma once

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

class QWidget;

namespace arc::gui {

    class Object {
    private:
    protected:
        vector<shared_ptr<Object>> m_children;

    public:
        virtual ~Object() = default;
        virtual bool hasView() const = 0;
        virtual QWidget* getView() const = 0;

        void addChild( shared_ptr<Object> child );
    };

}  // namespace arc::gui
