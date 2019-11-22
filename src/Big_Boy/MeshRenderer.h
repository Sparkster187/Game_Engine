#pragma once
#ifndef _MESH_RENDERER_H_
#define _MESH_RENDERER_H_

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <memory>
#include <exception>
#include "Material.h"

class MeshRenderer
{
public:

	void Init();
	void onDisplay();
private:
	GLuint programId;
	GLuint vaoId;
	GLuint vboId;
	GLuint window;

	//std::weak_ptr<Mesh> mesh;
	std::shared_ptr<Material> getMaterial;
};

#endif // !_MESH_RENDERER_H_

