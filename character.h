#ifndef COOLGAME_CHARACTER_H
#define COOLGAME_CHARACTER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Character {
private:
    float ACCELERATION, VELOCITY_LIMIT;
    static void constrain(float &value, float min, float max);

public:
    Character(float x, float y, float w, float h, Texture texture);

    Character(float x, float y, float w, float h, Color color);

    Vector2f velocity, position;

    bool canJump, isAlive;

    RectangleShape shape;

    float width, height, jumpTime;

    void checkGroundCollision();

    void jump();

    void controls();

    void applyForce(Vector2f force);

    void update(int loopTimes);
};
#endif
