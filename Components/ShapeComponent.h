#include "Component.h"
#include "../Shapes/Shape.h"
#define ShapeComponentId 0b100

namespace Components{
    class ShapeComponent: public Component{
        public:
        Shape* shape;
        int getComponentId();
        void resetComponent();
        ShapeComponent();
        ~ShapeComponent();
    };
}