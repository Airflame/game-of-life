#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>


class Tile : public sf::RectangleShape
{
public:
     Tile();
     void setGridPosition(sf::Vector2f pos);
     void setState(bool arg);

private:
     float size;
     sf::Color c_off;
     sf::Color c_on;
};


#endif
