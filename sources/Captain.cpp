#include "Player.hpp"
#include "Captain.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace coup;


coup::Captain::~Captain(){}

void coup::Captain::block(Player &p){
    /**
     *  Can Block p's action.
     */
    this->pgame->game_stats_validation();
    Player *ptr = &p;

    if(ptr->get_last_move() == "steal"){
        ptr->decreseByTwo();
    }
    else{
        throw invalid_argument("Captain canot Block this action!");
    }
}

void coup::Captain::steal(Player &p){
    /**
     *  Captain can steal 2 coins from p.
     */
    if(this->name != this->pgame->turn()){
        throw invalid_argument("Not Your Turn!");
    }
    this->pgame->game_stats_validation();
    Player *ptr = &p;
    if(ptr->coins() >= 2){
        ptr->decreseByTwo();
        this->increseByTwo();
        this->last_vict = ptr;
        this->last_move = "steal";
        this->pgame->end_turn();
    }
    else if(ptr->coins() == 1){
        ptr->decreseByOne();
        this->increseByOne();
        this->last_move = "steal";
        this->last_vict = ptr;
        this->pgame->end_turn();
    }
}














