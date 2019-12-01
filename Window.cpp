//TODO: 
//Make Signs
//Make Lives + Timer Thing
//Animation for movement
//Make Coins or collection thingies + secret coins
//Make jump things
//Make Thingies that you don't want to fall into
//Make main menu
//Make level menu
//Make story
//Make level maps
//More wall textures
//Make background texture


#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include "character.hpp"
#include "CollisionObjects.hpp"
#include <iostream>
#include <vector>
#include <SFML/Config.hpp>
#include "GText.hpp"

using namespace sf;

int main()
{
    Uint8 sPixels[2080] = {58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,58,35,35,255,66,34,27,255,58,35,35,255,58,35,35,255,255,255,255,255,255,255,255,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,0,0,0,255,255,255,255,255,58,35,35,255,66,34,27,255,58,35,35,255,58,35,35,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,58,35,35,255,66,34,27,255,58,35,35,255,58,35,35,255,255,255,255,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,255,255,255,255,0,0,0,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,255,255,255,255,58,35,35,255,66,34,27,255,58,35,35,255,58,35,35,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,58,35,35,255,66,34,27,255,58,35,35,255,58,35,35,255,255,255,255,255,0,0,0,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,255,255,255,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,255,255,255,255,0,0,0,255,255,255,255,255,58,35,35,255,66,34,27,255,58,35,35,255,58,35,35,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,58,35,35,255,66,34,27,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,89,46,37,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,89,46,37,255,89,46,37,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,58,35,35,255,58,35,35,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,58,35,35,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Uint8 bPixels[2704] = {58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,66,34,27,255,0,0,0,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,58,35,35,255,0,0,0,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,89,46,37,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255};
    Uint8 cPixels[1664] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,116,75,17,255,116,75,17,255,116,75,17,255,116,75,17,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,116,75,17,255,116,75,17,255,206,187,109,255,206,187,109,255,116,75,17,255,116,75,17,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,206,187,109,255,0,0,0,255,206,187,109,255,206,187,109,255,0,0,0,255,206,187,109,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,206,187,109,255,206,187,109,255,206,187,109,255,206,187,109,255,206,187,109,255,206,187,109,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,206,187,109,255,206,187,109,255,206,187,109,255,206,187,109,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,206,187,109,255,206,187,109,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,0,0,0,0,255,0,0,0,255,35,38,150,255,35,38,150,255,35,38,150,255,35,38,150,255,255,255,255,255,159,20,20,255,159,20,20,255,255,255,255,255,35,38,150,255,35,38,150,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,255,255,255,255,159,20,20,255,159,20,20,255,255,255,255,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,255,255,255,255,159,20,20,255,159,20,20,255,255,255,255,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,255,255,255,255,159,20,20,255,159,20,20,255,255,255,255,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,255,255,255,255,159,20,20,255,159,20,20,255,255,255,255,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,255,255,255,255,159,20,20,255,159,20,20,255,255,255,255,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,35,38,150,255,35,38,150,255,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,206,187,109,255,206,187,109,255,206,187,109,255,0,0,0,255,35,38,150,255,35,38,150,255,55,37,150,255,55,37,150,255,55,37,150,255,55,37,150,255,55,37,150,255,55,37,150,255,0,0,0,255,206,187,109,255,206,187,109,255,206,187,109,255,206,187,109,255,206,187,109,255,206,187,109,255,0,0,0,255,35,38,150,255,35,38,150,255,55,37,150,255,55,37,150,255,55,37,150,255,55,37,150,255,55,37,150,255,55,37,150,255,0,0,0,255,206,187,109,255,206,187,109,255,206,187,109,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,35,38,150,255,35,38,150,255,55,37,150,255,55,37,150,255,55,37,150,255,55,37,150,255,55,37,150,255,55,37,150,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,55,37,150,255,55,37,150,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,255,55,37,150,255,55,37,150,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,255,55,37,150,255,55,37,150,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,255,35,38,150,255,35,38,150,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,116,75,17,255,116,75,17,255,120,83,22,255,120,83,22,255,0,0,0,255,0,0,0,255,120,83,22,255,120,83,22,255,116,75,17,255,116,75,17,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,116,75,17,255,116,75,17,255,116,75,17,255,120,83,22,255,0,0,0,255,0,0,0,255,120,83,22,255,116,75,17,255,116,75,17,255,116,75,17,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0};
    const int windowWidth = 1020, windowHeight = 780;
    Vector2f translate((float)windowWidth / 2,(float)windowHeight / 2);
    int level = 0;
    bool levelIsChanging = false;
    const int gridSize = 26;
    const int totalLevels = 2, levelY = windowHeight / gridSize;
    const String levels[totalLevels][levelY] = {
            {

                "                   000000000000000000000000000000000000000000000000000",
                "                   0                                                 0",
                "                   0                                         0    !  0",
                "                   0 0                                      00 0000000",
                "                   0  0                                    000 0000000",
                "                   0   0                                  0  0       0",
                "                   0    0                                0   0000000 0",
                "                   0     0                              0      !     0",
                "                   0      0                            0  000000000000",
                "                   0       0                          00             0",
                "                   0       00000000000            !  01100 0 0 0 0 0 0",
                "                   0                              00000000 0 0 0 0 0 0",
                "                   0                      0        0     0 0 0 0 0 0 0",
                "                   0                       0      0      0 0 0 0 0 0 0",
                "                   0                        0    0                   0",
                "                   0                            0    00000000000000000",
                "                   0                       0        0                0",
                "                   0                         0     0                 0",
                "                   0                              0                  0",
                "                   0                             0                   0",
                "                   0                            0                    0",
                "                   0                           0                     0",
                "                   0                          0                      0",
                "                   0                                                 0",
                "                   0         ?         00000                         0",
                "                   1        0000  00000111110                        00000000000000000000000",
                "                   1       0      111111111110                                             0",
                "                   0      0       1111111111110                                            0",
                "                   0#    0   !    01111111111110                                           0",
                "000000000000000000000000000000000000000000000000000000000   00000000000000000000000000000000"
            },
            {
                "000000000000000000000000000000000000000000000000000",
                "                                #                  ",
                "000000000000000000000000000000000000000000000000000"
            }
    };

    std::vector<Enemy> enemies;
    std::vector<Sign> signs;
    std::vector<Wall> wallsD;
    std::vector<Wall> wallsI;
    std::vector<Wall> wallsR;
    std::vector<Sign> sign;
    std::vector<Portal> portals;
    Texture character, brick, signTexture;
    character.create(16,26);
    character.update(cPixels);
    brick.create(26,26);
    brick.update(bPixels);
    signTexture.create(26,20);
    signTexture.update(sPixels);

    int fadeTimer = 255;

    bool isQuestioning = false;

    Clock time;

    RenderWindow window(VideoMode(windowWidth, windowHeight, 32), "FBLA Game", Style::Close | Style::Titlebar);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    View main(FloatRect(0, 0, windowWidth, windowHeight));

    Character player((float)windowWidth / 2,50,16,26,character);

    RectangleShape background;
    background.setSize(Vector2f(windowWidth,windowHeight));
    background.setTexture(&character);

    RectangleShape background2;
    background2.setPosition(windowWidth,0);
    background2.setSize(Vector2f(windowWidth,windowHeight));
    background2.setTexture(&character);

    //render loop
    
    while (window.isOpen())
    {
        //Handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                break;
            }
        }

        //set player locations
        if(fadeTimer > 255 && fadeTimer < 510)
        {
            if(levelIsChanging) {
                level++;
                levelIsChanging = false;
            }
            player.isAlive = true;
            enemies.clear();
            signs.clear();
	    wallsR.clear();
	    wallsD.clear();
	    wallsI.clear();
	    signs.clear();
	    portals.clear();
            for (int y = 0; y < levelY; y++) {
                for (int x = 0; x < levels[level][y].getSize(); x++) {
                    switch (levels[level][y][x]) {
                        case '!':
                            {
                                Enemy enemy(x * gridSize, y * gridSize, 16, 26, character);
                                enemies.push_back(enemy);
                            }
                            break;
                        case '#':
                            player.position = Vector2f(x * gridSize, y * gridSize);
			    player.update(1);
                            break;
                        case '0':
			    {
				Wall wall(x * gridSize, y * gridSize, gridSize, gridSize, brick);
				wallsR.push_back(wall);
			    }
			    break;
                        case '1':
			    {
				Wall wall(x * gridSize, y * gridSize, gridSize, gridSize, brick);
				wallsD.push_back(wall);
			    }
                            break;
			case '2':
			    {
				Wall wall(x * gridSize, y * gridSize, gridSize, gridSize);
				wallsI.push_back(wall);
			    }
			    break;
			case '?':
			    {
				Sign sign(x * gridSize, y * gridSize + 6, gridSize, gridSize, signTexture);
				signs.push_back(sign);
			    }
			    break;
			case '@':
			    {
				Portal portal(x * gridSize, y * gridSize, 26, 20, signTexture);
				portals.push_back(portal);
			    }
                    }
                }
            }
            translate.x = player.position.x;
            main.setCenter(translate);
            background.setPosition(translate.x,0);
            background2.setPosition(translate.x + windowWidth,0);
        }

        //apply forces to players
        if(fadeTimer >= 510 && !isQuestioning) {
            player.velocity.y += 0.4;
            player.controls();
            for (Enemy &enemy : enemies) {
                enemy.move();
            }
            //check for collisions
            for(int checkCollisions = 0; checkCollisions < 8; checkCollisions++)
            {
	        for(Portal& portal : portals) {
		    player.collide(portal, levelIsChanging);
	        }
	        for(Sign& sign : signs) {
	 	    if(player.collide(sign)) {
		        isQuestioning = true;
		    }
	        }
	        for(Wall& wall : wallsR) {
		    player.collide(wall);
	        }
	        for(Wall& wall : wallsI) {
		    player.collide(wall);
	        }
                //collisions with enemies
                for(Enemy& enemy : enemies) {
                    player.collide(enemy);
                }

                //update the player's location
                player.update(8);

	        //if the player is not moving, there is no need to update, test for collisions, or apply friction after this point
	        if((abs(player.velocity.x) <= 0.001 && abs(player.velocity.y) <= 0.001) || fadeTimer < 510)
                    break;
            }
	}

        //update location of the background images
        if(translate.x > background.getPosition().x + windowWidth * 1.5) {
            background.setPosition(background2.getPosition().x + windowWidth,0);
        } else if (translate.x < background.getPosition().x - windowWidth * 0.5) {
            background.setPosition(background2.getPosition().x - windowWidth,0);
        }
        if(translate.x > background2.getPosition().x + windowWidth * 1.5) {
            background2.setPosition(background.getPosition().x + windowWidth,0);
        } else if (translate.x < background2.getPosition().x - windowWidth * 0.5) {
            background2.setPosition(background.getPosition().x - windowWidth,0);
        }

        //clear and draw new frames
        window.clear(Color::Black);
        window.setView(main);

        //translate view
        if((player.position.x > 100 + translate.x && player.velocity.x > 0) || (player.position.x < translate.x - 100 && player.velocity.x < 0))
        {
            translate.x += (int)player.velocity.x;
            main.setCenter(translate);
        }

        //draw specific things
        window.draw(background);
        window.draw(background2);
        window.draw(player.shape);

	//draw portals
	for(Portal &portal : portals) {
	    window.draw(portal.shape);
	}

	
	//draw question things
	for(Sign &sign : signs) {
	    window.draw(sign.shape);
	}

	//draw walls
	for(Wall &wall : wallsR) {
	    for(Enemy &enemy : enemies) {
		enemy.collide(wall);
	    }
	    window.draw(wall.shape);
	}
	for(Wall &wall : wallsD) {
	    if (player.position.x + player.width > wall.position.x && player.position.x < wall.position.x + wall.width && player.position.y + player.height > wall.position.y && player.position.y < wall.position.y + wall.height) {
		wall.shape.setColor(Color(255,255,255,100));
	    }
	    window.draw(wall.shape);
	}

	//draw enemies
        for(Enemy &enemy : enemies) {
            enemy.update();
            window.draw(enemy.shape);
        }

        //draws fading overlay
        if(fadeTimer < 510) {
            RectangleShape backgroundThing;
            backgroundThing.setPosition(translate.x - windowWidth / 2, 0);
            backgroundThing.setSize(Vector2f(windowWidth, windowHeight));
            backgroundThing.setFillColor(Color(0,0,0, fadeTimer > 255 ? 255 - fadeTimer : fadeTimer));
            window.draw(backgroundThing);
            fadeTimer+=5;
        }

	if(isQuestioning) {
	    //RectangleShape(
	}

	text("abcdefghijklmno",200,10,2, window);

        //display everything
        window.display();

        //sets fade animation to begin when player dies
        if(player.lives > 0 && fadeTimer == 510 && (!player.isAlive || player.position.y > windowHeight)) {
            player.lives--;
            fadeTimer = 0;
            player.velocity = Vector2f(0,0);
        }
        if(levelIsChanging && fadeTimer == 510) {
            fadeTimer = 0;
            player.velocity = Vector2f(0,0);
        }
    }

    //User is exiting game, cleanup anything?
    return EXIT_SUCCESS;
}