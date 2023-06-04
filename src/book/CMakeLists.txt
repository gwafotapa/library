# target_sources(Sources PRIVATE book.cpp)
# string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# # message(HEADER_DIR="${HEADER_DIR}")
# target_include_directories(Sources PUBLIC ${HEADER_DIR})

target_sources(library PRIVATE book.cpp)
string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# message(HEADER_DIR="${HEADER_DIR}")
target_include_directories(library PUBLIC ${HEADER_DIR})

add_subdirectory(comic_book)
add_subdirectory(standard_book)
