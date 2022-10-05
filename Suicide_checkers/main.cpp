// <2462667>

#include <iostream>
#include "Board.h"
#include "Rules.h"
#include <cmath>
#include <cstdlib>

using namespace std;

// Random algorithm
void algorithm1(vector <vector<char>>& board, Board& bd, Rules rules, int& player1, int& player2);
//Non-random algorithm
void algorithm2(vector <vector<char>>& board, Board& bd, Rules rules, int& player1, int& player2);
// Function that forces a jump
bool must_jump(char plyr, char plyr_king, vector <vector<char>>& board, Board bd, Rules rules, int& player1, int& player2);
//Function that updates game variables
void make_update(vector <vector<char>>& board, Board& bd, Rules& rules, int player1, int player2);
//Function to find playable positions for either algorithm indicated by the character o for algorithm 1 and x for algorithm 2
void find_playable_positions(vector<vector<char>>&, Rules rules, char alg, vector <int>&, vector <int>&, vector <int>&, vector <int>&, vector <int>&, vector <int>&);







int main()
{
    vector <vector <char>> board;
    // Important coordinates tables
    int sz , player1, player2, counter;



    while (cin >> sz){


    Board bd (sz, player1, player2);
    Rules rules;
    counter = 0;

    bd.initialize_board(board);
    bd.print_board(board);
    cout << endl;



     while (bd.game_finished_state() == 0){

        //play in alternating turns
        if (counter %2 == 0){
            algorithm1(board, bd, rules, player1, player2);
            make_update(board, bd, rules, player1, player2);

            }
        else{
            algorithm2(board, bd, rules, player1, player2);
            make_update(board, bd, rules, player1, player2);

            }

            cout << "we done yet? :" << bd.game_finished_state() << endl;

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

        counter++;
    }



    }



    return 0;
}


















