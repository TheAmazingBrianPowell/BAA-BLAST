#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "character.h"
#include "CollisionObjects.h"
#include <iostream>

using namespace sf;

int main()
{
    const float windowWidth = 1020, windowHeight = 780;
    Vector2f translate((float)windowWidth / 2,(float)windowHeight / 2);
    int level = 0;
    const int totalLevels = 1, levelY = 37;
    const String levels[totalLevels][levelY] = {
            {

                "                                                   ",
                "                                           0000    ",
                "                                          0        ",
                "                                         0         ",
                "                                        0          ",
                "                                       0           ",
                "                                      0            ",
                "                                     0             ",
                "                                    0              ",
                "                                   0               ",
                "                                  0                ",
                "                                 0                 ",
                "                                0                  ",
                "                               0                   ",
                "                              0                    ",
                "                             0                     ",
                "                            0                      ",
                "                           0                       ",
                "                          0                        ",
                "                         0                         ",
                "                        0                          ",
                "                       0                           ",
                "                      0                            ",
                "                     0                             ",
                "                    0                              ",
                "                   0                               ",
                "                  0                                ",
                "                 0                                 ",
                "                0                                  ",
                "               0                                   ",
                "              0                                    ",
                "             0                                     ",
                "            0                                      ",
                "           0                                       ",
                "          0                                        ",
                "         0                                         ",
                "        0                                          "
            }
    };

    //Load textures
    Texture cat;
    cat.loadFromFile("../resources/cat.jpeg");

    RenderWindow window(VideoMode(windowWidth, windowHeight, 32), "Cool Game", Style::Close | Style::Titlebar);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    View main(FloatRect(0, 0, windowWidth, windowHeight));

    Character player((float)windowWidth / 2,50,20,20,cat);

    RectangleShape background;
    background.setPosition(0,0);
    background.setSize(Vector2f(windowWidth,windowHeight));
    background.setTexture(&cat);

    RectangleShape background2;
    background2.setPosition(windowWidth,0);
    background2.setSize(Vector2f(windowWidth,windowHeight));
    background2.setTexture(&cat);

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
//            if (event.type == Event::Resized)
//            {
//                        windowHeight = event.size.width;
//                        windowWidth = event.size.height;
//                    main.setViewport(FloatRect(0, 0,  event.size.height / event.size.width,1));
//                  main.setCenter(event.size.width / 2,event.size.height / 2);
//                   main.setSize(event.size.width, event.size.height);
//                //else {
//                    //main.setViewport(FloatRect(0, 0, windowHeight / event.size.height, windowHeight / event.size.height));
//                    //main.setSize(windowHeight, windowHeight);
//                //}
//
//            }
        }

        //apply forces to players
        player.velocity.y += 0.4;
        player.controls();

        //check for collisions
        for(int checkCollisions = 0; checkCollisions < 7; checkCollisions++)
        {
            player.checkGroundCollision();
            for(int y = 0; y < levelY; y++) {
                for(int x = 0; x < levels[level][y].getSize(); x++) {
                    switch(levels[level][y][x]) {
                        case ' ':
                            break;
                        case '0':
                        {
                            Wall wall(x * 20, y * 20, 20, 20, cat);
                            player.collide(wall);
                        }
                            break;
                    }
                }
            }
            player.update(7);

            //if the player is not moving, there is no need to update, test for collisions, or apply friction
            if(abs(player.velocity.x) <= 0.001 && abs(player.velocity.y) <= 0.001) {
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
        if((player.position.x > (float)windowWidth / 2 - 200 + translate.x && player.velocity.x > 0) || (player.position.x < (float)-windowWidth / 2 + 200 + translate.x && player.velocity.x < 0))
        {
            translate.x += player.velocity.x;
            main.setCenter(translate);
        }
        window.draw(background);
        window.draw(background2);
        window.draw(player.shape);

        for(int y = 0; y < levelY; y++) {
            for(long x = 0; x < levels[level][y].getSize(); x++) {
                if(x * 20 > translate.x + windowWidth / 2 || x * 20 + 20 < translate.x - windowWidth / 2) {
                    continue;
                }
                switch(levels[level][y][x]) {
                    case ' ':
                        break;
                    case '0':
                        {
                            Wall wall(x * 20, y * 20, 20, 20, cat);
                            window.draw(wall.shape);
                        }
                        break;
                }
            }
        }

        //display everything
        window.display();
    }
    return EXIT_FAILURE;
}
