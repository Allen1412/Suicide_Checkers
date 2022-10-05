// <2462667>


/// This class initialises the board,
#ifndef BOARD_H
#define BOARD_H
#include <vector> // This allows us to use vectors, since the board is a 2D vector.

using namespace std;

class Board
{
    public:
        Board();
        Board(int, int&, int&);// To initialise player1, player2 and
        ~Board();
        void initialize_board(vector <vector <char>>&);
        int game_finished_state();// Returns the game_finished value for a draw, win or continuing state
        void update_game(int);// updates game_finished_value

    protected:

    private:
        int board_size;
        int game_finished_value;// 0 when the game is playing, 1 if player1 wins, 2 if player2 wins, and 3 for a draw


};

#endif // BOARD_H
