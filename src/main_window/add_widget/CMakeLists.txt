# target_sources(Sources PRIVATE add_widget.cpp)
# string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# # message(HEADER_DIR="${HEADER_DIR}")
# target_include_directories(Sources PUBLIC ${HEADER_DIR})

target_sources(library PRIVATE add_widget.cpp)
string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# message(HEADER_DIR="${HEADER_DIR}")
target_sources(library PUBLIC ${HEADER_DIR}/add_widget.h)
target_include_directories(library PUBLIC ${HEADER_DIR})

add_subdirectory(add_book_widget)
add_subdirectory(add_author_widget)
