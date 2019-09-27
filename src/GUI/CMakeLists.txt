# -- GUI/CMakeLists.txt --

include_directories( . )


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(arcgui STATIC)

#target_link_libraries(arcgui ${CONAN_LIBS})

target_include_directories(arcgui PRIVATE ${CMAKE_CURRENT_LIST_DIR}/.. )


include( ${CMAKE_CURRENT_LIST_DIR}/Widgets/CMakeLists.txt )
include( ${CMAKE_CURRENT_LIST_DIR}/Application/CMakeLists.txt )
include( ${CMAKE_CURRENT_LIST_DIR}/Notebook/CMakeLists.txt )
include( ${CMAKE_CURRENT_LIST_DIR}/ObjectModel/CMakeLists.txt )

#target_include_directories(arcgui 
#    PUBLIC 
#    ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
#target_include_directories( arcgui PRIVATE
#)
target_link_libraries(arcgui ${Qt5Core_LIBRARIES} ${Qt5Widgets_LIBRARIES})
#target_link_libraries(arcgui INTERFACE ${Qt5Widgets_LIBRARIES})

#target_link_libraries( arcgui stdc++fs)
