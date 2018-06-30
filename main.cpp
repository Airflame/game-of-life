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
     float acc_max = 0.05;
     bool stopped = true;
     bool lpressed = false;
     bool rpressed = false;
     int px = -1;
     int py = -1;

     sf::RenderWindow window(sf::VideoMode(800, 800), "Game of life");

     while(window.isOpen())
     {
          window.clear(sf::Color::Black);
          grid.draw(window);

          if(!stopped)
          {
               acc += dt;
               if( acc > acc_max )
               {
                    grid.tick();
                    state = grid.getState();
                    acc = 0;
               }
          }

          sf::Event event;
          while(window.pollEvent(event))
          {
               if(event.type == sf::Event::Closed)
                    window.close();
               if(event.type == sf::Event::MouseButtonPressed)
               {
                    if(event.mouseButton.button == sf::Mouse::Left)
                         lpressed = true;
                    if(event.mouseButton.button == sf::Mouse::Right)
                         rpressed = true;
               }
               if(event.type == sf::Event::MouseButtonReleased)
               {
                    if(event.mouseButton.button == sf::Mouse::Left)
                         lpressed = false;
                    if(event.mouseButton.button == sf::Mouse::Right)
                         rpressed = false;
               }
               if(event.type == sf::Event::MouseMoved and stopped and (lpressed or rpressed))
               {
                    if(event.mouseMove.x/10 == px and event.mouseMove.y/10 == py)
                         continue;
                    if(lpressed)
                         state[event.mouseMove.x/10][event.mouseMove.y/10] = true;
                    if(rpressed)
                         state[event.mouseMove.x/10][event.mouseMove.y/10] = false;
                    px = event.mouseMove.x/10;
                    py = event.mouseMove.y/10;
                    grid.setState(state);
               }
               if(event.type == sf::Event::KeyPressed)
               {
                    if(event.key.code == sf::Keyboard::Enter)
                    {
                         if(stopped)
                              stopped = false;
                         else
                              stopped = true;
                    }
                    if(event.key.code == sf::Keyboard::Right and stopped)
                         grid.tick();
                    if(event.key.code == sf::Keyboard::Up and acc_max > 0.01)
                         acc_max -= 0.01;
                    if(event.key.code == sf::Keyboard::Down and acc_max < 1)
                         acc_max += 0.01;

               }
          }
          window.display();
          dt = clock.restart().asSeconds();
     }
     return 0;
}
