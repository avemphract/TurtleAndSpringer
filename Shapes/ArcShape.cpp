#include "ArcShape.h"

ArcShape::ArcShape():Shape::Shape(), cenX{0}, cenY{0}, startAngle{0}, lengthAngle{0}, radius{0}
{
}

ArcShape::ArcShape(float cenX, float cenY, float startAngle, float lengthAngle, float radius):Shape::Shape(), cenX{ cenX }, cenY{ cenY }, startAngle{ startAngle }, lengthAngle{ lengthAngle }, radius{ radius }
{
}

ArcShape ArcShape::modifyTransform(Components::TransformComponent* transformComponent)
{
	return ArcShape(this->cenX + transformComponent->posX, this->cenY + transformComponent->posY, this->startAngle + transformComponent->angle, this->lengthAngle, this->radius);
}
