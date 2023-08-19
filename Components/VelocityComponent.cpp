#include "VelocityComponent.h"

int Components::VelocityComponent::getComponentId() {
	return VelocityComponentId;
}

void Components::VelocityComponent::resetComponent()
{
	this->velX = 0;
	this->velY = 0;
	this->velA = 0;
}

Components::VelocityComponent::VelocityComponent():velX{0}, velY{0}, velA{0}
{
}