#pragma once

#include <cstddef>
#include <memory>
#include <tuple>
#include <vector>

#include <Plot/Graphics/IGraphic.hpp>

using std::shared_ptr;
using std::tuple;
using std::vector;

namespace arc::gui {
    class TileLayoutView;
}

namespace arc::plot {

    class TiledLayout : public IGraphic {
    private:
        gui::TileLayoutView* m_view = nullptr;

        const int m_width;
        const int m_height;

        using GraphicSlot = tuple<int, int, shared_ptr<IGraphic>>;

        using Row = vector<GraphicSlot>;
        vector<Row> m_rows;

    public:
        TiledLayout( const int width, const int height ) noexcept;
        ~TiledLayout() noexcept final = default;

        void setGraphic( shared_ptr<IGraphic> graphic,
                         const int row,
                         const int column,
                         const int span );

        void clear();
        bool hasView() const noexcept final;
        QWidget* getView() const noexcept final;
    };

    template <class... Args>
    shared_ptr<TiledLayout> tiledLayout( Args&&... args ) {
        return std::make_shared<TiledLayout>( std::forward<Args>( args )... );
    }

}  // namespace arc::plot
