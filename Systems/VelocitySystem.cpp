#include "VelocitySystem.h"

VelocitySystem::VelocitySystem() :System(TransformComponentId | VelocityComponentId)
{
	priorty = 10;
}

VelocitySystem::~VelocitySystem()
{
}

void VelocitySystem::update(Entity* entity, float deltaTime)
{
	Components::TransformComponent* transfomComponent = entity->GetComponent<Components::TransformComponent>();
	Components::VelocityComponent* velocityComponent = entity->GetComponent<Components::VelocityComponent>();

	transfomComponent->posX += velocityComponent->velX * deltaTime;
	transfomComponent->posY += velocityComponent->velY * deltaTime;
	transfomComponent->angle += velocityComponent->velA * deltaTime;
}
