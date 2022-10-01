// <2462667>

#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    vector <vector <char>> board;

    int sz = 12;
    Board bd (sz);
    bd.initialize_board(board);
    bd.print_board(board);
    return 0;
}
