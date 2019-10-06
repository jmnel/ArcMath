# -- Math/CMakeLists.txt --

include_directories( . )


add_library(arcmath STATIC CoreMath.cpp)

#target_link_libraries(arcgui ${CONAN_LIBS})

target_include_directories(arcmath PRIVATE ${CMAKE_CURRENT_LIST_DIR}/.. )

#include( ${CMAKE_CURRENT_LIST_DIR}/Geometry/CMakeLists.txt )
include( ${CMAKE_CURRENT_LIST_DIR}/LinearAlgebra/CMakeLists.txt )
#include( ${CMAKE_CURRENT_LIST_DIR}/Solvers/CMakeLists.txt )

#target_link_libraries( arcgui stdc++fs)
