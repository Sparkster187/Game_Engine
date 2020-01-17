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
src/Big_Boy/Core.cpp
src/Big_Boy/Geppy.h
src/Big_Boy/Component.cpp
src/Big_Boy/Entity.cpp
src/Big_Boy/Camera.h
src/Big_Boy/Transform.cpp
)

if(MSVC)
  target_link_libraries(Big_Boy SDL2 rend)
else()
  target_link_libraries(Big_Boy SDL2 rend)
endif()

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Buffer.h
  src/rend/Context.h
  src/rend/Exception.h
  src/rend/mathutil.h
  src/rend/rend.h
  src/rend/RenderTexture.h
  src/rend/Shader.h
  src/rend/Texture.h
  src/rend/TextureAdapter.h
  src/rend/Util.cpp
  src/rend/Util.h
  src/rend/Mesh.h
  src/rend/stb_image.h
)

if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

target_link_libraries(Big_Boy SDL2 opengl32 glew32)

add_executable(Game
src/Game/main.cpp
)
target_link_libraries(Game Big_Boy)
