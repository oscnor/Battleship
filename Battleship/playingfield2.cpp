#include "playingfield2.hpp"

// Contructor 
Playingfield::Playingfield(bool isPlayer, int sizeOfGrid, sf::RectangleShape rectangleTemplate, sf::RenderWindow &_window)
: player(isPlayer), gridSize(sizeOfGrid), pWindow(&_window)
{
    lButtonPressed = false;
    grid.resize(gridSize);
    rectangleTemplate.setOutlineThickness(1);
    if(player)
        rectangleTemplate.setOutlineColor(sf::Color::Black);
    else
        rectangleTemplate.setOutlineColor(sf::Color::Red);

    invisibleSquare.setPosition(-rectangleTemplate.getSize().y,-rectangleTemplate.getSize().x);
    pMarkedSquare = &invisibleSquare;

    
    for(int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            rectangleTemplate.setPosition(rectangleTemplate.getPosition().x+rectangleTemplate.getSize().x,rectangleTemplate.getPosition().y);
            grid[i].push_back(sf::RectangleShape(rectangleTemplate));        
        }
        rectangleTemplate.setPosition(rectangleTemplate.getPosition().x,rectangleTemplate.getPosition().y+rectangleTemplate.getSize().y);
    }
}

// Destructor
Playingfield::~Playingfield()
{
    delete pMarkedSquare;
    delete pWindow;
    delete gridInFocus;

    if(!pSelectedSquares.empty())
    {
        for(auto p: pSelectedSquares)
        {
            delete p;
        }
    }
}

// Private
void Playingfield::hoveringSquare()
{
    pMarkedSquare = &invisibleSquare;
    gridInFocus = nullptr;
    // Check if mouse is between top left and bottom right corners of both grids together
    if(mousePos.y >= enemyGrid[0][0].getPosition().y && mousePos.y < friendlyGrid[gridSize-1][gridSize-1].getPosition().y+rectangleSize)
    {
        // Check if mouse is between top left and bottom right corners of enemy grid
        if(mousePos.x >= enemyGrid[0][0].getPosition().x && mousePos.x < enemyGrid[gridSize-1][gridSize-1].getPosition().x+rectangleSize)
            gridInFocus = &enemyGrid;
        // Check if mouse is between top left and bottom right corners of friendly grid
        else if(mousePos.x >= friendlyGrid[0][0].getPosition().x && mousePos.x < friendlyGrid[gridSize-1][gridSize-1].getPosition().x+rectangleSize)
            gridInFocus = &friendlyGrid;


        if(gridInFocus != nullptr)
        {
            if(std::floor(((mousePos.x-gridInFocus->at(0)[0].getPosition().x)+rectangleSize)/rectangleSize)-1 >= 0)
            {
                pMarkedSquare = &gridInFocus->at(std::floor(((mousePos.y-gridInFocus->at(0)[0].getPosition().y)+rectangleSize)/rectangleSize)-1)[std::floor(((mousePos.x-gridInFocus->at(0)[0].getPosition().x)+rectangleSize)/rectangleSize)-1];
                if(buttonPressed)
                {
                    pSelectedSquares.resize(1);
                    sf::Vector2f positionDifference = pMarkedSquare->getPosition() - pSelectedSquares[0]->getPosition();
                    for(int i = 0; i < 2; i++)
                    {
                        //pSelectedSquares.push_back();
                    }
                    




                /*
                *
                * Det här ligger på fel ställe, borde inte ligga i hovering, marked borde hamna någon annan stans mer logiskt. 
                * Matten verkar rätt iaf
                * 
                */



















                //std::floor(((mousePos.y-gridInFocus->at(0)[0].getPosition().y)+rectangleSize)/rectangleSize)-1;
                //std::floor(((mousePos.x-gridInFocus->at(0)[0].getPosition().x)+rectangleSize)/rectangleSize)-1;
                //****** if buttonPreviouslyPressed do this
                //int amountOfSquaresToLight;

                //amountOfSquaresToLight = std::floor(((mousePos.y-gridInFocus->at(0)[0].getPosition().y)+rectangleSize)/rectangleSize)-1;
                // std::floor(((mousePos.x-gridInFocus->at(0)[0].getPosition().x)+rectangleSize)/rectangleSize)-1
                }
            }
        }   
    }
}

// Public
void Playingfield::setButtonPressed(bool buttonPressed)
{
    lButtonPressed = buttonPressed;
}

bool Playingfield::isPlayer()
{
    return player;
}

int Playingfield::placeShip(std::vector<sf::Vector2f> position)
{
    ships.push_back(Ship(position));
    return position.size();
}

void Playingfield::selectSquare()
{
    if(!lButtonPressed)
    {
        pSelectedSquares.push_back(pMarkedSquare);   
    }   
    else if(lButtonPressed)
    {
        // pMarkedSquare;
        if(pSelectedSquares[0]->getPosition().x == pMarkedSquare->getPosition().x )
        {
            // Vertical
            
        }
        else if(pSelectedSquares[0]->getPosition().y == pMarkedSquare->getPosition().y)
        {
            // horizontal
        }
    }
}

void Playingfield::deselectSquares()
{
    pSelectedSquares[0]->setFillColor(sf::Color::White);
    pMarkedSquare = &invisibleSquare;
    pSelectedSquares.resize(0);
}

void Playingfield::drawGrid()
{
    for(int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j<gridSize; j++)
        {   
            pWindow->draw(grid[i][j]);
        }
    }
}

void Playingfield::lightMarkedSquare()
{
    mousePos = sf::Mouse::getPosition(*pWindow);
    pMarkedSquare->setFillColor(sf::Color::White);
    // change marked square
    pMarkedSquare->setFillColor(sf::Color::Green);
    if(!pSelectedSquares.empty())
    {
        pSelectedSquares[0]->setFillColor(sf::Color::Magenta);
    }
}





std::vector<std::vector<sf::RectangleShape>>* Playingfield::getGridAdress()
{
    return &grid;
}