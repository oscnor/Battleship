#include <iostream> 
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <time.h>
#include <vector>
#include "playingfield.hpp"

// Compile g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system

const int RECTANGLE_SIZE = 40;
const sf::Vector2i WINDOW_SIZE(1280, 720);
sf::RenderWindow WINDOW(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y),"Battleship");

int main()
{
    // Random initializer srand((unsigned) time(nullptr));
    // sf::Clock clock;

    sf::Event event;
    
    int gamestate = 0;
    

    // Initializing players
    Playingfield player(1,RECTANGLE_SIZE, WINDOW);
    Playingfield bot(2, RECTANGLE_SIZE, WINDOW);

    // Gameloop
    while (WINDOW.isOpen())
    {
        while (WINDOW.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                WINDOW.close();
            
            /*  
            *   switch functions based on current gamestate
            *   0 = Pre
            *   1 = Playing
            *   2 = Post
            */

            //mouseHovering position
            //std::cout << player.getGridAdress()[0][0].getPosition.x;
            switch (gamestate)
            {
                case 0:
                    player.lightMarkedSquare();
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == true)
                    {
                        player.selectSquare();
                        player.setButtonPressed(true);
                    }
                    else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) == true)
                    {
                        player.deselectSquares();
                        player.setButtonPressed(false);
                    }
                break;

                case 1:
                break;

                case 2:
                break;

                default:
                break;
            }
            
            /*if(direction.x == 0)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    direction = sf::Vector2f(-1, 0);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    direction = sf::Vector2f(1,0);
            }
            else if(direction.y == 0)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    direction = sf::Vector2f(0,-1);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    direction = sf::Vector2f(0,1);
            }*/

        }
        WINDOW.clear(sf::Color::White);
        player.drawGrid();
        WINDOW.display();
    }
    
    return 0;
}