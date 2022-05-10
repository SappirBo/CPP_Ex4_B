#include "Player.hpp"
#include "Assassin.hpp"
#include <iostream>
#include <string>
#include "Game.hpp"

using namespace std;
using namespace coup;

constexpr int MAX_SIZE = 7;


coup::Assassin::~Assassin(){}

void coup::Assassin::coup(Player &p){
    this->pgame->game_stats_validation();
    /**
     * assassinate player 'p'. only Contessa can block the assassination.
     * 
     */
    
    Player *ptr  = &p;
    if(!(this->pgame->isActive(ptr->get_name()))){
        throw invalid_argument("Player Already Dead!");
    }
    if(this->coins() >= MAX_SIZE){
        this->last_move = "coup";
        for(int i=0;i<MAX_SIZE;i++){
            this->decreseByOne();
        }
        this->pgame->kill(ptr->get_name());
        this->pgame->end_turn();
    }
    else if(this->coins() >= 3){
        this->last_move = "assasin_coup";
        this->decreseByOne();
        this->decreseByTwo();
        this->last_vict = ptr;
        this->pgame->kill(ptr->get_name());
        this->pgame->end_turn();
    }
    else{
        throw invalid_argument("Not Enough Coins For Coup (3/7)");
    }
}

