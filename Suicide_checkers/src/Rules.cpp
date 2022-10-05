#include "Rules.h"


Rules::Rules()
{
    //ctor
}

Rules::~Rules()
{
    //dtor
}

 bool Rules::is_forbidden(int row, int col, vector<vector<char>> board){
     if (row >= board.size() || col >=board.size() || row <0 || col<0){

        return true;
     }else if(board[row][col] == '.')
            return true;

            return false;
 }

 bool Rules::is_jumping(int& row_main, int& col_main, vector<vector<char>>& board, int& player1, int& player2){

    int row = row_main;
    int col = col_main;
    char plyr;

    if(!is_forbidden(row, col, board))
        plyr = board[row][col];



    if(plyr=='x'){
        if(!is_forbidden(row-1, col+1, board)&& !is_forbidden(row-2, col+2, board) && (board[row-1][col+1] == 'o' || board[row-1][col+1] == 'O') && board[row-2][col+2] == '#')
            {
                board[row][col] = '#';
                player1--;
                board[row-1][col+1] = '#';
                board[row-2][col+2] = 'x';
                row_main = row-2;
                col_main  = col+2;
                //is_jumping(row_main, col_main, board, player1, player2);
                return true;
            }
            else if(!is_forbidden(row-1, col-1, board)&& !is_forbidden(row-2, col-2, board) && (board[row-1][col-1] == 'o' || board[row-1][col-1] == 'O') && board[row-2][col-2] == '#')
                {

                    board[row][col] = '#';
                    player1--;
                    board[row-1][col-1] = '#';
                    board[row-2][col-2] = 'x';
                    row_main = row-2;
                    col_main  = col-2;
                    return true;
                }
     } else if(plyr == 'o'){
            if(!is_forbidden(row+1, col+1, board)&& !is_forbidden(row+2, col+2, board)&&(board[row+1][col+1] == 'x' || board[row+1][col+1] == 'X') && board[row+2][col+2] == '#')
                {

                    board[row][col] = '#';
                    player2--;
                    board[row+1][col+1] = '#';
                    board[row+2][col+2] = 'o';
                    row_main = row+2;
                    col_main  = col+2;
                    row = row_main;
                    col = col_main;

                    return true;
                }
                else if(!is_forbidden(row+1, col-1, board)&& !is_forbidden(row+2, col-2, board) && (board[row+1][col-1] == 'x' || board[row+1][col-1] == 'X') && board[row+2][col-2] == '#')
                    {
                        board[row][col] = '#';
                        player2--;
                        board[row+1][col-1] = '#';
                        board[row+2][col-2] = 'o';
                        row_main = row+2;
                        col_main  = col-2;
                        return true;
                    }


     }

     else if(plyr == 'X' || plyr == 'O'){



         if(!is_forbidden(row-1, col+1, board)&& !is_forbidden(row-2, col+2, board) && board[row-2][col+2] == '#'){

                    if (plyr == 'X' && (board[row-1][col+1] == 'o' || board[row-1][col+1] == 'O')){
                         board[row][col] = '#';
                         player1--;
                         board[row-1][col+1] = '#';
                         board[row-2][col+2] = 'X';
                         row_main = row-2;
                         col_main  = col+2;
                         return true;
                    }else if (plyr == 'O' && (board[row-1][col+1] == 'x' || board[row-1][col+1] == 'X')){
                         board[row][col] = '#';
                         player2--;
                         board[row-1][col+1] = '#';
                         board[row-2][col+2] = 'O';
                         row_main = row-2;
                         col_main  = col+2;
                         return true;
                    }



         }

        else if (!is_forbidden(row-1, col-1, board)&& !is_forbidden(row-2, col-2, board) && board[row-2][col-2] == '#'){

                    if (plyr == 'X' && (board[row-1][col-1] == 'o' || board[row-1][col-1] == 'O')){

                         board[row][col] = '#';
                         player1--;
                         board[row-1][col-1] = '#';
                         board[row-2][col-2] = 'X';
                         row_main = row-2;
                         col_main  = col-2;
                         return true;
                    }else if (plyr == 'O' && (board[row-1][col-1] == 'x' || board[row-1][col-1] == 'X')){
                         board[row][col] = '#';
                         player2--;
                         board[row-1][col-11] = '#';
                         board[row-2][col-2] = 'O';
                         row_main = row-2;
                         col_main  = col-2;
                         return true;
                    }



                }

        else if(!is_forbidden(row+1, col+1, board)&& !is_forbidden(row+2, col+2, board) && board[row+2][col+2] == '#'){


                                                if (plyr == 'X' && (board[row+1][col+1] == 'o' || board[row+1][col+1] == 'O')){
                                                     board[row][col] = '#';
                                                     player1--;
                                                     board[row+1][col+1] = '#';
                                                     board[row+2][col+2] = 'X';
                                                     row_main = row+2;
                                                     col_main  = col+2;
                                                     return true;
                                                }else if (plyr == 'O' && (board[row-1][col+1] == 'x' || board[row+1][col+1] == 'X')){
                                                     board[row][col] = '#';
                                                     player2--;
                                                     board[row+1][col+1] = '#';
                                                     board[row+2][col+2] = 'O';
                                                     row_main = row+2;
                                                     col_main  = col+2;
                                                     return true;
                                                }



                                    }
    if(!is_forbidden(row+1, col-1, board)&& !is_forbidden(row+2, col-2, board) && board[row+2][col-2] == '#'){


                    if (plyr == 'X' && (board[row+1][col-1] == 'o' || board[row+1][col-1] == 'O')){

                         board[row][col] = '#';
                         player1--;
                         board[row+1][col-1] = '#';
                         board[row+2][col-2] = 'X';
                         row_main = row+2;
                         col_main  = col-2;
                         return true;
                    }else if (plyr == 'O' && (board[row+1][col-1] == 'x' || board[row+1][col-1] == 'X')){
                         board[row][col] = '#';
                         player2--;
                         board[row+1][col-1] = '#';
                         board[row+2][col-2] = 'O';
                         row_main = row+2;
                         col_main  = col-2;
                         return true;
                    }



     }

     }
     return false;

}


