#include "Board.h"

Board::Board()
{
    //ctor
}

Board::Board(int sz)
{
    if (sz %2 == 0 && sz>=6 && sz <=12){
        board_size = sz;
    }

    initialize_board();
}

Board::~Board()
{
    //dtor
}

void Board::initialize_board(){

    // The number of rows a player must occupy is board size divided by 2 minus 1
    int player_rows = (board_size / 2) -1;

for (int i = 0; i < board_size; i++){

    // 1 D vector to temporarily store the column values
    vector <char> temp;

    for (int j = 0; j< board_size; j++){

        if (j%2 == 0 && i%2 ==0)             // mark positions where play is not allowed as '.'
            temp.push_back('.');
            else if (j%2 != 0 && i%2 !=0)               // mark positions where play is not allowed as '.'
                temp.push_back('.');
            else if(i<player_rows)           // Player 1 denoted with the character 'o'
                temp.push_back('o');
            else if(i >= (player_rows + 2))  // Player 2 denoted with the character 'x'
                temp.push_back('x');
            else
                temp.push_back('#');
    }

    board.push_back(temp);
}


}

void Board::print_board(){

    for (int i = 0; i< board_size; i++){
        for (int j = 0; j< board_size; j++){

            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
