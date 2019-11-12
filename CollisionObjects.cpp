#include "CollisionObjects.h"
CollisionObject::CollisionObject(float x, float y, float w, float h, const Texture& texture)
{
    position = Vector2f(x,y);
    width = w;
    height = h;
    shape.setPosition(position);
    shape.setSize(Vector2f(width,height));
    shape.setTexture(&texture);
}

CollisionObject::CollisionObject(float x, float y, float w, float h, Color color)
{
    width = w;
    height = h;
    position = Vector2f(x,y);
    shape.setPosition(position);
    shape.setSize(Vector2f(width,height));
    shape.setFillColor(color);
}

bool CollisionObject::checkCollision(Character character)
{
    return character.position.x + character.width >= position.x && character.position.x <= position.x + width &&
    character.position.y + character.height >= position.y && character.position.y <= position.y + height;
}

Character CollisionObject::checkCollision(Character character[]) {
    //Character characters[2];
//    for (var i = 0; i < character.length; i++) {}
//    if (character[].position.x + character[].width >= position.x && character[].position.x <= position.x + width &&
//        character[].position.y + character[].height >= position.y && character[].position.y <= position.y + height) {
//        return character[i]
//    }
//    }
}




//Wall inherits from CollisionObject
Wall::Wall(float x, float y, float w, float h, const Texture& texture) : CollisionObject(x,y, w, h, texture)
{

}

Wall::Wall(float x, float y, float w, float h, Color color) : CollisionObject(x,y, w, h, color)
{

}


