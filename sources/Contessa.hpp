#include "Player.hpp"
#include <iostream>
#include <string>
#pragma once

using namespace std;

namespace coup
{
    class Contessa: public coup::Player
    {
    public:
    Contessa(Game &g, string Name): Player(g,Name){this->ch_role = "Contessa";};
    ~Contessa();

    void block(Player &p);
    };
}