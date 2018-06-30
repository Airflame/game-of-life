#include "../include/Grid.h"

Grid::Grid()
{
     g_curr = GridState(80, GridStateRow(80, false));
     g_next = GridState(80, GridStateRow(80, false));
     g_tiles = GridContent(80, GridContentRow(80, Tile()));
     for(int i = 0; i < 80; i++)
     {
          for(int j = 0; j < 80; j++)
          {
               g_tiles[i][j].setGridPosition(sf::Vector2f(i, j));
          }
     }
}

void Grid::setState(GridState arg)
{
     g_curr = arg;
     createContent();
     return;
}

GridState Grid::getState()
{
     return g_curr;
}

void Grid::clearState()
{
     g_curr = GridState(80, GridStateRow(80, false));
     g_next = GridState(80, GridStateRow(80, false));
     createContent();
     return;
}

void Grid::setRules(Rules rules)
{
     s_birth = rules.getBirthSet();
     s_survival = rules.getSurvivalSet();
     return;
}

void Grid::tick()
{
     for(int x = 0; x < 80; x++)
     {
          for(int y = 0; y < 80; y++)
          {
               int neigh = 0;
               for(int i = -1; i <= 1; i++)
               {
                    for(int j = -1; j <= 1; j++)
                    {
                         if(i == 0 and j == 0)
                              continue;
                         int ex = x + i;
                         int ey = y + j;
                         if(ex < 0)
                              ex += 80;
                         if(ex >= 80)
                              ex -= 80;
                         if(ey < 0)
                              ey += 80;
                         if(ey >= 80)
                              ey -= 80;
                         if(g_curr[ex][ey])
                              neigh++;
                    }
               }
               if(s_birth.find(neigh) != s_birth.end() and !g_curr[x][y])
                    g_next[x][y] = true;
               if(s_survival.find(neigh) != s_survival.end() and g_curr[x][y])
                    g_next[x][y] = true;
          }
     }
     g_curr = g_next;
     g_next = GridState(80, GridStateRow(80, false));
     createContent();
     return;
}

void Grid::draw(sf::RenderWindow& window)
{
     for(GridContentRow row : g_tiles)
     {
          for(Tile t : row)
               window.draw(t);
     }
     return;
}

void Grid::createContent()
{
     for(int i = 0; i < 80; i++)
     {
          for(int j = 0; j < 80; j++)
          {
               g_tiles[i][j].setState(g_curr[i][j]);
          }
     }
     return;
}
