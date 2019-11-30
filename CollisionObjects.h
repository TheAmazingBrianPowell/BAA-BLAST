#ifndef COOLGAME_COLLISION_OBJECTS_H
#define COOLGAME_COLLISION_OBJECTS_H

#include <SFML/Graphics.hpp>

using namespace sf;

class CollisionObject {
public:
    Vector2f position;
    float width, height;
    CollisionObject(float x, float y, float w, float h, const Texture& texture);
    CollisionObject(float x, float y, float w, float h, Color color);
    CollisionObject(float x, float y, float w, float h);
    Sprite shape;
};

class Wall : public CollisionObject {
public:
    Wall(float x, float y, float w, float h, const Texture& texture);
    Wall(float x, float y, float w, float h, Color color);
    Wall(float x, float y, float w, float h);
};

class Portal : public CollisionObject{
public:
    Portal(float x, float y, float w, float h, const Texture& texture);
    Portal(float x, float y, float w, float h, Color color);
    Portal(float x, float y, float w, float h);
};

class Sign : public CollisionObject {
public:
    Sign(float x, float y, float w, float h, const Texture& texture);
    Sign(float x, float y, float w, float h, Color color);
    Sign(float x, float y, float w, float h);
};

#endif
