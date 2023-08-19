#include "ShapeComponent.h"

Components::ShapeComponent* Components::ShapeComponent::setComponent(Shape* shape)
{
    this->shape = shape;
    return this;
}

int Components::ShapeComponent::getComponentId()
{
    return ShapeComponentId;
}

void Components::ShapeComponent::resetComponent()
{
}

Components::ShapeComponent::ShapeComponent()
{
}
