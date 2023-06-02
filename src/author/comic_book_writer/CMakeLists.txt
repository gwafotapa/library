# target_sources(Sources PRIVATE comic_book_writer.cpp)
# string(REPLACE "src" "include" INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# # message(INCLUDE_DIR="${INCLUDE_DIR}")
# target_include_directories(Sources PUBLIC ${INCLUDE_DIR})

target_sources(library PRIVATE comic_book_writer.cpp)
string(REPLACE "src" "include" INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# message(INCLUDE_DIR="${INCLUDE_DIR}")
target_include_directories(library PUBLIC ${INCLUDE_DIR})

add_subdirectory(comic_book_writer_illustrator)
