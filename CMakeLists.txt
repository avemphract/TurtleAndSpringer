cmake_minimum_required(VERSION 3.21)

project(TurtleAndSpringerProject VERSION 1.0)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    Components/Component.h
    Components/GardenComponent.h
    Components/ShapeComponent.h
    components/SpringerComponent.h
    Components/TransformComponent.h
    Components/TurtleComponent.h
    Components/VelocityComponent.h
    
    Shapes/ArcShape.h
    Shapes/PointShape.h
    Shapes/RectangleShape.h
    Shapes/Shape.h
    
    Systems/System.h
    Systems/VelocitySystem.h
    Systems/TurtleSystem.h

    ComponentManager.h
    Entity.h
    Game.h
)

set(Sources
    Components/Component.cpp
    Components/GardenComponent.cpp
    Components/ShapeComponent.cpp
    components/SpringerComponent.cpp
    Components/TransformComponent.cpp
    Components/TurtleComponent.cpp
    Components/VelocityComponent.cpp

    Shapes/ArcShape.cpp
    Shapes/PointShape.cpp
    Shapes/RectangleShape.cpp
    Shapes/Shape.cpp

    Systems/System.cpp
    Systems/VelocitySystem.cpp
    Systems/TurtleSystem.cpp

    ComponentManager.cpp
    Entity.cpp
    Game.cpp
    main.cpp
)
add_executable(TurtleAndSpringer ${Sources} ${Headers})