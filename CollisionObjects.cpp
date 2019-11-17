#include "CollisionObjects.h"

Wall::Wall(float x, float y, float w, float h, const Texture& texture)
{
    position = Vector2f(x,y);
    width = w;
    height = h;
    shape.setPosition(position);
    shape.setSize(Vector2f(width,height));
    shape.setTexture(&texture);
}

Wall::Wall(float x, float y, float w, float h, Color color)
{
    width = w;
    height = h;
    position = Vector2f(x,y);
    shape.setPosition(position);
    shape.setSize(Vector2f(width,height));
    shape.setFillColor(color);
}
