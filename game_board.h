#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "piece.h"
#include "chess_arsenal.h"
#include "helpers.h"
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>


namespace chess
{
    class Chess_Board
    {
    	protected :
    		std :: vector<std :: vector<Piece*>> Board ;
    		char PlayerTurn {'W'} ;
    		std :: vector<std ::vector<std :: string>> white_board , black_board ;
    		
    		std :: pair<int,int> White_King , Black_King ;
    		
    		std :: vector<Piece*> Captured_Black_Pieces ;
    		std :: vector<Piece*> Captured_White_Pieces ;
    		std :: vector<std :: string> History ;
    		bool Game_Over {false} ;
    	public :
    		Chess_Board();
    		~Chess_Board();
    	  	
    	  	// ConsoleUI functions
    		void Board_transformation();
    		void Print_Chess_Board();
    		void White_Chess_Board_Display();
    		void Black_Chess_Board_Display();
    		char get_turncolour();
		void alternate_turn();
		void start_message();
		void end_message_win( std :: string winner ); // player
		void end_message_draw();
    		bool Is_Game_Over();
    		
    		// Input and Move functions
    		void input_checker( std :: string& input );
    		void make_move();
    		
    		// King handling functions
    		bool King_In_check(char player);
    		bool exposes_king_to_check(int source_rank, int source_file, int destined_rank, int destined_file ,char player);
    		bool Is_checkmate(char player);
    		bool can_king_move(char player);
    		bool can_any_move(char player);
    		bool Is_stalemate(char player);
    		
    		// Special moves
		void pawn_promotion( int row , int col );
		bool castling( char king_colour, int fcol );
    		
    };
}

#endif
