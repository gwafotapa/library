cmake_minimum_required(VERSION 3.25)
project(library)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_PREFIX_PATH "C:/Users/Administrateur/SE23-188121-POEI-Python-C-/qt/5.15.2/mingw81_64")
set(CMAKE_PREFIX_PATH "/home/guillaume/programs/qt/6.5.1/gcc_64/lib/cmake")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -Wextra -Wpedantic")
set(INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/include")
message(INCLUDE_DIRECTORIES=${INCLUDE_DIRECTORIES}) #TODO: remove
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

find_package(Qt6 COMPONENTS
  Core
  Gui
  Widgets
  Sql
  REQUIRED)

add_executable(library)

add_subdirectory(src)

# enable_testing ()
# add_subdirectory (test)


if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(DEBUG_SUFFIX)
  if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
    set(DEBUG_SUFFIX "d")
  endif ()
  set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
  if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
    set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
      set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    endif ()
  endif ()
  if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E make_directory
      "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy
      "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
      "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
  endif ()
  foreach (QT_LIB Core Gui Widgets Sql)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy
      "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
      "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
  endforeach (QT_LIB)
endif ()
