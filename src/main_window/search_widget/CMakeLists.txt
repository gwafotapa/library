target_sources(Sources PRIVATE search_widget.cpp)
string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(Sources PUBLIC ${HEADER_DIR}/search_widget.h)
target_include_directories(Sources PUBLIC ${HEADER_DIR})
