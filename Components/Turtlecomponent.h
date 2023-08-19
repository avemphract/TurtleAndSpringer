#include "Component.h"
#pragma once
#define TurtleComponentId 0b1000
namespace Components{
    class TurtleComponent: public Component
    {
    private:
        /* data */
    public:

        int getComponentId();
        void resetComponent();
        TurtleComponent() = default;
    };
}