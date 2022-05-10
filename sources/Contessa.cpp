#include "Player.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace coup;

coup::Contessa::~Contessa(){}

void coup::Contessa::block(Player &p){
    /**
     *  if p's last move was assassination of as -> it's blocked.
     */
    this->pgame->game_stats_validation();
    Player *ptr = &p;

    if(ptr->get_last_move() == "assasin_coup"){
        this->pgame->revive();
    }
    else{
        throw invalid_argument("Contessa canot Block this action!");
    }
}

