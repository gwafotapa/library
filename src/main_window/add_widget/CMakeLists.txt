# target_sources(Sources PRIVATE add_widget.cpp)
# string(REPLACE "src" "include" INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# # message(INCLUDE_DIR="${INCLUDE_DIR}")
# target_include_directories(Sources PUBLIC ${INCLUDE_DIR})

target_sources(library PRIVATE add_widget.cpp)
string(REPLACE "src" "include" INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# message(INCLUDE_DIR="${INCLUDE_DIR}")
target_sources(library PUBLIC ${INCLUDE_DIR}/add_widget.h)
target_include_directories(library PUBLIC ${INCLUDE_DIR})

add_subdirectory(add_book_widget)
add_subdirectory(add_author_widget)
