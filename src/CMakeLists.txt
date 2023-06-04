target_sources(library PRIVATE main.cpp)
# target_sources(library PRIVATE "${HEADER_DIRECTORIES}/main_window/main_window.h")
# target_include_directories(library PRIVATE "${HEADER_DIRECTORIES}/main_window")
# target_link_libraries(library PRIVATE Sources)
target_link_libraries(library
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
  Qt6::Sql
)

# add_library(Sources STATIC)
# # target_include_directories(Sources PUBLIC main_window)
# target_link_libraries(Sources
#   Qt6::Core
#   Qt6::Gui
#   Qt6::Widgets
#   Qt6::Sql
# )

add_subdirectory(main_window)
add_subdirectory(book)
add_subdirectory(author)
