cmake_minimum_required(VERSION 3.25)
project(square-eater)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} main.cpp
        Brick.cpp
        Brick.h
        BricksSpawner.cpp
        BricksSpawner.h)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-system sfml-window sfml-graphics)

install(FILES font.otf DESTINATION ${CMAKE_INSTALL_PREFIX})
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release)