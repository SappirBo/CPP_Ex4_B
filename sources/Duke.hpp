#include "Player.hpp"
#include <iostream>
#include <string>
#pragma once

using namespace std;
using namespace coup;

namespace coup
{
    class Duke: public coup::Player
    {
    public:
    Duke(Game &g, string Name): Player(g,Name){this->ch_role = "Duke";};
    ~Duke();
    void block(Player &p);
    void tax();
    };
}
