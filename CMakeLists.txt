cmake_minimum_required(VERSION 2.6)
project(Game_Engine)

add_library(Big_Boy
src/Big_Boy/dummy.cpp
)
target_link_libraries(Big_Boy SDL2 opengl32 glew32)

add_executable(Game
src/Game/main.cpp
)
target_link_libraries(Game Big_Boy)
