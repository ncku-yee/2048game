#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Game 
{
    public :
        Game();
//        ~Game();
        int map[4][4];
        int score = 0;
        int check_map[4][4];
        void copy_map();
        void init_map();
        void print_map();
        void print_score();
        void moveup();
        void movedown();
        void moveleft();
        void moveright();
        bool add_up();
        bool add_down();
        bool add_left();
        bool add_right();
        void pop_num();
        bool gameover();
        void restart();
};