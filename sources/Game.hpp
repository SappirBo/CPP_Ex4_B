#include <iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;

namespace coup
{
    class Game{
    protected:
        vector<string> players_list;
        vector<string> players_out_list;
        vector<int> players_out_loc;
        int size;
        int turn_num;
        bool Start;

    public:
        Game();
        ~Game();

        vector<string> players();
        void add_player(string const &name);
        string turn();
        void end_turn();
        string winner();

        void kill(string const &player_name);
        void add_to_Out_list(string const &Name);
        void revive();
        bool isActive(string const &n);
        
        void get_out_list(){
            cout<< "    Out: "<<endl;
            for(size_t i=0; i < this->players_out_list.size() ; i++){
                cout<<"     " <<"Location: "<<this->players_out_loc.at(i)<<") "<<this->players_out_list.at(i)<<endl;
            }
            cout<< "    Out, END. "<<endl;

        }
        void size_and_start_check();
        void game_stats_validation();
        void initialize();

        // Printing Out This Game Stats.
        void game_stats_print(){
            cout<<"Game Status:" << endl << "     "<< "Size: " << this->size << endl
                                         << "     "<< "Turn player num: " << this->turn_num << ", For: "<< this->turn() << endl
                                          << "     "<< "Players: " << endl;
            for(size_t i=0; i<this->players_list.size(); i++){
                cout << "     "<<"     "<<  i <<") " << players_list.at(i) << endl;
            }

        }
    };
}