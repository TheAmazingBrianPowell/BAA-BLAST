#ifndef COOLGAME_COLLISIONOBJECTS_H
#define COOLGAME_COLLISIONOBJECTS_H

#include <SFML/Graphics.hpp>
#include "character.h"

using namespace sf;


class CollisionObject {
protected:
    Vector2f position;
    float width, height;

public:
    CollisionObject(float x, float y, float w, float h, const Texture& texture);
    CollisionObject(float x, float y, float w, float h, Color color);
    bool checkCollision(Character character);
    Character checkCollision(Character character[]);
    RectangleShape shape;
};

class Wall : public CollisionObject {
public:
    Wall(float x, float y, float w, float h, const Texture& texture);
    Wall(float x, float y, float w, float h, Color color);
};


#endif
