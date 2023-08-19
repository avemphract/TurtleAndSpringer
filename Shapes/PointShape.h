#include"Shape.h"
#include"../Components/TransformComponent.h"

class PointShape: public Shape{
    public:
        float x;
        float y;
        PointShape();
        PointShape(float x, float y);
        PointShape modifyTransform(Components::TransformComponent* transformComponent);
};