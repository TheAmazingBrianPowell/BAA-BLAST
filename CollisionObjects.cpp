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

Coin::Coin(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x + 13, y, w, h, texture) {
    rotation = (float)(rand() % 11 - 5) / 5;
    rotateDirection = true;
}

Coin::Coin(float x, float y, float w, float h, const Texture& texture, const Texture& texture2) : CollisionObject(x + 13, y, w, h, texture) {
    rotation = (float)(rand() % 11 - 5) / 5;
    rotateDirection = true;
    shape2.setTexture(texture2);
    shape2.setPosition(position - Vector2f(13,0));
}

void Coin::rotate() {
    if(rotation <= 0) {
	shape.setPosition(position.x + shape.getGlobalBounds().width / 2, shape.getPosition().y);
    } else {
	shape.setPosition(position.x - shape.getGlobalBounds().width / 2, shape.getPosition().y);
    }
    if(rotateDirection) {
    	rotation -= 0.05;
    } else {
	rotation += 0.05;
    }
    if(rotation <= -1) {
    	rotateDirection = false;
    }
    if(rotation >= 1) {
    	rotateDirection = true;
    }
    shape.setScale(sin(M_PI * rotation * 0.5), 1);
}

Jump::Jump(float x, float y, float w, float h, const Texture& texture, const Texture& texture2) : CollisionObject(x,y,w,h,texture) {
    firstTexture = &texture;
    secondTexture = &texture2;
    originalPos = Vector2f(x,y);
    springTimer = 0;
}
