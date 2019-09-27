# -------------------- #
# Geometry/CMakeLists.txt #
# -------------------- #

set( Geometry_SRC 
    ${CMAKE_CURRENT_LIST_DIR}/Shapes/Arc2d.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/Shapes/Circle2d.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/Shapes/Line.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/Shapes/Plane.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/Shapes/Ray.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/Shapes/Sphere.cpp 
    )

target_sources( arcmath PUBLIC ${Geometry_SRC} )
