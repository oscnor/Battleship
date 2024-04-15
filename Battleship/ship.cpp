#include "ship.hpp"

Ship::Ship(std::vector<sf::Vector2f> _position)
{
    position = _position;
    size = position.size();
};
Ship::~Ship(){};

std::vector<sf::Vector2f> Ship::getPosition()
{
    return position;
};