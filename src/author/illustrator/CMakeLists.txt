# target_sources(Sources PRIVATE illustrator.cpp)
# string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# # message(HEADER_DIR="${HEADER_DIR}")
# target_include_directories(Sources PUBLIC ${HEADER_DIR})

target_sources(library PRIVATE illustrator.cpp)
string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# message(HEADER_DIR="${HEADER_DIR}")
target_include_directories(library PUBLIC ${HEADER_DIR})
