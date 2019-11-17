#include "character.h"

Character::Character(float x, float y, float w, float h, Texture& texture)
{
    VELOCITY_LIMIT = 4;
    ACCELERATION = 0.4;
    position = Vector2f(x,y);
    shape.setPosition(position);
    width = w;
    height = h;
    shape.setSize(Vector2f(width, height));
    shape.setTexture(&texture);
    isAlive = true;
    jumpTime = -1;
    canJump = false;
}

Character::Character(float x, float y, float w, float h, Color color)
{
    VELOCITY_LIMIT = 4;
    ACCELERATION = 0.4;
    position = Vector2f(x,y);
    shape.setPosition(position);
    width = w;
    height = h;
    shape.setSize(Vector2f(width, height));
    shape.setFillColor(color);
    isAlive = true;
    jumpTime = -1;
    canJump = false;
}

void Character::constrain(float& value, float min, float max)
{
    if(value < min)
        value = min;

    if(value > max)
        value = max;
}

void Character::jump()
{
    if(jumpTime == -2)
        jumpTime = 5;

    if (jumpTime >= 0) {
        velocity.y += -jumpTime;
        jumpTime--;
    }
}

void Character::controls()
{
    if(Keyboard::isKeyPressed(Keyboard::Up) && canJump)
        jumpTime = -2;

    jump();

    if (Keyboard::isKeyPressed(Keyboard::Left))
        velocity.x += -ACCELERATION;
    else if (Keyboard::isKeyPressed(Keyboard::Right))
        velocity.x += ACCELERATION;

    canJump = false;
}

void Character::checkGroundCollision()
{
    if(position.y + height > 760)
    {
        canJump = true;
        velocity.y = 0;
        position.y = 760 - height;
    }
}

void Character::collide(Wall wall) {
    if(position.x + width >= wall.position.x && position.x <= wall.position.x + wall.width && position.y + height >= wall.position.y && position.y <= wall.position.y + wall.height) {
        if(position.x + width >= wall.position.x + 1 && position.x <= wall.position.x + wall.width - 1 && position.y + height >= wall.position.y && position.y <= wall.position.y + wall.height - 1)
        {
            position.y = wall.position.y - height - 0.001;
            velocity.y = 0;
            canJump = true;
        }
        else if(position.x + width >= wall.position.x + 1 && position.x <= wall.position.x + wall.width - 1 && position.y + height >= wall.position.y + 1 && position.y <= wall.position.y + wall.height)
        {
            position.y = wall.position.y + wall.height + 0.001;
            velocity.y = 0;
            jumpTime = -1;
        }
        if(position.x + width >= wall.position.x && position.x <= wall.position.x + wall.width - 1 && position.y + height >= wall.position.y + 1 && position.y <= wall.position.y + wall.height - 1)
        {
            position.x = wall.position.x - width - 0.001;
            velocity.x = 0;
        }
        else if(position.x + width >= wall.position.x + 1 && position.x <= wall.position.x + wall.width && position.y + height >= wall.position.y + 1 && position.y <= wall.position.y + wall.height - 1)
        {
            position.x = wall.position.x + wall.width + 0.001;
            velocity.x = 0;
        }
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
