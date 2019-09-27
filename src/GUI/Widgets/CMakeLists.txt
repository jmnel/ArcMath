# -------------------- #
# Widgets/CMakeLists.txt #
# -------------------- #

set( Widgets_SRC 
    ${CMAKE_CURRENT_LIST_DIR}/Window.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/WindowView.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/WindowModel.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/WindowController.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/IWindowView.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/IWindowModel.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/IWindowController.cpp 
    
    ${CMAKE_CURRENT_LIST_DIR}/GraphicsWindow.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/GraphicsWindowModel.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/GraphicsWindowView.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/GraphicsWindowController.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/IGraphicsWindowModel.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/IGraphicsWindowView.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/IGraphicsWindowController.cpp 
    
    ${CMAKE_CURRENT_LIST_DIR}/ListPlotView.cpp 
    )

target_sources( arcgui PUBLIC ${Widgets_SRC} )
