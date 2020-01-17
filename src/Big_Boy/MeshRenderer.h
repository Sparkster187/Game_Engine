#include <rend/rend.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <memory>
#include <exception>
#include "Material.h"
#include "Component.h"

class MeshRenderer : public Component
{
	friend class Core;
	friend class Entity;

private:
	GLuint programId;
	GLuint vaoId;
	GLuint vboId;

	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Mesh> shape;

	//std::weak_ptr<Mesh> mesh;
	std::shared_ptr<Material> getMaterial;

public:

	void loadObject(const char* path);
	void loadTexture(const char* path);
	void onInit();
	void onDisplay();


};


