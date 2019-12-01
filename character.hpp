#ifndef COOLGAME_CHARACTER_HPP
#define COOLGAME_CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include "CollisionObjects.hpp"

using namespace sf;

class Enemy {
private:
    short direction;
    bool isOnBlock;

public:
    float width, height;

    Sprite shape;

    Vector2f position;

    Enemy(float x, float y, float w, float h, const Texture& texture);

    void move();

    void collide(Wall wall);

    void update();
};

class Character {
private:
    float ACCELERATION, VELOCITY_LIMIT;
    static void constrain(float &value, float min, float max);

public:
    Character(float x, float y, float w, float h, Texture& texture);

    Vector2f velocity, position;
    bool isAlive;
    bool canJump;

    int lives;

    Sprite shape;

    float width, height, jumpTime;


    void jump();

    void controls();

    void collide(Wall wall);

    void collide(Enemy enemy);

    void collide(Portal portal, bool& level);

    bool collide(Sign sign);

    void update(int loopTimes);
};
#endif
