#ifndef GRID_H
#define GRID_H
#include <vector>
#include <set>
#include "../include/Tile.h"


typedef std::vector<std::vector<bool>> GridState;
typedef std::vector<bool> GridStateRow;
typedef std::vector<std::vector<Tile>> GridContent;
typedef std::vector<Tile> GridContentRow;

class Grid
{
public:
     Grid();
     void setState(GridState arg);
     void setRules(std::vector<int> arg1, std::vector<int> arg2);
     void tick();
     void draw(sf::RenderWindow& window);

private:
     void createContent();

     std::set<int> s_begin;
     std::set<int> s_stay;
     Tile temp;
     GridState g_curr;
     GridState g_next;
     GridContent g_tiles;
};


#endif
