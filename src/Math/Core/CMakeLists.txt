# -------------------- #
# Core/CMakeLists.txt #
# -------------------- #

set( Core_SRC 
    ${CMAKE_CURRENT_LIST_DIR}/CoreMath.cpp 
    )

target_sources( arcmath PUBLIC ${Core_SRC} )
