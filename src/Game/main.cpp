#include <cstdlib>
#include <memory>
#include <list>
#include "Big_Boy\Geppy.h"

int main()
{
	std::shared_ptr<Core> core = Core::Initialize();

	std::shared_ptr<Entity> gameObject = core->addEntity();

	std::shared_ptr<MeshRenderer> triangle = gameObject->addComponent<MeshRenderer>();
	
	triangle->loadObject("samples\curuthers\curuthers.obj");
	triangle->loadTexture("samples\curuthers\Whiskers_diffuse.png");

	core->run();

return 0;
}