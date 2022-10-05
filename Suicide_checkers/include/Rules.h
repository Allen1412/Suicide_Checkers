// <2462667>

// This class implements the playing rules for the game.

#ifndef RULES_H
#define RULES_H
#include <vector>
using namespace std;

class Rules
{
    public:
        Rules();
        ~Rules();
        bool is_jumping(int& row_main, int& col_main, vector<vector<char>>& board, int& player1, int& player2);//checks for a must-jump move
        bool is_on_boundaries(int row,int col, vector<vector<char>> board);// checks if player is at the other end of play
        bool can_move_left_up_diagonally(int row, int col,vector<vector<char>> board);// checks if it is possible to move is diagonal going up
        bool can_move_left_down_diagonally(int row, int col,vector<vector<char>> board);// checks if it is possible to move is diagonal going up
        bool can_move_right_up_diagonally(int row, int col,vector<vector<char>> board);// checks if it is possible to move is diagonal going up
        bool can_move_right_down_diagonally(int row, int col,vector<vector<char>> board);// checks if it is possible to move is diagonal going up
        void make_king(int row, int col, vector<vector<char>>& board);//makes the king

    protected:

    private:
         bool is_forbidden(int, int, vector <vector <char>>);//checks if the destination is not a dot or not beyond boundaries
         bool is_king(int, int, vector<vector<char>>); // returns true if piece is crowned
};

#endif // RULES_H
