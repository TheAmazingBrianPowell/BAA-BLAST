#ifndef COOLGAME_COLLISION_OBJECTS_HPP
#define COOLGAME_COLLISION_OBJECTS_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h> 

using namespace sf;

class CollisionObject {
public:
    Vector2f position;
    float width, height;
    CollisionObject(float x, float y, float w, float h, const Texture& texture);
    CollisionObject(float x, float y, float w, float h);
    Sprite shape;
};

class Wall : public CollisionObject {
public:
    Wall(float x, float y, float w, float h, const Texture& texture);
    Wall(float x, float y, float w, float h);
};

class Elevator : public CollisionObject {
public:
    Elevator(float x, float y, float w, float h, const Texture& texture);
    void move();
    void collide(Wall& wall);
    int direction;
    int waitTimer;
};

class Board : public CollisionObject {
public:
    Board(float x, float y, float w, float h, const Texture& texture);
    bool startTimer;
    void runTimer();
private:
    int timerThing;
};

class Portal : public CollisionObject{
public:
    Portal(float x, float y, float w, float h, const Texture& texture);
};

class Sign : public CollisionObject {
public:
    Sign(float x, float y, float w, float h, const Texture& texture);
};

class Coin : public CollisionObject {
public:
    Sprite shape2;
    Coin(float x, float y, float w, float h, const Texture& texture);
    Coin(float x, float y, float w, float h, const Texture& texture, const Texture& texture2);
    void rotate();
private:
    bool rotateDirection;
    float rotation;
    Vector2f position2;
};

class Jump : public CollisionObject {
public:
    Jump(float x, float y, float w, float h, const Texture& texture, const Texture& texture2);
   const Texture* firstTexture;
   const Texture* secondTexture;
   Vector2f originalPos;
   int springTimer;
};

#endif
