cmake_minimum_required(VERSION 2.6)
project(Game_Engine)

include_directories(src)

add_library(Big_Boy
src/Big_Boy/dummy.cpp
src/Big_Boy/Component.h
src/Big_Boy/Core.h
src/Big_Boy/Entity.h
src/Big_Boy/Environment.h
src/Big_Boy/Keyboard.h
)
target_link_libraries(Big_Boy SDL2 opengl32 glew32)

add_executable(Game
src/Game/main.cpp
)
target_link_libraries(Game Big_Boy)
