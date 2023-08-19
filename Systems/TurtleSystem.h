#include "System.h"
#include "../Shapes/PointShape.h"
#include "../Game.h"
#include <list>

class TurtleSystem: public System{
public:
    TurtleSystem(Game* game);
    ~TurtleSystem();
    virtual void update(Entity* entity, float deltaTime);
private:
    Game* game;
    Entity* garden = nullptr;
    std::list<Entity*> springers = std::list<Entity*>();
    PointShape getExitPoint(PointShape turtle_p1, PointShape turtle_p2, PointShape boundary_p1, PointShape boundary_p2);

protected:
    virtual void beforeUpdate(std::list<Entity*> &entity);
};