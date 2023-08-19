#include "Shape.h"
#include"../Components/TransformComponent.h"

class ArcShape: public Shape{
    public:
        float cenX;
        float cenY;
        float startAngle;
        float lengthAngle;
        float radius;
        
        ArcShape();
        ArcShape(float cenX, float cenY, float startAngle, float lengthAngle, float radius);
        ArcShape* modifyTransform(Components::TransformComponent* transformComponent);
};