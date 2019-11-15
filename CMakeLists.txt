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
src/Big_Boy/Resources.h
src/Big_Boy/Material.h
src/Big_Boy/Transform.h
src/Big_Boy/MaterialAttribute.h
src/Big_Boy/Screen.h
src/Big_Boy/MeshRenderer.h
src/Big_Boy/MeshRenderer.cpp
)
target_link_libraries(Big_Boy SDL2 opengl32 glew32)

add_executable(Game
src/Game/main.cpp
)
target_link_libraries(Game Big_Boy)
