#include "TransformComponent.h"

Components::TransformComponent* Components::TransformComponent::setComponent(float posX, float posY, float angle)
{
	this->posX = posX;
	this->posY = posY;
	this->angle = angle;
	return this;
}

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