#include "Player.hpp"
#include <iostream>
#include <string>
#pragma once

using namespace std;
using namespace coup;

namespace coup
{
    class Ambassador: public coup::Player
    {
        public:
        Ambassador(Game &g, string Name): Player(g, Name){this->ch_role = "Ambassador";};
        ~Ambassador();
            
        void transfer(Player &p1, Player &p2);
        void block(Player &p);
    };
}