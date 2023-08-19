#include "TransformComponent.h"

int Components::TransformComponent::getComponentId()
{
	return TransformComponentId;
}

void Components::TransformComponent::resetComponent()
{
	posX = 0;
	posY = 0;
	angle = 0;
}

Components::TransformComponent::TransformComponent():posX{0},posY{0},angle{0}
{
}