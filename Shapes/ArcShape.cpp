#include "ArcShape.h"

#define M_PI           3.14159265358979323846  /* pi */
ArcShape::ArcShape():Shape::Shape(), cenX{0}, cenY{0}, startAngle{0}, lengthAngle{0}, radius{0}
{
}

ArcShape::ArcShape(float cenX, float cenY, float startAngle, float lengthAngle, float radius):Shape::Shape(), cenX{ cenX }, cenY{ cenY }, startAngle{ startAngle }, lengthAngle{ lengthAngle }, radius{ radius }
{
}

ArcShape* ArcShape::modifyTransform(Components::TransformComponent* transformComponent)
{
	auto angle = this->startAngle + transformComponent->angle;
	angle = angle >= 2 * M_PI ? angle - 2 * M_PI : angle;
	return new ArcShape(this->cenX + transformComponent->posX, this->cenY + transformComponent->posY, (angle), this->lengthAngle, this->radius);
}
