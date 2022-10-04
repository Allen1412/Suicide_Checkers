// <2462667>

// This class implements the playing rules for the game.

#ifndef RULES_H
#define RULES_H
#include <vector>
#include <iostream>
using namespace std;

class Rules
{
    public:
        Rules();
        ~Rules();
        bool is_forbidden(int row, int col, vector <vector <char>> board);//checks if the destination is not a dot or not beyond boundaries
        bool is_jumping(int& row_main, int& col_main, vector<vector<char>>& board, int& player1, int& player2);//checks for a must-jump move
        bool is_on_boundaries(int row,int col, vector<vector<char>> board);// checks if player is at the other end of play
        bool is_diagonal_up(int row1, int col1, int row2, int col2, vector<vector<char>> board);//move is diagonal going up
        bool is_diagonal_down(int row1, int col1, int row2, int col2, vector<vector<char>> board);//move is diagonal going down
        bool is_king(int row, int col, vector<vector<char>> board); // returns true if piece is crowned
        void make_king(int row, int col, vector<vector<char>>& board);//makes the king

    protected:

    private:
};

#endif // RULES_H
