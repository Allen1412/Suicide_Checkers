// <2462667>

#include "Board.h"
#include "Rules.h"
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

// Random algorithm
void algorithm1(vector <vector<char>>& board, Board& bd, Rules rules, int& player1, int& player2, ofstream& output);
//Non-random algorithm
void algorithm2(vector <vector<char>>& board, Board& bd, Rules rules, int& player1, int& player2, ofstream& output);
// Function that forces a jump
bool must_jump(char plyr, char plyr_king, vector <vector<char>>& board, Board bd, Rules rules, int& player1, int& player2, ofstream& output);
//Function that updates game variables
void make_update(vector <vector<char>>& board, Board& bd, Rules& rules, int player1, int player2);
//Function to find playable positions for either algorithm indicated by the character o for algorithm 1 and x for algorithm 2
void find_playable_positions(vector<vector<char>>&, Rules rules, char alg, vector <int>&, vector <int>&, vector <int>&, vector <int>&, vector <int>&, vector <int>&);
void fill_positions(int i, int j, int i_, int j_, int initial,int destination ,vector <int>&, vector <int>&, vector <int>&, vector <int>&, vector <int>&, vector <int>&);








int main()
{
    vector <vector <char>> board;
    // Important coordinates tables
    int sz , player1, player2, counter;

    // board sizes will be read from a text file called input.txt
    ifstream input("input.txt");

    ofstream output("output.txt");


    if(input.is_open()){


                            while (input >> sz){

                            output << sz << endl;
                            Board bd (sz, player1, player2);
                            Rules rules;
                            counter = 0;
                            bd.initialize_board(board);

                             while (bd.game_finished_state() == 0){

                                //play in alternating turns
                                if (counter %2 == 0){
                                    algorithm1(board, bd, rules, player1, player2, output);
                                    make_update(board, bd, rules, player1, player2);

                                    }
                                else{
                                    algorithm2(board, bd, rules, player1, player2, output);
                                    make_update(board, bd, rules, player1, player2);

                                    }

                                if (bd.game_finished_state() == 1)
                                {
                                   output << "tp1 " << player1 << endl;
                                   output << "tp2 " << player2 <<endl;
                                   output << "wp1" << endl << endl;
                                   board.clear();
                                   break;
                                }
                                else if(bd.game_finished_state() == 2)
                                {
                                   output << "tp1 " << player1 << endl;
                                   output << "tp2 " << player2 <<endl;
                                   output << "wp2" << endl << endl;
                                   board.clear();
                                   break;
                                }
                                else if (bd.game_finished_state() == 3){

                                   output << "tp1 " << player1 << endl;
                                   output << "tp2 " << player2 <<endl;
                                   output << "d" << endl << endl;
                                   board.clear();
                                   break;
                                }

                                counter++;
                            }



                            }

       // Safely closing files
        input.close();
        output.close();

    }

    return 0;
}


















void algorithm1(vector <vector<char>>& board, Board& bd, Rules rules, int& player1, int& player2, ofstream& output){

    vector <int> initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination;
    // character o represents algorithm 1
    char alg = 'o';
    find_playable_positions(board, rules, alg, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);

    if(must_jump('o', 'O', board, bd, rules, player1, player2, output)){

         return;

    } else if(one_dimension_initial.size() >0){

            // Randomness
            srand(time(0));
            int position = (rand()%one_dimension_initial.size());


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

            output << "p1 " << one_dimension_initial.at(position)<< "-" << one_dimension_destination.at(position)<< endl;

    }else{
                // if the previous conditions fails, then it is a draw since this one cannot move.
                bd.update_game(3);
            }


        initial_rows.clear();
        initial_cols.clear();
        destination_rows.clear();
        destination_cols.clear();
        one_dimension_initial.clear();
        one_dimension_destination.clear();

}













