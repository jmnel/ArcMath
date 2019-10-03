# -------------------- #
# Solvers/CMakeLists.txt #
# -------------------- #

set( Solvers_SRC 
    ${CMAKE_CURRENT_LIST_DIR}/GoldenMethod.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/RevSimplex.cpp 
    )

target_sources( arcmath PUBLIC ${Solvers_SRC} )
