#include <iostream>
#include <string>
#include <stdexcept>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;
using namespace coup;

constexpr int MAX_SIZE = 7;
constexpr int MAX_COIN = 10;

// Constructor / Deconstructor
coup::Player::Player(Game &g, string const &Name){
    g.size_and_start_check();
    this->pgame = &g;
    this->name = Name;
    this->pgame->add_player(name);
    this->coins_amount = 0;
    this->last_move = "";
    this->last_vict = NULL;
}
coup::Player::~Player(){}

// Player gets one coin 
void coup::Player::income(){
    this->pgame->game_stats_validation();
    if(this->name != this->pgame->turn()){
        throw invalid_argument("Cannot Use income, Not Your Turn!");
    }
    this->pgame->initialize();
    this->coins_amount +=  1;
    this->last_move = "income";
    this->pgame->end_turn();
}

// Player gets two coins - can be blocked! 
void coup::Player::foreign_aid(){
    this->pgame->game_stats_validation();
    if(this->coins() >= MAX_COIN){
        throw invalid_argument("You Have more Then 10 coins!");
    }
    if(this->name != this->pgame->turn()){
        throw invalid_argument("You Cannot Use 'foreign_aid', Not Your Turn!");
    }
    this->pgame->initialize();
    this->coins_amount +=  2;
    this->last_move = "foreign_aid";
    this->pgame->end_turn();  
}

// Return the players role.
string coup::Player::role(){
    return this->ch_role;
}

/**
 * @brief Coup - player attack other player for 7 coins - this action cant be blocked 
 * @param p = refrence to the plyer we want to attack.
 */
void coup::Player::coup(Player &p){
    this->pgame->game_stats_validation();
    if(this->coins_amount < MAX_SIZE){
        throw invalid_argument("Not Enough Coins!");
    }
    if(!(this->pgame->isActive(p.name))){
        throw invalid_argument("Player Already Dead!");
    }
    this->coins_amount -= MAX_SIZE;
    Player *ptr  = &p;
    this->pgame->kill(ptr->get_name());
    this->pgame->end_turn();
    this->last_move = "coup";
}
// Helper to send the last move this player done (each action the player does - this argument updated).
string coup::Player::get_last_move(){
    return this->last_move;
}

/**
 * Helpers:
 *   for increase or decrease the Players coins.
 */
void coup::Player::decreseByTwo(){
    this->coins_amount -= 2;
}
void coup::Player::decreseByOne(){
    this->coins_amount --;
}
void coup::Player::increseByOne(){
    this->coins_amount ++;
}
void coup::Player::increseByTwo(){
    this->coins_amount ++;
    this->coins_amount ++;
}
