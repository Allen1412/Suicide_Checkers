// <2462667>

#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    vector <vector <char>> board;

    int sz = 12, player1, player2;
    Board bd (sz, player1, player2);
    bd.initialize_board(board);
    bd.print_board(board);
    int i = 0;
/*
    while (bd.game_finished_state() == 0){

        if (i%2 == 0)
            algorithm1();
        else
            algorithm2();
    }*/
    return 0;
}
