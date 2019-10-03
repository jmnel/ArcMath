# -- playground - CMakeLists.txt --

#include_directories(${Boost_INCLUDE_DIRS})

#if(${PLATFORM_WIN64})
#elseif(${PLATFORM_LINUX})
#    add_executable( playground Main.cpp )
#endif()

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable( playground Main.cpp )


#set_property(TARGET playground PROPERTY CXX_STANDARD 17)
#set_property(TARGET playground PROPERTY CXX_STANDARD_REQUIRED ON)

#include_directories( "../arclib" )

target_link_libraries(playground PRIVATE arcmath)
#target_link_libraries(playground PRIVATE arcgui)
#target_link_libraries(playground PRIVATE arcplot)

target_include_directories(playground PRIVATE ${CMAKE_CURRENT_LIST_DIR}/.. )

#find_package(Qt5 COMPONENTS Core REQUIRED)
#find_package(Qt5 COMPONENTS Widgets REQUIRED)

#target_link_libraries(playground PRIVATE ${Qt5Core_LIBRARIES})
#target_link_libraries(playground PRIVATE ${Qt5Widgets_LIBRARIES})

#target_include_directories(playground SYSTEM PUBLIC "C:/usr/local/include/" )

#file(GLOB SOURCES *.cpp)

#target_link_libraries( arcgame ${GLEW_LIBRARIES})
#target_link_libraries( arcgame ${OPENGL_gl_LIBRARY} )
#target_link_libraries( playground arclib )



#target_link_libraries( arcgame ${FREETYPE_LIBRARIES} )
#target_link_libraries( arcgame ${HarfBuzz_LIBRARIES} )

#target_include_directories( arcgame PUBLIC "C:/usr/local/include/harfbuzz")
#target_include_directories( arcgame PUBLIC "C:/usr/local/include/freetype2")

#add_custom_command(
    #TARGET arcgame POST_BUILD
    #COMMAND ${CMAKE_COMMAND} -E copy
    #${CMAKE_SOURCE_DIR}/../build/compile_commands.json
    #${CMAKE_SOURCE_DIR}/../compile_commands.json )
