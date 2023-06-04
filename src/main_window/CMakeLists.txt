target_sources(Sources PRIVATE main_window.cpp)
string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(Sources PUBLIC ${HEADER_DIR}/main_window.h)
target_include_directories(Sources PUBLIC ${HEADER_DIR})

add_subdirectory(add_widget)
add_subdirectory(search_widget)
