#include<iostream>
#include"game.h"

using namespace std;

int main()
{
    Game play;
    play.init_map();
    play.print_map();
    cout << endl << endl;
    char direction;
    while(1)
    {   
        cin >> direction;
        if(direction == 'P' || direction == 'p')
            break;
        switch(direction)
        {
            case 'W':
            case 'w':
                play.moveup();
                break;
            case 'S':
            case 's':
                play.movedown();
                break;
            case 'A':
            case 'a':
                play.moveleft();
                break;
            case 'D':
            case 'd':
                play.moveright();
                break;          
            case 'R':
            case 'r':
                play.restart();
                break;
            default:
                break;
        }
        play.print_score();
        play.print_map();
        cout << endl << endl;
        if(play.gameover() == true)
        {
            cout << "GAMEOVER" << endl << endl;
            break;
        }
    }
    return 0;
}