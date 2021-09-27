cmake_minimum_required(VERSION 3.7)
project(cligraph C)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CURSES_NEED_NCURSES TRUE)

find_package(Curses REQUIRED)
find_library(MENU_LIBRARY menu)

include_directories(cligraph ${CURSES_INCLUDE_DIRS})

add_executable(cligraph
  src/main.c
  src/cord.c
  src/bstrlib/bstrlib.c)

target_link_libraries(cligraph ${CURSES_LIBRARIES} ${MENU_LIBRARY} )
