#include "character.hpp"



Enemy::Enemy(float x, float y, float w, float h, const Texture& texture)
{
    position = Vector2f(x,y);
    width = w;
    height = h;
    shape.setPosition(position);
    shape.setTexture(texture);
    isOnBlock = true;
    direction = rand() % 2 * 2 - 1;
}

void Enemy::move() {
    position.x += direction * 1.5;
}

void Enemy::collide(Wall wall) {
    if(position.x + width / 1.5 >= wall.position.x && position.x <= wall.position.x + wall.width / 1.5 && position.y + height >= wall.position.y && position.y <= wall.position.y + wall.height - 1)
        isOnBlock = true;
    if((position.x + width >= wall.position.x && position.x <= wall.position.x + wall.width - 1 && position.y + height >= wall.position.y + 1 && position.y <= wall.position.y + wall.height - 1) || (position.x + width >= wall.position.x + 1 && position.x <= wall.position.x + wall.width && position.y + height >= wall.position.y + 1 && position.y <= wall.position.y + wall.height - 1))
        direction*=-1;
}

void Enemy::update() {
    if(!isOnBlock)
        direction *= -1;
    isOnBlock = false;
    shape.setPosition(position);
}



Character::Character(float x, float y, float w, float h, Texture& texture)
{
    VELOCITY_LIMIT = 4;
    ACCELERATION = 0.4;
    position = Vector2f(x,y);
    shape.setPosition(position);
    width = w;
    height = h;
    shape.setTexture(texture);
    isAlive = true;
    lives = 3;
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

void Character::collide(Enemy enemy) {
    if(position.x + width >= enemy.position.x && position.x <= enemy.position.x + enemy.width && position.y + height >= enemy.position.y && position.y <= enemy.position.y + enemy.height) {
        isAlive = false;
    }
}

void Character::collide(Portal portal, bool& level) {
    if(position.x + width >= portal.position.x && position.x <= portal.position.x + portal.width && position.y + height >= portal.position.y && position.y <= portal.position.y + portal.height)
    {
        level = true;
    }
}

bool Character::collide(Sign sign) {
    return (position.x + width >= sign.position.x && position.x <= sign.position.x + sign.width && position.y + height >= sign.position.y && position.y <= sign.position.y + sign.height);
}

void Character::update(int loopTimes) {
    constrain(velocity.x, -VELOCITY_LIMIT, VELOCITY_LIMIT);
    constrain(velocity.y, -7, 7);
    position += velocity / (float) loopTimes;
    shape.setPosition(position);
    if (!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right))
        velocity.x *= pow(0.9, 1.f / loopTimes);
}