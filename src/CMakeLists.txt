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
set( CMAKE_BUILD_TYPE RelWithDebInfo )
#set( CMAKE_BUILD_TYPE Debug )
project( ArctMath VERSION 0.1 LANGUAGES CXX )

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

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
#    "-Wpedantic "
    "-fsanitize=undefined,address,leak "
    "-fcolor-diagnostics "
    "-fdiagnostics-show-template-tree "
#    "-fno-elide-type "
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

#set( WARNING_FLAGS
#    -pedantic
#    -Wall
#    -Werror=return-type
#    -Wextra
#    -Wmissing-field-initializers
#    -Wno-predefined-identifier-outside-function
#    -Wno-missing-braces
#    )

#set( MISC_FLAGS
#    -fsanitize=address,undefined
#    -fcolor-diagnostics
#    -frtti
#    -fPIE
#    -fsanitize-trap=all
#    -fno-exceptions
#    -O2 -fprofile-instr-generate -fcoverage-mapping -fprofile-arcs -ftest-coverage
#    "-O2 "
#    )


#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#    add_compile_options(-fdiagnostics-color=always)
#elseif( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    add_compile_options(${WARNING_FLAGS};${MISC_FLAGS})
#    string(REPLACE ";" "\n  " L2 "${WARNING_FLAGS}${MISC_FLAGS}")
#    message( "Clang detected. Setting compile flags: \n  ${L2}\n")
#endif()

#set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
# set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${MISC_FLAGS} ${WARNING_FLAGS} )
#set( DEBUG_FLAGS )


#set( CMAKE_CXX_COMPILER_LAUNCHER pump distcc )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ArcMath_SOURCE_DIR}/../targets/Debug )
set( CMAKE_MODULE_PATH ${ArcMath_SOURCE_DIR}/cmake/modules )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

#set( OpenCV_INSTALL_PATH "C:/usr/local/lib/opencv")


#find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

#find_package(Qt5 COMPONENTS Core REQUIRED)
#find_package(Qt5 COMPONENTS Widgets REQUIRED)



#find_program(CCACHE_PROGRAM ccache)
#if(CCACHE_PROGRAM)
#    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
#    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
#endif()


find_package( Boost 1.69 REQUIRED )
#find_package( Gperftools REQUIRED )

add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/playground )
add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/Core )
#add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/Plot )
add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/Math )
#add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/GUI )
#add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/tests )



