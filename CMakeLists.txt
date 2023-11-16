cmake_minimum_required(VERSION 3.27)
project(squareEater)

set(CMAKE_CXX_STANDARD 17)
add_executable(squareEater main.cpp
        MovableRectangle.cpp
        MovableRectangle.h
        Brick.cpp
        Brick.h
        BricksSpawner.cpp
        BricksSpawner.h)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(squareEater PUBLIC sfml-system sfml-window sfml-graphics)
install(FILES font.otf DESTINATION .)