void algorithm2(vector <vector<char>>&board, Board& bd, Rules rules, int& player1, int& player2, ofstream& output){

    vector <int> initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination;
    // character x represents algorithm 2 always
    char alg = 'x';
    find_playable_positions(board, rules, alg, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
    if(must_jump('x', 'X', board, bd, rules, player1, player2, output)){

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

            output << "p2 " << one_dimension_initial.at(position)<< "-" << one_dimension_destination.at(position)<< endl;
            }

            else{
                // if the previous conditions fails, then it is a draw since this one cannot move.
                bd.update_game(3);
            }

            initial_rows.clear();
            initial_cols.clear();
            destination_rows.clear();
            destination_cols.clear();
            one_dimension_initial.clear();
            one_dimension_destination.clear();

}






bool must_jump(char plyr, char plyr_king, vector <vector<char>>& board, Board bd, Rules rules, int& player1, int& player2, ofstream& output){


    //play a forced jump move if there is move
    for (int i =0; i < board.size(); i++){
        for (int j=0; j < board.size(); j++){
            if(board[i][j] == plyr || board[i][j] == plyr_king){
                    int a = i, b =j, jumps = 0;
                    while(rules.is_jumping(a,b,board,player1,player2)){

                            if(plyr == 'o' && jumps == 0){
                                output << "p1 ";
                            }else if (plyr == 'x' && jumps == 0){
                                output << "p2 ";
                            }

                                int jumped_row = (a+i)/2;
                                int jumped_col = (b+j)/2;

                                int initial = i*(board.size()/2) + ceil(j/2) +1;
                                int jumped = jumped_row*(board.size()/2) + ceil(jumped_col/2) +1;
                                int destination = a*(board.size()/2) + ceil(b/2) +1;

                                output << initial << "x" << destination << "(" << jumped<< ")";


                        if(rules.is_on_boundaries(a,b,board))
                            rules.make_king(a,b,board);
                                jumps++;

                    }
                if(jumps>0){
                   output << endl;
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
       int destination = 0;
       int quotient = board.size()/2;

       for (int i=0; i<board.size(); i++){
            for (int j = 0; j < board.size(); j++){

                if(alg == 'x'){

                    if (board[i][j] == 'x'){

                        if(rules.can_move_left_up_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i-1)*quotient + ceil((j-1)/2) +1;
                            fill_positions(i, j, i-1, j-1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                        }

                        if(rules.can_move_right_up_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i-1)*quotient + ceil((j+1)/2) +1;
                            fill_positions(i, j, i-1, j+1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                        }

                    }

                    if (board[i][j] == 'X'){

                        if(rules.can_move_left_up_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i-1)*quotient + ceil((j-1)/2) +1;
                            fill_positions(i, j, i-1, j-1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                        }

                        if(rules.can_move_right_up_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i-1)*quotient + ceil((j+1)/2) +1;
                            fill_positions(i, j, i-1, j+1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                        }

                        if(rules.can_move_left_down_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i+1)*quotient + ceil((j-1)/2) +1;
                            fill_positions(i, j, i+1, j-1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                        }

                        if(rules.can_move_right_down_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i+1)*quotient + ceil((j+1)/2) +1;
                            fill_positions(i, j, i+1, j+1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                        }
                    }

                }else if (alg == 'o'){

                        if(board[i][j]== 'o'){

                            if(rules.can_move_left_down_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i+1)*quotient + ceil((j-1)/2) +1;
                            fill_positions(i, j, i+1, j-1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                          }

                            if(rules.can_move_right_down_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i+1)*quotient + ceil((j+1)/2) +1;
                            fill_positions(i, j, i+1, j+1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                             }


                        }

                        if(board[i][j] == 'O'){


                                if(rules.can_move_left_up_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i-1)*quotient + ceil((j-1)/2) +1;
                            fill_positions(i, j, i-1, j-1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                                   }


                                   if(rules.can_move_right_up_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i-1)*quotient + ceil((j+1)/2) +1;
                            fill_positions(i, j, i-1, j+1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                                      }


                                    if(rules.can_move_left_down_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i+1)*quotient + ceil((j-1)/2) +1;
                            fill_positions(i, j, i+1, j-1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                                  }

                                  if(rules.can_move_right_down_diagonally(i, j, board)){

                            initial = i*quotient + ceil(j/2) +1;
                            destination = (i+1)*quotient + ceil((j+1)/2) +1;
                            fill_positions(i, j, i+1, j+1, initial, destination, initial_rows, initial_cols, destination_rows, destination_cols, one_dimension_initial, one_dimension_destination);
                                     }

                        }


                }
            }
       }


}




void fill_positions(int i, int j, int i_, int j_,int initial, int destination,vector <int>& initial_rows, vector <int>& initial_cols, vector <int>& destination_rows, vector <int>& destination_cols, vector <int>& one_dimension_initial, vector <int>& one_dimension_destination){

                        initial_rows.push_back(i);
                        initial_cols.push_back(j);
                        destination_rows.push_back(i_);
                        destination_cols.push_back(j_);
                        one_dimension_initial.push_back(initial);
                        one_dimension_destination.push_back(destination);

}


