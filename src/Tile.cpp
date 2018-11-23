#include "../include/Tile.h"

Tile::Tile()
{
    size = 10;
    setSize(sf::Vector2f(size,size));
    c_off = sf::Color(0, 0, 50);
    c_on = sf::Color(200, 200, 0);
    setState(false);
    setOutlineThickness(1);
    setOutlineColor(sf::Color::Black);
}

void Tile::setGridPosition(sf::Vector2f pos)
{
    setPosition(sf::Vector2f(pos.x*size, pos.y*size));
    return;
}

void Tile::setState(bool arg)
{
    setFillColor(arg ? c_on : c_off);
    return;
}
