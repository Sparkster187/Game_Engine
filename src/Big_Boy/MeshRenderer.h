

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <memory>
#include <exception>
#include "Material.h"
#include "Component.h"

class MeshRenderer : public Component
{
public:

	void onInit();
	void onDisplay();
private:
	GLuint programId;
	GLuint vaoId;
	GLuint vboId;
	SDL_Window * window;
	std::shared_ptr<rend::Shader> shader;

	//std::weak_ptr<Mesh> mesh;
	std::shared_ptr<Material> getMaterial;
};


