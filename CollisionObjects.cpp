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

Coin::Coin(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {
    rotation = 1;
    rotateDirection = true;
}

void Coin::rotate() {
    if(rotateDirection) {
    	rotation -= 0.05;
	shape.setPosition(shape.getPosition().x + 0.5, shape.getPosition().y);
    } else {
	rotation += 0.05;
	shape.setPosition(shape.getPosition().x - 0.5, shape.getPosition().y);
    }
    if(rotation <= -1) {
    	rotateDirection = false;
    }
    if(rotation >= 1) {
    	rotateDirection = true;
    }
    shape.setScale(rotation, 1);
}

Jump::Jump(float x, float y, float w, float h, const Texture& texture, const Texture& texture2) : CollisionObject(x,y,w,h,texture) {
    firstTexture = &texture;
    secondTexture = &texture2;
    originalPos = Vector2f(x,y);
    springTimer = 0;
}
