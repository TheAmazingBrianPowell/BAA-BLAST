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

Elevator::Elevator(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {
    direction = rand() % 2 * 2 - 1;
    waitTimer = 0;
}
void Elevator::move(float numLoops) {
    if(waitTimer == 0) {
        position.x += ((float)direction * 1.5 / numLoops);
        shape.setPosition(position);
    }
    if(waitTimer != 0) {
        waitTimer += 1.f / numLoops;
    }
    if(waitTimer >= 100) {
	waitTimer = 0;
    }
}

void Elevator::collide(Wall& wall) {
    if(position.x + width >= wall.position.x && position.x <= wall.position.x + wall.width && position.y + height >= wall.position.y && position.y <= wall.position.y + wall.height) 
    {
        if(position.x + width >= wall.position.x && position.x <= wall.position.x + wall.width - 1.5 && position.y + height >= wall.position.y + 1.5 && position.y <= wall.position.y + wall.height - 1.5)
        {
            position.x = wall.position.x - width - 1.5;
	    direction = -1;
	    waitTimer++;
        }
         if(position.x + width >= wall.position.x + 1.5 && position.x <= wall.position.x + wall.width && position.y + height >= wall.position.y + 1.5 && position.y <= wall.position.y + wall.height - 1.5)
        {
            position.x = wall.position.x + wall.width + 1.5;
	    direction = 1;
	    waitTimer++;
        }
    }
}

Wall::Wall(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {}

Wall::Wall(float x, float y, float w, float h) : CollisionObject(x, y, w, h) {}

Board::Board(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {
    timerThing = 255;
    startTimer = false;
}

void Board::runTimer() {
    if(startTimer) {
	shape.setColor(Color(255,255,255,timerThing-=5));
    }
    if(timerThing <= 0) {
	startTimer = false;
	timerThing--;
	shape.setColor(Color(255,255,255,0));
    }
    if(timerThing <= -400) {
	timerThing = 255;
	shape.setColor(Color(255,255,255,255));
    }
}

Portal::Portal(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {}

Sign::Sign(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {}

Coin::Coin(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x, y, w, h, texture) {
    rotation = (float)(rand() % 11 - 5) / 5;
    rotateDirection = true;
    position2 = Vector2f(x + 13, y);
}

Coin::Coin(float x, float y, float w, float h, const Texture& texture, const Texture& texture2) : CollisionObject(x, y, w, h, texture) {
    rotation = (float)(rand() % 11 - 5) / 5;
    rotateDirection = true;
    shape2.setTexture(texture2);
    position2 = Vector2f(x + 13, y);
}

void Coin::rotate() {
    if(rotation <= 0) {
	shape.setPosition(position2.x + shape.getGlobalBounds().width / 2, shape.getPosition().y);
    } else {
	shape.setPosition(position2.x - shape.getGlobalBounds().width / 2, shape.getPosition().y);
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