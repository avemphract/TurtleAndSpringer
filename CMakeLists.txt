cmake_minimum_required(VERSION 3.21)

project(TurtleAndSpringerProject VERSION 1.0)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    Components/Component.h
    Components/ShapeComponent.h
    Components/TransformComponent.h
    Components/VelocityComponent.h
    
    Shapes/ArcShape.h
    Shapes/PointShape.h
    Shapes/Shape.h

    Systems/System.h
    Systems/VelocitySystem.h

    ComponentManager.h
    Entity.h
    Game.h
)

set(Sources
    Components/Component.cpp
    Components/ShapeComponent.cpp
    Components/TransformComponent.cpp
    Components/VelocityComponent.cpp

    Shapes/ArcShape.cpp
    Shapes/PointShape.cpp
    Shapes/Shape.cpp

    Systems/System.cpp
    Systems/VelocitySystem.cpp

    ComponentManager.cpp
    Entity.cpp
    Game.cpp
    main.cpp
)
add_executable(TurtleAndSpringer ${Sources} ${Headers})