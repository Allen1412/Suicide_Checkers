// <2462667>

#include "Board.h"

Board::Board()
{
    //ctor
}

Board::Board(int sz, int& player1, int& player2)
{
    // Board size must always be an even number that ranges from 6 to 12.
    if (sz %2 == 0 && sz>=6 && sz <=12){
        board_size = sz;
    }
    // 0 indicates that the game is playing
    game_finished_value = 0;

    //Number of players in the game is equal to (size/2)*(size/2-1) initially
    player1 = sz/2;
    player1 = player1*(player1-1);
    player2 = player1;
}

Board::~Board()
{
    //dtor
}

void Board::initialize_board(vector <vector <char>> &board){

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



void Board::print_board(vector <vector <char>> &board){

    for (int i = 0; i< board_size; i++){
        for (int j = 0; j< board_size; j++){

            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int Board::game_finished_state(){
    return game_finished_value;
}

void Board::update_game(int game_finished){

if (game_finished >=0 && game_finished<=3)
    game_finished_value = game_finished;
}
