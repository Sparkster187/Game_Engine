#include <cstdlib>
#include <memory>
#include "Big_Boy/Core.h"
int main()
{
	std::shared_ptr<Core> core = Core::Initialize();

	std::shared_ptr<Entity> gameObject = core->addEntity();

	
return 0;
}