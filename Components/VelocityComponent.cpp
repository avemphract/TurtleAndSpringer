#include "VelocityComponent.h"

Components::VelocityComponent* Components::VelocityComponent::setComponent(float velX, float velY, float velA)
{
	this->velX = velX;
	this->velY = velY;
	this->velA = velA;
	return this;
}

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