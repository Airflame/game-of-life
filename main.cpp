#include <iostream>
#include "include/Grid.h"

int main()
{
     sf::Clock clock;
     float dt = 0;

     GridState state(80, GridStateRow(80, false));
     state[10][11] = true;
     state[11][10] = true;
     state[12][10] = true;
     state[12][11] = true;
     state[12][12] = true;

     Grid grid;
     grid.setRules({3}, {2, 3});
     grid.setState(state);

     float acc = 0;

     sf::RenderWindow window(sf::VideoMode(800, 800), "Game of life");

     while(window.isOpen())
     {
          window.clear(sf::Color::Black);
          grid.draw(window);

          acc += dt;
          if( acc > 0.05 )
          {
               grid.tick();
               acc = 0;
          }

          sf::Event event;
          while(window.pollEvent(event))
          {
               if(event.type == sf::Event::Closed)
                    window.close();
          }
          window.display();
          dt = clock.restart().asSeconds();
     }
     return 0;
}
