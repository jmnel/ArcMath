# -- arclib/CMakeLists.txt --

include_directories( . )

#if( ${PLATFORM_LINUX} )
#    include_directories( ${LIBINPUT_INCLUDE_DIRS} )
#    include_directories( ${png++_INCLUDE_DIRS} )
#endif()

#include_directories( ${PNG_PNG_INCLUDE_DIR} )
#include_directories( ${png++_INCLUDE_DIRS})


#include_directories( ${FREETYPE_INCLUDE_DIRS} )
#include_directories( ${HarfBuzz_INCLUDE_DIRS} )

include_directories( ${Boost_INCLUDE_DIRS} )

add_library( arclib STATIC )

#set_property(TARGET arclib PROPERTY CXX_STANDARD 17 )

#target_link_libraries( arclib ${Boost_LIBRARIES} )
#target_link_libraries( arclib Boost::optional )

#message(${Boost_INCLUDE_DIR})

target_link_libraries(arclib ${CONAN_LIBS})

target_include_directories(arclib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} )
#target_include_directories(arclib SYSTEM PUBLIC "/usr/local/include/GL" )
#target_include_directories(arclib SYSTEM PUBLIC "C:/usr/local/include/" )
#target_include_directories( arclib SYSTEM PUBLIC ${FREETYPE_INCLUDE_DIRS} )

#target_link_libraries( arclib ${OPENGL_gl_LIBRARY} )
#target_link_libraries( arclib ${X11_Xinput_LIB} )
#target_link_libraries( arclib ${LIBINPUT_LIBRARY} )
#target_link_libraries( arclib ${FREETYPE_LIBRARIES} )
#target_link_libraries( arclib ${HarfBuzz_LIBRARIES} )
#target_include_directories( arclib PUBLIC "C:/usr/local/include/harfbuzz")
#target_include_directories( arclib PUBLIC "C:/usr/local/include/freetype2")

#target_link_libraries( arclib ${GLEW_LIBRARIES} )
#include_directories( ${GLEW_INCLUDE_DIRS} )

include( ${CMAKE_CURRENT_SOURCE_DIR}/Debug/CMakeLists.txt )
include( ${CMAKE_CURRENT_SOURCE_DIR}/Utility/CMakeLists.txt )


#include_directories( ${GPERFTOOLS_LIBRARIES} )

#set( DEBUG_FLAGS "-Wall" "-Wextra" "-O3" )
#target_compile_options( arcgame PUBLIC ${DEBUG_FLAGS} )
#target_compile_options( arcgame PUBLIC ${DEBUG_FLAGS} )
#target_compile_options( arcgame PUBLIC ${CMAKE_CXX_FLAGS} )

#target_include_directories( arclib PUBLIC . )

#if( ${PLATFORM_LINUX} )
#    target_link_libraries( arclib ${X11_LIBRARIES} )
#    target_link_libraries( arclib ${LIBINPUT_LIBRARY} )
#    target_link_libraries( arclib ${X11_Xinput_LIB} )
#    target_link_libraries( arclib ${LIBINPUT_LIBRARY} )
#endif()

target_link_libraries( arclib stdc++fs)


#target_link_libraries( arclib ${FREETYPE_LIBRARIES} )
#target_link_libraries( arclib ${HarfBuzz_LIBRARIES} )


#target_link_libraries( arclib ${PNG_LIBRARIES} )
#target_link_libraries( arclib ${png++_LIBRARIES} )

#target_link_libraries( arclib ${GPERFTOOLS_LIBRARIES} )

#add_custom_command(
    #TARGET arclib POST_BUILD
    #COMMAND ${CMAKE_COMMAND} -E copy
    #${CMAKE_SOURCE_DIR}/../build/compile_commands.json
    #${CMAKE_SOURCE_DIR}/../compile_commands.json )

