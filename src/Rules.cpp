#include "../include/Rules.h"

Rules::Rules(std::string path)
{
     std::ifstream file;
     file.open(path);
     int id = 0;
     char input;
     while(!file.eof())
     {
          file >> input;
          if(input == 'B')
          {
               id = 1;
               continue;
          }
          if(input == 'S')
          {
               id = 2;
               continue;
          }
          int n = input - '0';
          switch(id)
          {
               case 1:
                    birth.insert(n);
                    break;

               case 2:
                    survival.insert(n);
                    break;
          }
     }
     file.close();
}

std::set<int> Rules::getBirthSet()
{
     return birth;
}

std::set<int> Rules::getSurvivalSet()
{
     return survival;
}
