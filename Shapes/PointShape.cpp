#include "PointShape.h"

PointShape::PointShape():Shape::Shape(),x{0},y{0}
{
}

PointShape::PointShape(float x, float y):Shape::Shape(),x{x},y{y}
{
}

PointShape PointShape::modifyTransform(Components::TransformComponent* transformComponent)
{
	return PointShape(this->x + transformComponent->posX, this->y + transformComponent->posY);
}
