#include "System.h"
#include "../Entity.h"
#include <list>

System::System(int requiredComponents):requiredComponents{requiredComponents}
{
}

void System::update(std::list<Entity*>& entities,  float deltaTime)
{
	for (Entity * ent : entities) {
		if ((ent->getComponentsBit() & requiredComponents) == requiredComponents) {
			update(ent, deltaTime);
		}
	}
}

bool System::operator<(const System& rhs)
{
	return this->priorty < rhs.priorty;
}
