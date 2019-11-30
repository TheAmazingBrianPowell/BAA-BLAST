#include "CollisionObjects.h"

CollisionObject::CollisionObject(float x, float y, float w, float h, const Texture& texture)
{
    position = Vector2f(x,y);
    width = w;
    height = h;
    shape.setPosition(position);
    shape.setTexture(texture);
}

CollisionObject::CollisionObject(float x, float y, float w, float h, Color color)
{
    width = w;
    height = h;
    position = Vector2f(x,y);
    shape.setPosition(position);
    shape.setColor(color);
}

CollisionObject::CollisionObject(float x, float y, float w, float h)
{
    width = w;
    height = h;
    position = Vector2f(x,y);
}

Wall::Wall(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {}
Wall::Wall(float x, float y, float w, float h, Color color) : CollisionObject(x, y, w, h, color) {}
Wall::Wall(float x, float y, float w, float h) : CollisionObject(x, y, w, h) {}

Portal::Portal(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {}
Portal::Portal(float x, float y, float w, float h, Color color) : CollisionObject(x, y, w, h, color) {}
Portal::Portal(float x, float y, float w, float h) : CollisionObject(x, y, w, h) {}

Sign::Sign(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {}
Sign::Sign(float x, float y, float w, float h, Color color) : CollisionObject(x, y, w, h, color) {}
Sign::Sign(float x, float y, float w, float h) : CollisionObject(x, y, w, h) {}
