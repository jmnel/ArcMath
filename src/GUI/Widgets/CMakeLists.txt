# -------------------- #
# Widgets/CMakeLists.txt #
# -------------------- #

set( Widgets_SRC 
#    ${CMAKE_CURRENT_LIST_DIR}/ListPlotView.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/TiledLayoutView.cpp 
    )

target_sources( arcgui PUBLIC ${Widgets_SRC} )
