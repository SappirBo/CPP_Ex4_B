#include "Player.hpp"
#include "Duke.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace coup;


coup::Duke::~Duke(){}

void coup::Duke::block(Player &p){
    this->pgame->game_stats_validation();
    /**
     *  Can Block p's action.
     */
    Player *ptr = &p;

    if(ptr->get_last_move() == "foreign_aid"){
        ptr->decreseByTwo();
    }
    else{
        throw invalid_argument("Duke canot Block this action!");
    }
}

void coup::Duke::tax(){
    this->pgame->game_stats_validation();
    for(int i=0; i<3; i++){
        this->increseByOne();
    }
    this->pgame->end_turn();
}
