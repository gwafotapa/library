cmake_minimum_required(VERSION 3.25)
project(library)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_PREFIX_PATH "C:/Users/Administrateur/SE23-188121-POEI-Python-C-/qt/5.15.2/mingw81_64")
set(CMAKE_PREFIX_PATH "/home/guillaume/programs/qt/6.5.1/gcc_64/lib/cmake/Qt6")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -Wextra -Wpedantic")
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

add_library(Sources author/author.h author/author.cpp book/book.h book/book.cpp mainwindow/mainwindow.cpp mainwindow/mainwindow.h mainwindow/mainwindow.ui formwidget/formwidget.cpp formwidget/formwidget.h formwidget/formwidget.ui tablewidget/tablewidget.cpp tablewidget/tablewidget.h tablewidget/tablewidget.ui buttonswidget/buttonswidget.cpp buttonswidget/buttonswidget.h buttonswidget/buttonswidget.ui messagewidget/messagewidget.cpp messagewidget/messagewidget.h messagewidget/messagewidget.ui datamodel/datamodel.h datamodel/datamodel.cpp searchwidget/searchwidget.cpp searchwidget/searchwidget.h searchwidget/searchwidget.ui add_widget/add_widget.cpp add_widget/add_widget.h add_widget/add_widget.ui add_std_book_widget/add_std_book_widget.h add_std_book_widget/add_std_book_widget.cpp add_std_book_widget/add_std_book_widget.ui add_comic_book_widget/add_comic_book_widget.h add_comic_book_widget/add_comic_book_widget.cpp add_comic_book_widget/add_comic_book_widget.ui add_author_widget/add_author_widget.h add_author_widget/add_author_widget.cpp add_author_widget/add_author_widget.ui)
target_link_libraries(Sources
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
  Qt6::Sql
)

add_executable(library main.cpp)
target_link_libraries (library Sources)
# target_link_libraries(library
#   Qt6::Core
#   Qt6::Gui
#   Qt6::Widgets
#   Qt6::Sql
# )

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