bool Rules::is_on_boundaries(int row, int col, vector <vector<char>> board){

    if (board[row][col] == 'o'&& row == board.size() - 1)
        return true;
    else if(board[row][col] == 'x' && row == 0 )
        return true;

        return false;
}

void Rules::make_king(int row, int col, vector<vector<char>>& board){
    //Opponent at the other boundary is king
    if (board[row][col] == 'x')
        board[row][col] = 'X';
    else
        board[row][col] = 'O';


}

bool Rules::is_king(int row, int col, vector<vector<char>> board){
    if(board[row][col] == 'X' || board[row][col] == 'O')
        return true;

    return false;
}


bool Rules::can_move_left_up_diagonally(int row, int col,vector<vector<char>> board){

    if(!is_forbidden(row, col, board) && !is_forbidden(row-1, col-1, board) && board[row - 1][col-1] == '#')
        return true;

    return false;
}
bool Rules::can_move_left_down_diagonally(int row, int col,vector<vector<char>> board){
if(!is_forbidden(row, col, board) && !is_forbidden(row+1, col-1, board) && board[row + 1][col-1] == '#')
        return true;

    return false;

}
bool Rules::can_move_right_up_diagonally(int row, int col,vector<vector<char>> board){
if(!is_forbidden(row, col, board) && !is_forbidden(row-1, col+1, board) && board[row - 1][col+1] == '#')
        return true;

    return false;

}
bool Rules::can_move_right_down_diagonally(int row, int col,vector<vector<char>> board){
if(!is_forbidden(row, col, board) && !is_forbidden(row+1, col+1, board) && board[row + 1][col+1] == '#')
        return true;

    return false;
}
