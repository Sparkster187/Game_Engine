#include <cstdlib>
#include <memory>
#include <list>
#include "Big_Boy\Geppy.h"

int main()
{
	std::shared_ptr<Core> core = Core::Initialize(); ///< core contains the 

	std::shared_ptr<Entity> gameObject = core->addEntity(); ///< gameObject becomes an entity
	std::shared_ptr<MeshRenderer> triangle = gameObject->addComponent<MeshRenderer>(); ///< triangle uses gameObject to access Mesh Renderer component
	std::shared_ptr<Transform> transform = gameObject->addComponent<Transform>(); ///< transform uses gameObject to access the Transform component

	std::shared_ptr<Entity> mainCamera = core->addEntity(); ///< mainCamera becomes an entity
	std::shared_ptr<Camera> camera = mainCamera->addComponent<Camera>(); ///< camera uses mainCamera to get the Camera component
	std::shared_ptr<Transform> cameraTransform = mainCamera->addComponent<Transform>(); ///< cameraTransform uses mainCamera to access the transform component
	mainCamera->getComponent<Transform>()->SetLocalPosition(glm::vec3(0.0f, 0.0f, 10.0f)); ///< mainCamera uses transform component to set the current position of the camera
	/**
	*Loads in texture and object files
	*/
	triangle->loadObject("../samples/curuthers/curuthers.obj"); ///< calls loadObject function to load the object file 
	triangle->loadTexture("../samples/curuthers/Whiskers_diffuse.png"); ///< calls loadTexture function to load the texture file 
	
	core->run(); ///< tells the program to run

return 0;
}