void algorithm1(vector <vector<char>>& board, Board& bd, Rules rules, int& player1, int& player2){

    vector <int> initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination;
    // character o represents algorithm 1
    char alg = 'o';
    find_playable_positions(board, rules, alg, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
    if(must_jump('o', 'O', board, bd, rules, player1, player2)){

         return;

    } else if(one_dimension_initial.size() >0){

            // Randomness
            srand(time(0));
            int position = rand() % one_dimension_initial.size();

            cout << "alg 1 from: " << one_dimension_initial.at(position)<< " to: " << one_dimension_destination.at(position)<< endl;



            // random initial position
            int row1 = initial_rows.at(position), col1 = initial_cols.at(position);
            // random destination position
            int row2 = destination_rows.at(position),col2 = destination_cols.at(position);

            if(board[row1][col1] == 'o')
            {
                board[row1][col1] = '#';
                board[row2][col2] = 'o';
                if(rules.is_on_boundaries(row2,col2,board))
                            rules.make_king(row2,col2,board);
                }
             else  if(board[row1][col1] == 'O')
            {
                board[row1][col1] = '#';
                board[row2][col2] = 'O';
                if(rules.is_on_boundaries(row2,col2,board))
                            rules.make_king(row2,col2,board);
                }

            bd.print_board(board);
            cout << endl << endl;

    }else{
                // if the previous conditions fails, then it is a draw since this one cannot move.
                bd.update_game(3);
            }



}













void algorithm2(vector <vector<char>>&board, Board& bd, Rules rules, int& player1, int& player2){

    vector <int> initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination;
    // character x represents algorithm 2 always
    char alg = 'x';
    find_playable_positions(board, rules, alg, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
    if(must_jump('x', 'X', board, bd, rules, player1, player2)){

                return;

    }else if (one_dimension_destination.size() > 0){



            int diff = 100, temp1 = 100, temp2 = 100, position = 100;

            // every possible destination column position is compared with the boundaries so that the nearest is chosen
            for (int i = 0; i < one_dimension_initial.size(); i++){



                temp1 = destination_rows.at(i) - 0;
                temp2 = (one_dimension_initial.size() -1 ) - destination_rows.at(i);

                if((temp1<=temp2) && (temp1 <= diff)){
                    diff = temp1;
                    position = i;
                }else if ((temp2<=temp1) && (temp2 <= diff)){
                    diff = temp1;
                    position = i;
                }

            }

            //initial coordinates
            int row1 = initial_rows.at(position), col1 = initial_cols.at(position);


            //final coordinates
            int row2 = destination_rows.at(position),col2 = destination_cols.at(position);

            if(board[row1][col1] == 'x')
            {
                board[row1][col1] = '#';
                board[row2][col2] = 'x';
                if(rules.is_on_boundaries(row2,col2,board))
                            rules.make_king(row2,col2,board);
                }
             else  if(board[row1][col1] == 'X')
            {
                board[row1][col1] = '#';
                board[row2][col2] = 'X';
                if(rules.is_on_boundaries(row2,col2,board))
                            rules.make_king(row2,col2,board);
                }

            cout << "alg 2 from: " << one_dimension_initial.at(position) << " To :" << one_dimension_destination.at(position) << endl;
            bd.print_board(board);
            cout << endl << endl;
            }

            else{
                // if the previous conditions fails, then it is a draw since this one cannot move.
                bd.update_game(3);
            }


}






bool must_jump(char plyr, char plyr_king, vector <vector<char>>& board, Board bd, Rules rules, int& player1, int& player2){


    //play a forced jump move if there is move
    for (int i =0; i < board.size(); i++){
        for (int j=0; j < board.size(); j++){
            if(board[i][j] == plyr || board[i][j] == plyr_king){
                    int a = i, b =j, jumps = 0;
                    while(rules.is_jumping(a,b,board,player1,player2)){

                        if(rules.is_on_boundaries(a,b,board))
                            rules.make_king(a,b,board);
                                jumps++;

                    }
                if(jumps>0){
                   bd.print_board(board);
                   cout << endl << endl;
                   return true;

                }
            }
        }
    }

    return false;
}







void make_update(vector <vector<char>>& board, Board& bd, Rules& rules, int player1, int player2){

    if(player1 == 0)
        bd.update_game(1);
    else if(player2 == 0)
        bd.update_game(2);

}







void find_playable_positions(vector<vector<char>>& board,Rules rules,char alg, vector <int>& initial_rows, vector <int>& initial_cols, vector <int>& destination_rows, vector <int>& destination_cols, vector <int>& one_dimension_initial, vector <int>& one_dimension_destination)

{
       int initial = 0;
       int finl = 0;
       int quotient = board.size()/2;

       for (int i = 0; i < board.size(); i++){
            for(int j =0; j< board.size(); j++){


                 if(alg == 'x'){
                         if (board[i][j] == 'x' || board[i][j] == 'X'){
                            if(rules.can_move_left_up_diagonally(i, j, board)){

                                initial_rows.push_back(i);
                                initial_cols.push_back(j);
                                destination_rows.push_back(i-1);
                                destination_cols.push_back(j-1);

                                // exuation to convert the 2D coordinates to 1D
                                initial = (i* quotient) + floor(j/2) + 1;
                                finl = (i-1)*(quotient) + floor((j-1)/2) + 1;

                                one_dimension_initial.push_back(initial);
                                one_dimension_destination.push_back(finl);

                            }
                            if(rules.can_move_right_up_diagonally(i, j, board)){

                                initial_rows.push_back(i);
                                initial_cols.push_back(j);
                                destination_rows.push_back(i-1);
                                destination_cols.push_back(j+1);

                                // exuation to convert the 2D coordinates to 1D
                                initial = (i*quotient) + floor(j/2) + 1;
                                finl = (i-1)*(quotient) + floor((j+1)/2) + 1;

                                one_dimension_initial.push_back(initial);
                                one_dimension_destination.push_back(finl);
                            }
                } else if(board[i][j] == 'X'){


                        if(rules.can_move_left_down_diagonally(i, j, board)){

                                initial_rows.push_back(i);
                                initial_cols.push_back(j);
                                destination_rows.push_back(i+1);
                                destination_cols.push_back(j-1);

                                // exuation to convert the 2D coordinates to 1D
                                initial = (i*quotient) + floor(j/2) + 1;
                                finl = ((i+1)*(quotient)) + floor((j-1)/2) + 1;

                                one_dimension_initial.push_back(initial);
                                one_dimension_destination.push_back(finl);

                            }
                            if(rules.can_move_right_down_diagonally(i, j, board)){

                                initial_rows.push_back(i);
                                initial_cols.push_back(j);
                                destination_rows.push_back(i+1);
                                destination_cols.push_back(j+1);

                                // exuation to convert the 2D coordinates to 1D
                                initial = (i*quotient) + floor(j/2) + 1;
                                finl = (i+1)*(quotient) + floor((j+1)/2) + 1;

                                one_dimension_initial.push_back(initial);
                                one_dimension_destination.push_back(finl);

                            }


                }

                }


                //Player 2 only moves down diagonally, either left or right, kings also move in these directions
                else if(alg == 'o')

                {


                    if (board[i][j] == 'o' ||  board[i][j] == 'O'){

                            if(rules.can_move_left_down_diagonally(i, j, board)){

                                initial_rows.push_back(i);
                                initial_cols.push_back(j);
                                destination_rows.push_back(i+1);
                                destination_cols.push_back(j-1);

                                // exuation to convert the 2D coordinates to 1D
                                initial = (i*quotient) + floor(j/2) + 1;
                                finl = ((i+1)*(quotient)) + floor((j-1)/2) + 1;

                                one_dimension_initial.push_back(initial);
                                one_dimension_destination.push_back(finl);

                            }
                            if(rules.can_move_right_down_diagonally(i, j, board)){

                                initial_rows.push_back(i);
                                initial_cols.push_back(j);
                                destination_rows.push_back(i+1);
                                destination_cols.push_back(j+1);

                                // exuation to convert the 2D coordinates to 1D
                                initial = (i*quotient) + floor(j/2) + 1;
                                finl = (i+1)*(quotient) + floor((j+1)/2) + 1;

                                one_dimension_initial.push_back(initial);
                                one_dimension_destination.push_back(finl);

                            }

                }else if(board[i][j] == 'O'){


                    if(rules.can_move_left_up_diagonally(i, j, board)){

                        initial_rows.push_back(i);
                        initial_cols.push_back(j);
                        destination_rows.push_back(i-1);
                        destination_cols.push_back(j-1);

                        // exuation to convert the 2D coordinates to 1D
                        initial = (i* quotient) + floor(j/2) + 1;
                        finl = (i-1)*(quotient) + floor((j-1)/2) + 1;

                        one_dimension_initial.push_back(initial);
                        one_dimension_destination.push_back(finl);

                    }
                    if(rules.can_move_right_up_diagonally(i, j, board)){

                        initial_rows.push_back(i);
                        initial_cols.push_back(j);
                        destination_rows.push_back(i-1);
                        destination_cols.push_back(j+1);

                        // exuation to convert the 2D coordinates to 1D
                        initial = (i*quotient) + floor(j/2) + 1;
                        finl = (i-1)*(quotient) + floor((j+1)/2) + 1;

                        one_dimension_initial.push_back(initial);
                        one_dimension_destination.push_back(finl);
                    }


                }



                }


            }
       }



}

