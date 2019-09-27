# -------------------- #
# Plots/CMakeLists.txt #
# -------------------- #

set( Plots_SRC 
    ${CMAKE_CURRENT_LIST_DIR}/Graphic.cpp 
    )

target_sources( arcplot PUBLIC ${Plots_SRC} )
