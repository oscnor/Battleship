#ifndef PLAYINGFIELD
#define PLAYINGFIELD

#include <SFML/Graphics.hpp>
#include <vector>
#include "ship.hpp"
#include <cmath>

#include <iostream>

class Playingfield
{
private:
    const int gridSize;
    //const int friendlyGridOffset = gridSize +3;
    const bool player;
    bool lButtonPressed;

    std::vector<std::vector<sf::RectangleShape>> grid;
    std::vector<std::vector<sf::RectangleShape>>* gridInFocus; 
    std::vector<sf::RectangleShape*> pSelectedSquares;
    std::vector<Ship> ships;

    sf::RenderWindow *pWindow;
    sf::RectangleShape* pMarkedSquare;
    sf::RectangleShape invisibleSquare;
    sf::Vector2i mousePos;    

    void hoveringSquare();

    //int shipSizes[5] = {5,4,3,3,2};

public:
    Playingfield(bool _isPlayer, int sizeOfGrid, sf::RectangleShape rectangleTemplate, sf::RenderWindow &_window);
    ~Playingfield();

    bool isPlayer();
    int placeShip(std::vector<sf::Vector2f> position);
    void setButtonPressed(bool setButtonPressed);
    void selectSquare();
    void deselectSquares();
    void drawGrid();
    void lightMarkedSquare();

    std::vector<std::vector<sf::RectangleShape>>* getGridAdress();
};
#endif