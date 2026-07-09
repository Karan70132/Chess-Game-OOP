#include <bits/stdc++.h>
#include "game_board.h"

using namespace std;

unordered_map<string, string> symbols = {
    // White pieces
    
    {"WK",u8"♔"} ,
    {"WQ" , u8"♕"},
    {"WR" , u8"♖"},
    {"WB" , u8"♗"},
    {"WN" , u8"♘"},
    {"WP" , u8"♙" } ,

    // Black pieces
    { "BK" , u8"♚"},
    {"BQ" , u8"♛"},
    {"BR" , u8"♜"},
    {"BB" , u8"♝"},
    {"BN" , u8"♞"},
    {"BP" , u8"♟"}
};


const string RESET = "\033[0m";
const string DARK  = "\033[100;98m";  // Gray background, White text
const string LIGHT = "\033[97m";         // Bright white

void Help()
{

    cout << "\n---------------------------- CHESS GAME GUIDE -------------------------------------\n\n";

    cout << "MOVE FORMAT\n";
    cout << "  • Enter every move as : A2 to A4\n";
    cout << "  • Columns : A - H\n";
    cout << "  • Rows    : 1 - 8\n";
    cout << "  • Example : E2 to E4\n\n";

    cout << "SPECIAL COMMANDS\n";
    cout << "  • resign      - Concede the game.\n";
    cout << "  • offer draw  - Offer a draw to your opponent.\n\n";

    cout << "GAME FEATURES\n";
    cout << "  • Legal move validation for every piece.\n";
    cout << "  • Check and Checkmate detection.\n";
    cout << "  • Stalemate detection.\n";
    cout << "  • Kingside and Queenside castling.\n";
    cout << "  • Automatic pawn promotion.\n";
    cout << "  • Captured piece tracking.\n";
    cout << "  • Move history recording.\n";
    cout << "  • Board automatically rotates for the current player.\n\n";

    cout << "NOTES\n";
    cout << "  • A move that leaves your own King in check is rejected.\n";
    cout << "  • If a move is rejected you still have chance to type a valid move if possible.\n";
    cout << "  • Castling is allowed only if all official conditions are satisfied.\n";
    cout << "  • Promotion choices: Queen, Rook, Bishop or Knight.\n";
    cout << "  • Follow standard chess rules throughout the game.\n";

    cout << "\n-----------------------------------  xxx  ---------------------------------------------\n";
    cout << "\n\n\n\n\n";
    
};

bool Linear_Check(vector<vector< chess :: Piece* >>& Board, int krow, int kcol, int dr, int dc, char player)
{
    int trow = krow + dr;
    int tcol = kcol + dc;
    
    while (trow >= 0 && trow < 8 && tcol >= 0 && tcol < 8)
    {
        chess::Piece* current = Board[trow][tcol];
        
        if (current == nullptr) 
        {
            trow += dr;
            tcol += dc;
        } 
        else 
        {
            char current_piece_player = current->get_player();
            if (current_piece_player == player) 
            {
                break; 
            } 
            else 
            {
                char current_piece_id = current->get_id();
                if (current_piece_id == 'Q' || current_piece_id == 'R') 
                {
                    return true;
                } 
                else if (max(abs(trow - krow),abs(tcol - kcol)) == 1 && current_piece_id == 'K') 
                {
                    return true;
                } 
                else 
                {
                    break; 
                }
            }
        }
    }
    return false;
}

bool Diagonal_Check(vector<vector< chess :: Piece* >>& Board, int krow, int kcol, int dr, int dc, char player)
{
    int trow = krow + dr;
    int tcol = kcol + dc;
    
    while (trow >= 0 && trow < 8 && tcol >= 0 && tcol < 8)
    {
        chess::Piece* current = Board[trow][tcol];
        
        if (current == nullptr) 
        {
            trow += dr;
            tcol += dc;
        } 
        else 
        {
            char current_piece_player = current->get_player();
            if (current_piece_player == player) 
            {
                break; 
            } 
            else 
            {
                char current_piece_id = current->get_id();
                if (current_piece_id == 'Q' || current_piece_id == 'B') 
                {
                    return true;
                } 
                else if (abs(trow - krow) == 1 && abs(tcol - kcol) == 1) 
                {
                    if (current_piece_id == 'K') 
                    {
                        return true;
                    }
                    if (current_piece_id == 'P') 
                    {
                        if (dr == 1 && current_piece_player == 'B') return true;
                        if (dr == -1 && current_piece_player == 'W') return true;
                    }
                    break;
                } 
                else 
                {
                    break; 
                }
            }
        }
    }
    return false;
}


bool Knight_Check(vector<vector< chess:: Piece*>>& Board, int krow, int kcol, char player)
{
    for (int jump_row = max(0, krow - 2); jump_row <= min(7, krow + 2); jump_row++) 
    {
        for (int jump_col = max(0, kcol - 2); jump_col <= min(7, kcol + 2); jump_col++) 
        {
            if (abs(jump_row - krow) + abs(jump_col - kcol) == 3 && abs(jump_row - krow) * abs(jump_col - kcol) != 0) 
            {
                chess::Piece* current = Board[jump_row][jump_col];
                
                if (current == nullptr) 
                {
                    continue;
                } 
                else 
                {
                    char current_piece_player = current->get_player();
                    char current_piece_id = current->get_id();
                    if (current_piece_player != player && current_piece_id == 'N') 
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// <------------------------------------------   END   ---------------------------------------------->
