#include "Shape.h"
#pragma once
class RectangleShape: public Shape
{
private:
    /* data */
public:
    float x;
    float y;
    float width;
    float height;


    RectangleShape();
    RectangleShape(float x, float y, float width, float height);
    RectangleShape* modifyTransform(Components::TransformComponent* transformComponent);
};