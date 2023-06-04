target_sources(Sources PRIVATE data_model.cpp)
string(REPLACE "src" "include" HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(Sources PUBLIC ${HEADER_DIR}/data_model.h)
target_include_directories(Sources PUBLIC ${HEADER_DIR})
