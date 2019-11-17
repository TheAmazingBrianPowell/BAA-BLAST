#ifndef COOLGAME_COLLISION_OBJECTS_H
#define COOLGAME_COLLISION_OBJECTS_H

#include <SFML/Graphics.hpp>

using namespace sf;


class Wall {
public:
    Vector2f position;
    float width, height;
    Wall(float x, float y, float w, float h, const Texture& texture);
    Wall(float x, float y, float w, float h, Color color);
    RectangleShape shape;
};


#endif
