#include "character.h"
#include <cmath>

Character::Character(float x, float y, float w, float h, Texture texture)
{
    VELOCITY_LIMIT = 4;
    ACCELERATION = 0.2;
    position = Vector2f(x,y);
    shape.setPosition(position);
    width = w;
    height = h;
    shape.setSize(Vector2f(width, height));
    shape.setTexture(&texture);
    isAlive = true;
    jumpTime = -2;
    canJump = false;
}

Character::Character(float x, float y, float w, float h, Color color)
{
    VELOCITY_LIMIT = 4;
    ACCELERATION = 0.2;
    position = Vector2f(x,y);
    shape.setPosition(position);
    width = w;
    height = h;
    shape.setSize(Vector2f(width, height));
    shape.setFillColor(color);
    isAlive = true;
    jumpTime = -2;
    canJump = false;
}

void Character::applyForce(Vector2f force)
{
    velocity += force;
}

void Character::constrain(float &value, float min, float max)
{
    if(value < min)
        value = min;

    if(value > max)
        value = max;
}

void Character::jump()
{
    if(jumpTime == -3)
        jumpTime = 5;

    if (jumpTime >= 0)
        applyForce(Vector2f(0, -jumpTime--));
}

void Character::controls()
{
    if(Keyboard::isKeyPressed(Keyboard::Up) && canJump)
        jumpTime = -3;

    jump();

    if (Keyboard::isKeyPressed(Keyboard::Left))
        applyForce(Vector2f(-ACCELERATION,0));
    else if (Keyboard::isKeyPressed(Keyboard::Right))
        applyForce(Vector2f(ACCELERATION,0));

    canJump = false;
}

void Character::checkGroundCollision()
{
    if(position.y + height > 768)
    {
        canJump = true;
        velocity.y = 0;
        position.y = 768 - height;
    }
}

void Character::update(int loopTimes) {
    constrain(velocity.x, -VELOCITY_LIMIT, VELOCITY_LIMIT);
    constrain(velocity.y, -7, 7);
    position += velocity / (float) loopTimes;
    shape.setPosition(position);
    if (!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right))
        velocity.x *= pow(0.9, 1.f / loopTimes);
}