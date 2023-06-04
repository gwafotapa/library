target_sources(Sources PRIVATE illustrator.cpp)
string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Sources PUBLIC ${HEADER_DIR})
