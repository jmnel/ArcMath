# -------------------- #
# ObjectModel/CMakeLists.txt #
# -------------------- #

set( ObjectModel_SRC 
    ${CMAKE_CURRENT_LIST_DIR}/Object.cpp 
    )

target_sources( arcgui PUBLIC ${ObjectModel_SRC} )
