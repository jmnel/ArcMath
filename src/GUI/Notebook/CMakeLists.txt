# -------------------- #
# Notebook/CMakeLists.txt #
# -------------------- #

set( Notebook_SRC 
    ${CMAKE_CURRENT_LIST_DIR}/Notebook.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/NotebookModel.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/NotebookView.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/NotebookController.cpp 
    )

target_sources( arcgui PUBLIC ${Notebook_SRC} )
