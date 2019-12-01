#include "CollisionObjects.hpp"

CollisionObject::CollisionObject(float x, float y, float w, float h, const Texture& texture)
{
    position = Vector2f(x,y);
    width = w;
    height = h;
    shape.setPosition(position);
    shape.setTexture(texture);
}

CollisionObject::CollisionObject(float x, float y, float w, float h)
{
    width = w;
    height = h;
    position = Vector2f(x,y);
}

Wall::Wall(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {}
Wall::Wall(float x, float y, float w, float h) : CollisionObject(x, y, w, h) {}

Portal::Portal(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {}

Sign::Sign(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {}