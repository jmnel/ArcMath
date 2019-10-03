#include <iostream>

#include <Core/Debug/Assert.hpp>
#include <GUI/GraphWindow/GraphWindow.hpp>
#include <GUI/Widgets/TiledLayoutView.hpp>

#include <Plot/Graphics/TiledLayout.hpp>

using std::cout;
using std::endl;

namespace arc::plot {

    // -- Constructor --
    TiledLayout::TiledLayout( const int width, const int height ) noexcept
        : m_view( gui::display()->setChildView( new gui::TileLayoutView ) ),
          m_width( width ), m_height( height ) {

        for( int i = 0; i < height; i++ ) {
            m_rows.emplace_back();
            auto& row = m_rows.back();
            for( int j = 0; j < width; j++ ) {
                m_rows.emplace_back();
            }
        }
        cout << "TiledLayout created." << endl;
    }

    // -- setGraphic function --
    void TiledLayout::setGraphic( shared_ptr<IGraphic> graphic,
                                  const int row,
                                  const int column,
                                  const int span ) {

        assertf( graphic );
        assertf( row >= 0 );
        assertf( row < m_height );
        assertf( column >= 0 );
        assertf( column + span <= m_width );
    }

    // -- clear function --
    void TiledLayout::clear() {
        m_rows.clear();
    }

    // -- hasView function --
    bool TiledLayout::hasView() const noexcept {
        return true;
    }

    // -- getView function --
    QWidget* TiledLayout::getView() const noexcept {
        return m_view;
    }

}  // namespace arc::plot
