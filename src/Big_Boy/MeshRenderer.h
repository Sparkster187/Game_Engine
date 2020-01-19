#include <rend/rend.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <memory>
#include <exception>
#include "Material.h"
#include "Component.h"

class MeshRenderer : public Component ///< Inherits from Component class
{
	friend class Core;
	friend class Entity;

private:
	GLuint programId;
	GLuint vaoId; ///< Vertex Array Object 
	GLuint vboId; ///< Vertex Buffer Object

	std::shared_ptr<rend::Shader> shader; ///< accesses the shader class in rend and makes a shared pointer using it allowing the pointer to have information on both classes
	std::shared_ptr<rend::Mesh> shape; 

	//std::weak_ptr<Mesh> mesh;
	std::shared_ptr<Material> getMaterial;

public:

	void loadObject(const char* path); ///< function for loading the object mesh from the file in the path given
	void loadTexture(const char* path); ///< function for loading the texture from the file in the path given
	void onInit();
	void onDisplay();


};


