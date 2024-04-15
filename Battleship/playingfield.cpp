#include "playingfield.hpp"

// Contructor 
Playingfield::Playingfield(bool _player,int _rectangleSize, sf::RenderWindow &_window)
{
    player = _player;
    rectangleSize = _rectangleSize;
    friendlyGrid.resize(gridSize);
    enemyGrid.resize(gridSize);
    buttonPressed = false;

    pWindow = &_window;
    // Initialize rectangle to be used as template for rest
    sf::RectangleShape friendRec(sf::Vector2f(rectangleSize,rectangleSize));
    friendRec.setOutlineThickness(1);
    friendRec.setPosition(rectangleSize*friendlyGridOffset ,rectangleSize*2);
    friendRec.setOutlineColor(sf::Color::Black);

    sf::RectangleShape enemyRec(friendRec);
    enemyRec.setOutlineColor(sf::Color::Red);
    enemyRec.setPosition(rectangleSize,rectangleSize*2);

    invisibleSquare.setPosition(-rectangleSize,-rectangleSize);
    pMarkedSquare = &invisibleSquare;
    
    for(int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            friendRec.setPosition(friendRec.getPosition().x+rectangleSize, friendRec.getPosition().y);
            enemyRec.setPosition(enemyRec.getPosition().x+rectangleSize, enemyRec.getPosition().y);
            friendlyGrid[i].push_back(sf::RectangleShape(friendRec));
            enemyGrid[i].push_back(sf::RectangleShape(enemyRec));            
        }
        friendRec.setPosition(rectangleSize*friendlyGridOffset, friendRec.getPosition().y+rectangleSize);
        enemyRec.setPosition(rectangleSize, enemyRec.getPosition().y+rectangleSize);
    }

    pMarkedSquare = &enemyGrid[0][0];
}

// Destructor
Playingfield::~Playingfield()
{
    //delete gridInFocus;
    //delete pMarkedSquare;
    //for(auto p: pSelectedSquares)
    //{
    //    delete p;
    //}
    //pSelectedSquares.clear(); 
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
void Playingfield::setButtonPressed(bool setButtonPressed)
{
    buttonPressed = setButtonPressed;
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
    if(!buttonPressed)
    {
        pSelectedSquares.push_back(pMarkedSquare);   
    }   
    else if(buttonPressed)
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
            pWindow->draw(friendlyGrid[i][j]);
        }
    }
    for(int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j<gridSize; j++)
        {   
            pWindow->draw(enemyGrid[i][j]);
        }
    }
}

void Playingfield::lightMarkedSquare()
{
    mousePos = sf::Mouse::getPosition(*pWindow);
    pMarkedSquare->setFillColor(sf::Color::White);
    hoveringSquare();
    pMarkedSquare->setFillColor(sf::Color::Green);
    if(pSelectedSquares.size() > 0)
    {
        pSelectedSquares[0]->setFillColor(sf::Color::Magenta);
    }
}