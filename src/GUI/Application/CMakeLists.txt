# -------------------- #
# Application/CMakeLists.txt #
# -------------------- #

set( Application_SRC 
    ${CMAKE_CURRENT_LIST_DIR}/Application.cpp 
    )

target_sources( arcgui PUBLIC ${Application_SRC} )
