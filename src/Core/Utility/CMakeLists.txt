# -- Utility/CMakeLists.txt --

set( Utility_SRC 
    	${CMAKE_CURRENT_LIST_DIR}/Result.cpp
    	${CMAKE_CURRENT_LIST_DIR}/StringUtility.cpp
    )

target_sources( arclib PUBLIC ${Utility_SRC} )
