#include "RectangleShape.h"
#include "Shape.h"

RectangleShape::RectangleShape():Shape(),x{0},y{0},width{0},height{0}
{
}

RectangleShape::RectangleShape(float x, float y, float width, float height): Shape(), x{x}, y{y}, width{width}, height{height}
{
}

RectangleShape::RectangleShape(RectangleShape* rec) : Shape(), x{ rec->x }, y{ rec->y }, width{ rec->width }, height{ rec->height }
{

}

RectangleShape* RectangleShape::modifyTransform(Components::TransformComponent* transformComponent)
{
	return new RectangleShape(this->x + transformComponent->posX, this->y + transformComponent->posY, this->width, this->height);
}
