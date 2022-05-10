#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"

using namespace std;
using namespace coup;

constexpr int MAX_PLAYERS_SIZE = 6;
constexpr int MIN_PLAYERS_SIZE = 2;

coup::Game::Game(){
    this->size =0;
    this->turn_num=0;
    this->Start = false;
}
coup::Game::~Game(){}

// Return vector (as string) with all the names.
vector<string> coup::Game::players(){
    return this->players_list;
}

// Helper for adding players to this game (it called from the players Constructors or the revive).
void coup::Game::add_player(string const &name){
    this->players_list.push_back(name);
    this->size++;
}


/**
 * @brief Function for Calculate the next player (there is a counter for turn numbers % the number of players).
 * 
 * @return string - The name of the player turn.
 */
string coup::Game::turn(){
    size_t tmp = (size_t) this->turn_num % (unsigned int)this->size;
    return this->players_list.at( tmp );
}

/**
 * @brief Helper for ending the turn (each player that finish his turn call this function last).
 */
void coup::Game::end_turn(){
    this->turn_num++;
}


/**
 * @brief Function for eliminate other player - 
 *      it also re aranging the players list (after the eliminated player is out), and set the turn for the right player.
 * @param player_name = the player we want to eliminate.
 */
void coup::Game::kill(string const &player_name){
    int i=0;
    size_t num = 0;
    int flag = 0;
    for(; i<players_list.size();i++){
        if(player_name == players_list.at((size_t)i) &&  i == players_list.size()-1){
            this->players_out_loc.push_back((int) i);
            flag = 2;
        }
        else if(player_name == players_list.at((size_t)i) &&  i == 0){
            this->players_out_loc.push_back((int) i);
            flag = 3;
        }
        else if(player_name == players_list.at((size_t)i)){
            this->players_out_loc.push_back((int) i);
            flag = 1;
        }
    }
    if(flag == 0){
        throw invalid_argument("Player Doesn't Exist!");
    }
    if(flag == 1){
        vector<string> new_list;
        num = 0;
        for(; num <this->players_list.size(); num++){
            if(player_name != this->players_list.at(num)){
                new_list.push_back(this->players_list.at(num));
            }
        }
        this->players_out_list.push_back(player_name);
        this->players_list = new_list;
        this->turn_num -= this->size;
    }
    if(flag == 2){
        vector<string> new_list;
        num=0;
        for(; num < players_list.size()-1; num++){
            new_list.push_back(players_list.at(num));
        }
        this->players_out_list.push_back(player_name);
        this->players_list = new_list;
        this->turn_num = this->turn_num % this->size;
    }
    if(flag == 3){
        vector<string> new_list;
        num=1;
        for(; num < players_list.size(); num++){
            new_list.push_back(players_list.at(num));
        }
        this->players_out_list.push_back(player_name);
        this->players_list = new_list;
        this->turn_num--;
        this->turn_num -= this->size;
    }
    this->size--;
}

/**
 * @brief function for getting the winners name.
 * if the game  Has't Over or Has't Started it will throw.
 * @return string - name of the winner.
 */
string coup::Game::winner(){
    if(players_list.size() > 1){
        throw invalid_argument("The Game Has't Over Yet!");
    }
    if(!this->Start){
        throw invalid_argument("The Game Has't Started Yet!");
    }
    return this->players_list.at(0);
}

//Helper (Kepp the eliminated player's names).
void coup::Game::add_to_Out_list(string const &Name){
    this->players_out_list.push_back(Name);
}

/**
 * @brief Function for revive player - it brings the last player that got couped but in the gane (to the same order as before).
 * 
 */
void coup::Game::revive(){
    if(this->players_out_list.empty()){
        throw invalid_argument("No Players Out\n");
    }
    string tmp = this->players_out_list.at(this->players_out_list.size()-1);
    this->players_out_list.pop_back();
    int location = this->players_out_loc.at(this->players_out_loc.size()-1);
    this->players_out_loc.pop_back();
    vector<string> new_list;
    size_t i=0;
    size_t j=0;
    for(; i< location; i++){
        new_list.push_back(this->players_list.at(i));
    }
    new_list.push_back(tmp);
    for(i=(size_t)location; i< this->players_list.size(); i++){
        new_list.push_back(this->players_list.at(i));
    }
    if(location == 0){
        this->turn_num++;
    }
    this->players_list.clear();
    this->players_list = new_list;
    this->size++;
}

// Helper for checking if a player still in the game.
bool coup::Game::isActive(string const &n){
    bool ans = false;
    for(size_t i=0; i < this->players_list.size(); i++){
        if(this->players_list.at(i) == n){
            ans = true;
            break;
        }
    }
    return ans;
}

// Two functions to check if action is alowed (THe main functions for throwing).
void coup::Game::game_stats_validation(){
    if(this->players_list.size() < MIN_PLAYERS_SIZE ){
        throw invalid_argument("Not Enough Players! need to have more then 1.");
    }
    if(this->players_list.size() > MAX_PLAYERS_SIZE){
        throw invalid_argument("To Many Players! need to have less then 7.");
    }
}
void coup::Game::size_and_start_check(){
    if(this->players_list.size() >= MAX_PLAYERS_SIZE){
        throw invalid_argument("To Many Players!");
    }
    if(this->Start){
        throw invalid_argument("Game Already Started!");
    }
}

// Starting the game.
void coup::Game::initialize(){
    if(!this->Start){
        this->Start = true;
    }
}
