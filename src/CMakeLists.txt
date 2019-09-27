# -- Arcturus root CMakeLists.txt --

cmake_minimum_required( VERSION 3.8 FATAL_ERROR )
#set (CMAKE_USER_MAKE_RULES_OVERRIDE "${CMAKE_CURRENT_LIST_DIR}/CompilerOptions.cmake")

add_definitions("-std=c++17")
#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)


#set( BUILD_TESTING ON )
#set( ENABLE_PROFILING false )
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()

set( CMAKE_CXX_STANDARD 17 )
#set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED ON)
set( CMAKE_CXX_EXTENSIONS ON )
#set( CMAKE_CXX_COMPILER ${CXX} )
#set( CMAKE_BUILD_TYPE RelWithDebInfo )
set( CMAKE_BUILD_TYPE Debug )
project( Arcturus VERSION 0.1 LANGUAGES CXX )

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
#add_definitions( -DUNICODE )
#add_definitions( -D_UNICODE )

#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#    add_compile_options(-fdiagnostics-color=always)
#elseif( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    add_compile_options(-fcolor-diagnostics)
#endif()

#if (MSVC_VERSION GREATER_EQUAL "1900")
#    include(CheckCXXCompilerFlag)
#    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
#    if (_cpp_latest_flag_supported)
#        add_compile_options("/std:c++latest")
#		add_definitions( -D_MSVC_LANG=201703 )
#    endif()
#endif()



### Detect build platform ###
if( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
    set( PLATFORM_LINUX TRUE )
    message( STATUS "Linux platform detected." )
elseif( ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin" )
    set( PLATFORM_APPLE TRUE )
    message( STATUS "Apple platform detected." )
elseif( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
    set( PLATFORM_WIN64 TRUE )
    message( STATUS "Windows platform detected." )
else( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
    message( FATAL_ERROR "Failed to determine platform." )
endif( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )

set( WARNING_FLAGS
    "-pedantic "
    "-Wall "
    "-Werror=return-type "
    "-Wextra "
    "-Wmissing-field-initializers "
    "-Wno-predefined-identifier-outside-function "
#    "-Wno-missing-braces "
    )

set( MISC_FLAGS
    "-Wpedantic "
    "-fsanitize=undefined "
    "-fcolor-diagnostics "
    "-frtti "
#    "-fPIE "
#    "-fsanitize-trap=all "
#    "-fno-exceptions "
#    "-O2 -fprofile-instr-generate -fcoverage-mapping -fprofile-arcs -ftest-coverage "
#    "-O2 "
    )

#set( CMAKE_CXX_FLAGS
#    "-Wall -Werror=return-type -Wextra -Werror=return-type -Wextra -stdlib=libstdc++ -O2"
#    )

string(CONCAT WARNING_FLAGS_STR ${WARNING_FLAGS})
string(CONCAT MISC_FLAGS_STR ${MISC_FLAGS})

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MISC_FLAGS_STR}${WARNING_FLAGS_STR}" )
#set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
# set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${MISC_FLAGS} ${WARNING_FLAGS} )
#set( DEBUG_FLAGS )


#set( CMAKE_CXX_COMPILER_LAUNCHER pump ccache )
#set( CCACHE_PREFIX pump distcc )
#set( CMAKE_CXX_COMPILER_LAUNCHER ccache )


#set( CMAKE_CXX_COMPILER_LAUNCHER pump distcc )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Arcturus_SOURCE_DIR}/../targets/Debug )
set( CMAKE_MODULE_PATH ${Arcturus_SOURCE_DIR}/cmake/modules )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

#set( OpenCV_INSTALL_PATH "C:/usr/local/lib/opencv")

###
#if( ${PLATFORM_WIN64} )
#	set( CMAKE_PRE )
#	set( GLEW_INCLUDE_DIR "C:/usr/local/include/GL/" )
#	set( GLEW_LIBRARY "C:/usr/local/lib/glew32s.lib" )
#	set( FREETYPE_INCLUDE_DIRS "C:/usr/local/include/freetype2" )
#	set( FREETYPE_LIBRARY "C:/usr/local/lib/freetype.lib" )
#	set( ZLIB_ROOT "C:/usr/local/bin/")
#	set( ZLIB_INCLUDE_DIR "C:/usr/local/zlib")
#	set( ZLIB_LIBRARY "C:/usr/local/lib/zlib.lib")
#	set( ZLIB_INCLUDE_DIR "C:")
#	set( ZLIB_INCLUDE_DIR "C:/usr/local/include/zlib")
#	set( PNG_PNG_INCLUDE_DIR "C:/usr/local/include/libpng16")
#	set( PNG_LIBRARY "C:/usr/local/lib/libpng16.lib")
#	set( OpenCV_DIR "C:/usr/local/lib/opencv")
#	set( png++_INCLUDE_DIR "C:/usr/local/include/png++")
#	set( BOOST_ROOT "C:/Program Files (x86)/boost_1_68_0/" )
#endif()

#find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

#find_package(Qt5 COMPONENTS Core REQUIRED)
#find_package(Qt5 COMPONENTS Widgets REQUIRED)

### Common dependencies ###
#find_package( Freetype REQUIRED )
#find_package( GLEW REQUIRED )
#if( NOT GLEW_FOUND )
#	message( FATAL_ERROR "Can not find glew!" )
#else( NOT GLEW_FOUND )
#	message( "glews= ${GLEW_INCLUDE_DIRS}" )
#endif()

#find_package( HarfBuzz REQUIRED )
#find_package( OpenGL REQUIRED )
#find_package( Catch2 REQUIRED )
#find_package( PNG REQUIRED )
#find_package( png++ REQUIRED )
#find_package( ZLIB REQUIRED)
#find_package( OpenCV REQUIRED )

### Linux library dependencies ###
if( ${PLATFORM_LINUX} )
    #find_package( LibInput REQUIRED )
    #find_package( PNG REQUIRED )
    #    find_package( png++ REQUIRED )
    #    find_package( X11 REQUIRED )
elseif( ${PLATFORM_OSX} )
    #find_package( PNG REQUIRED )
    #find_package( png++ REQUIRED )
    #find_package( SDL2 REQUIRED )
elseif( ${PLATFORM_WIN64} )
endif()

find_package( Boost 1.69 REQUIRED )
#find_package( Gperftools REQUIRED )

add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/playground )
add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/Core )
add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/Plot )
add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/Math )
add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/GUI )
#add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/tests )

if( MSVC )
	target_compile_options( arclib PRIVATE "/MP")
	target_compile_options( arcplot PRIVATE "/MP")
	target_compile_options( arcmath PRIVATE "/MP")
	target_compile_options( playground PRIVATE "/MP")
endif()

#add_subdirectory( ./tests )
