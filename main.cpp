#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "character.h"
#include <iostream>
#include "CollisionObjects.h"

using namespace sf;

int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;
    Vector2f translate((float)windowWidth / 2,(float)windowHeight / 2);
    Wall wall(200,700,20,20,Color::Green);

    Texture texture;
    texture.loadFromFile("../resources/cat.jpeg");

    RenderWindow window(VideoMode(windowWidth, windowHeight, 32), "Cool Game");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    View main(FloatRect(0, 0, windowWidth, windowHeight));

    Character player((float)windowWidth / 2,50,10,10,Color::Blue);
    //render loop
    while (window.isOpen())
    {

        //Handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                //close game
                window.close();
                break;
            }
            if (event.type == Event::Resized)
            {
                windowWidth = event.size.width;
                windowHeight = event.size.height;
                main.setSize(windowWidth,windowHeight);
                main.setCenter(player.position.x,windowHeight / 2);
            }
        }

        player.applyForce(Vector2f(0,0.4));

        player.controls();

        for(int checkCollisions = 0; checkCollisions < 5; checkCollisions++)
        {
            player.checkGroundCollision();
            std::cout << wall.checkCollision(player) << std::endl;
            player.update(5);
        }

        //clear and draw new frames
        window.clear(Color::Black);
        window.setView(main);
        if((player.position.x > (float)windowWidth / 2 - 200 + translate.x && player.velocity.x > 0) || (player.position.x < (float)-windowWidth / 2 + 200 + translate.x && player.velocity.x < 0))
        {
            translate.x += player.velocity.x;
            main.setCenter(translate);
        }
        window.draw(player.shape);
        window.draw(wall.shape);

        //display everything
        window.display();
    }
    return EXIT_SUCCESS;
}