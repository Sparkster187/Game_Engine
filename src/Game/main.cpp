#include <cstdlib>
#include <memory>
#include <list>
#include "Big_Boy\Geppy.h"

int main()
{
	std::shared_ptr<Core> core = Core::Initialize();

	std::shared_ptr<Entity> gameObject = core->addEntity();

	std::shared_ptr<Component> component = gameObject->addComponent<Component>();

	std::weak_ptr<MeshRenderer> triangle = gameObject->addComponent<MeshRenderer>();

	core->run();

return 0;
}