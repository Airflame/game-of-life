#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>


class Tile : public sf::RectangleShape
{
public:
     Tile();
     void setGridPosition(sf::Vector2f pos);
     void setState(bool arg);
     bool isOn();

private:
     float size;
     bool on;
     sf::Color c_off;
     sf::Color c_on;
};


#endif
