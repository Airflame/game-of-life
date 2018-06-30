#ifndef RULES_H
#define RULES_H
#include <vector>
#include <set>
#include <string>
#include <fstream>


class Rules
{
public:
     Rules(std::string path);
     std::set<int> getBirthSet();
     std::set<int> getSurvivalSet();

private:
     std::set<int> birth;
     std::set<int> survival;
};

#endif
