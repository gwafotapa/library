# target_sources(Sources PRIVATE main_window.cpp)
# string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# message(HEADER_DIR="${HEADER_DIR}")
# target_include_directories(Sources PUBLIC ${HEADER_DIR})

target_sources(library PRIVATE main_window.cpp)
string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# message(HEADER_DIR="${HEADER_DIR}")
target_sources(library PUBLIC ${HEADER_DIR}/main_window.h)
target_include_directories(library PUBLIC ${HEADER_DIR})

add_subdirectory(add_widget)
add_subdirectory(search_widget)
add_subdirectory(data_model)
