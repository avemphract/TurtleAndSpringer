#include"Shape.h"
#include"../Components/TransformComponent.h"

#pragma once
class PointShape: public Shape{
    public:
        float x;
        float y;
        PointShape();
        PointShape(float x, float y);
        PointShape* modifyTransform(Components::TransformComponent* transformComponent);
};