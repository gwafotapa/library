cmake_minimum_required(VERSION 3.25)
project(library)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_PREFIX_PATH "/home/guillaume/programs/qt/6.5.1/gcc_64/lib/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -Wpedantic")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
# set(BUILD_GMOCK OFF)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   # Specify the commit you depend on and update it regularly.
#   URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

find_package(Qt6 COMPONENTS Core Gui Widgets Sql REQUIRED)

add_executable(Library)
target_link_libraries(Library PRIVATE Sources)

add_library(Sources STATIC)
target_link_libraries(Sources Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Sql)

add_subdirectory(src)

# enable_testing ()
# add_subdirectory (test)
