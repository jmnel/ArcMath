# -- arcplot/CMakeLists.txt --

include_directories( . )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library( arcplot STATIC )

target_link_libraries(arcplot ${CONAN_LIBS})
target_link_libraries(arcplot ${Qt5Core_LIBRARIES} ${Qt5Widgets_LIBRARIES})

target_include_directories(arcplot PRIVATE ${CMAKE_CURRENT_LIST_DIR}/.. )

include( ${CMAKE_CURRENT_SOURCE_DIR}/Plots/CMakeLists.txt )


target_link_libraries( arcplot stdc++fs)
