// <2462667>

#include <iostream>
#include "Board.h"
#include "Rules.h"

using namespace std;

void algorithm1(vector <vector<char>>& board, Board bd, Rules rules, int& player1, int& player2);
void algorithm2(vector <vector<char>>& board, Board bd, Rules rules, int& player1, int& player2);
bool must_jump(char plyr, char plyr_king, vector <vector<char>>& board, Board bd, Rules rules, int& player1, int& player2);

int main()
{
    vector <vector <char>> board;
    int sz = 6, player1, player2;

    Board bd (sz, player1, player2);
    Rules rules;

    bd.initialize_board(board);
    bd.print_board(board);
    int i = 0;

    while (bd.game_finished_state() == 0){

        if (i%2 == 0)
            algorithm1(board, bd, rules, player1, player2);
        else
            algorithm2(board, bd, rules, player1, player2);

        if (bd.game_finished_state() == 1)
       {
           cout << "player 1 wins" << endl;
           break;
       }
    else if(bd.game_finished_state() == 2)
        {
            cout << "player 2 wins" << endl;
            break;
        }

        i++;
    }



    return 0;
}


void algorithm1(vector <vector<char>>& board, Board bd, Rules rules, int& player1, int& player2){

    if(must_jump('o', 'O', board, bd, rules, player1, player2))
        return;
    int row1, col1, row2,col2;
    cout << "o initial row position:" << endl;
    cin >> row1;
    cout << "o initial col position:" << endl;
    cin >> col1;

    cout << "o destination row position:" << endl;
    cin >> row2;
    cout << "o destination col position:" << endl;
    cin >> col2;

    if(board[row1][col1] == 'o')
    {
        board[row1][col1] = '#';
        board[row2][col2] = 'o';
        }
     else  if(board[row1][col1] == 'O')
    {
        board[row1][col1] = '#';
        board[row2][col2] = 'O';
        }

    bd.print_board(board);
    cout << endl;

}
void algorithm2(vector <vector<char>>&board, Board bd, Rules rules, int& player1, int& player2){

    if(must_jump('x', 'X', board, bd, rules, player1, player2))
        return;
    int row1, col1, row2,col2;
    cout << "x initial row position:" << endl;
    cin >> row1;
    cout << "x initial col position:" << endl;
    cin >> col1;

    cout << "x destination row position:" << endl;
    cin >> row2;
    cout << "x destination col position:" << endl;
    cin >> col2;

    if(board[row1][col1] == 'x')
    {
        board[row1][col1] = '#';
        board[row2][col2] = 'x';
        }
     else  if(board[row1][col1] == 'X')
    {
        board[row1][col1] = '#';
        board[row2][col2] = 'X';
        }
    bd.print_board(board);
    cout << endl;

}






bool must_jump(char plyr, char plyr_king, vector <vector<char>>& board, Board bd, Rules rules, int& player1, int& player2){


    //play a forced jump move if there is move
    for (int i =0; i < board.size(); i++){
        for (int j=0; j < board.size(); j++){
            if(board[i][j] == plyr || board[i][j] == plyr_king){
                    int a = i, b =j, jumps = 0;
                    while(rules.is_jumping(a,b,board,player1,player2)){
                        if(player1 == 0)
                            bd.update_game(1);

                        else if(player2 == 0)
                            bd.update_game(2);

                        if(rules.is_on_boundaries(a,b,board))
                            rules.make_king(a,b,board);
                                jumps++;

                    }
                if(jumps>0){
                   bd.print_board(board);
                   cout << endl;
                   return true;

                }
            }
        }
    }

    return false;
}


