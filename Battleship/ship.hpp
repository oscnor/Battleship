#ifndef SHIP
#define SHIP

#include <SFML/Graphics.hpp>
#include <vector>

class Ship
{
private:
    std::vector<sf::Vector2f> position;
    int size;
public:
    Ship(std::vector<sf::Vector2f> _position);
    ~Ship();
    std::vector<sf::Vector2f> getPosition();

};

#endif