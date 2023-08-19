#include "System.h"
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

protected:
    virtual void beforeUpdate(std::list<Entity*> &entity);
};