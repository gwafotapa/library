# target_sources(Sources PRIVATE author.cpp)
# string(REPLACE "src" "include" INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# # message(INCLUDE_DIR="${INCLUDE_DIR}")
# target_include_directories(Sources PUBLIC ${INCLUDE_DIR})

target_sources(library PRIVATE author.cpp)
string(REPLACE "src" "include" INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# message(INCLUDE_DIR="${INCLUDE_DIR}")
target_include_directories(library PUBLIC ${INCLUDE_DIR})

add_subdirectory(writer)
add_subdirectory(comic_book_writer)
add_subdirectory(illustrator)
add_subdirectory(comic_book_writer_illustrator)
