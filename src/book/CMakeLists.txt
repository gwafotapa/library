target_sources(Sources PRIVATE book.cpp)
string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Sources PUBLIC ${HEADER_DIR})

add_subdirectory(comic_book)
add_subdirectory(standard_book)
