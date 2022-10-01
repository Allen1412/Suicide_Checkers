#ifndef BOARD_H
#define BOARD_H
#include <vector> // This allows us to use vectors, since the board is a 2D vector.
#include <iostream>

#include <iostream>

using namespace std;

class Board
{
    public:
        Board();
        Board(int sz);
        ~Board();
        void print_board(vector <vector <char>>&);
        void initialize_board(vector <vector <char>>&);

    protected:

    private:
        int board_size;

};

#endif // BOARD_H
