#pragma once
#ifndef _MESH_RENDERER_H_
#define _MESH_RENDERER_H_

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <memory>
#include <exception>

class MeshRenderer
{
public:
	GLuint programId;
	GLuint vaoId;
	GLuint vboId;
	GLuint window;

	void Init();
	int Run();
private:
	void onDisplay();
	std::weak_ptr<Mesh> mesh;
};

#endif // !_MESH_RENDERER_H_

