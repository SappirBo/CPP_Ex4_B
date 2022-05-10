#include <iostream>
#include <string>
#include "Game.hpp"
#pragma once

using namespace std;

namespace coup
{
    class Player
    {
    protected:
        string name;
        string ch_role;
        int coins_amount;
        Game *pgame;
        string last_move;
        Player *last_vict;
    public:
        Player(Game &g, string const &Name);
        ~Player();

        void income ();
        void foreign_aid();
        void coup(Player &p);
        void add(string Name);

        void decreseByOne();
        void decreseByTwo();
        void increseByOne();
        void increseByTwo();

        string get_name(){return this->name;}
        string get_last_move();
        string role();
        int coins(){return this->coins_amount;} 
        Player *get_last_vic(){return this->last_vict;}

        /**
         * @brief Prints Out Player's stats: name, role, coins and last move.
         */
        void player_stats(){
            cout<< this->name <<" stats: \n" <<
                "   role: "<<this->ch_role<<endl<<
                "   coins: "<<this->coins()<<endl<<
                "   last move: "<< this->last_move<<endl;
        }
    };
}