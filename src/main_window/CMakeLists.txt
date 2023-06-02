# target_sources(Sources PRIVATE main_window.cpp)
# string(REPLACE "src" "include" INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}) # TODO: rename INCLUDE_DIR
# message(INCLUDE_DIR="${INCLUDE_DIR}")
# target_include_directories(Sources PUBLIC ${INCLUDE_DIR})

target_sources(library PRIVATE main_window.cpp)
string(REPLACE "src" "include" INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}) # TODO: rename INCLUDE_DIR
# message(INCLUDE_DIR="${INCLUDE_DIR}")
target_sources(library PUBLIC ${INCLUDE_DIR}/main_window.h)
target_include_directories(library PUBLIC ${INCLUDE_DIR})

add_subdirectory(add_widget)
add_subdirectory(search_widget)
add_subdirectory(data_model)
