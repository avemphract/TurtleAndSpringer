#include "System.h"

class VelocitySystem: public System
{
private:
    /* data */
public:
    VelocitySystem();
    ~VelocitySystem();
    virtual void update(Entity* entity, float deltaTime);
};
