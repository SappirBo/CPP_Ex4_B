#include "Player.hpp"
#include "Ambassador.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace coup;

coup::Ambassador::~Ambassador(){}

void coup::Ambassador::transfer(Player &p1, Player &p2){
    this->pgame->game_stats_validation();
    /**
     * can transfer 1 coin from p1 to p2.
     */
    Player *ptr1 = &p1;
    Player *ptr2 = &p2;
    if(ptr1->coins() <= 0 ){
        string s = ptr1->get_name();
        s += " Dont Have Enough Coins To Transfer!";
        throw invalid_argument(s);
    }

    ptr1->decreseByOne();
    ptr2->increseByOne();

    this->pgame->end_turn();
}

void coup::Ambassador::block(Player &p){
    this->pgame->game_stats_validation();
    /**
     *  Can Block p's action.
     */
    Player *ptr = &p;

    if(ptr->get_last_move() == "steal"){
        ptr->decreseByTwo();
        Player *vict = ptr->get_last_vic();
        vict->increseByTwo();
    }
    else{
        throw invalid_argument("Ambassador canot Block this action!");
    }
}

