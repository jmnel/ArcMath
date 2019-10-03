# -------------------------- #
# GraphWindow/CMakeLists.txt #
# -------------------------- #

set( GraphWindow_SRC 
    ${CMAKE_CURRENT_LIST_DIR}/GraphWindow.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/GraphWindowModel.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/GraphWindowView.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/GraphWindowController.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/IGraphWindow.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/IGraphWindowModel.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/IGraphWindowView.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/IGraphWindowController.cpp 
    )

target_sources( arcgui PUBLIC ${GraphWindow_SRC} )
