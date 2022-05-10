#include "Player.hpp"
#include <iostream>
#include <string>
#pragma once

using namespace std;

namespace coup
{
    class Captain: public coup::Player
    {
    public:
    Captain(Game &g, string Name): Player(g, Name){this->ch_role = "Captain";};
    ~Captain();
    void block(Player &p);
    void steal(Player &p);
    };
}