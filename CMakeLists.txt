cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(project-3-minesweeper)

## If you want to link SFML statically
#set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
add_executable(project-3-minesweeper main.cpp Board.cpp Board.h Tile.cpp Tile.h Menu.cpp Menu.h Game.cpp Game.h Game.cpp Game.h TextureManager.cpp TextureManager.h)
target_link_libraries(project-3-minesweeper sfml-graphics sfml-audio)