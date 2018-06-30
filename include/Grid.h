#ifndef GRID_H
#define GRID_H
#include "../include/Rules.h"
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
     GridState getState();
     void clearState();
     void setRules(Rules rules);
     void tick();
     void draw(sf::RenderWindow& window);

private:
     void createContent();

     std::set<int> s_birth;
     std::set<int> s_survival;
     GridState g_curr;
     GridState g_next;
     GridContent g_tiles;
};


#endif
