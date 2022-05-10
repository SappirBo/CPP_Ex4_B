#include "Player.hpp"
#include <iostream>
#include <string>
#pragma once

using namespace std;

namespace coup
{
    class Assassin: public coup::Player
    {
    public:
    Assassin(Game &g, string Name): Player(g,Name){this->ch_role = "Assassin";};
    ~Assassin();
    
    void coup(Player &p);
    void assasinate(Player &p);
    };
}