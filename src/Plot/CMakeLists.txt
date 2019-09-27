# -- arcplot/CMakeLists.txt --

include_directories( . )

#include_directories( ${Boost_INCLUDE_DIRS} )

add_library( arcplot STATIC )

target_link_libraries(arcplot ${CONAN_LIBS})

target_include_directories(arcplot INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} )

include( ${CMAKE_CURRENT_SOURCE_DIR}/Plots/CMakeLists.txt )


target_link_libraries( arcplot stdc++fs)
