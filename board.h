// CHESS BOARD

#ifndef BOARD_h
#define BOARD_h

#include "subpieces.h"
#include "piece.h"

namespace chess
{
    class Chess_Board
    {
    	private :
    		std :: vector<std :: vector<Piece*>> Board;
    		std :: vector<std ::vector<std :: string>> white_board , black_board ;
    		std :: pair<int,int> White_King , Black_King;
    		bool Game_Over;
    	protected :
    		std :: vector<Piece*> Captured_Black_Pieces ;
    		std :: vector<Piece*> Captured_White_Pieces ;
    	public :
    		Chess_Board();
    		
    		void Normal_move
    	  ( std:: vector< std:: vector<Piece*>>& Board ,char player , int initial_rank , int initial_file ,int final_rank , int final_file );
    	  
    	    	void Killer_move
    	  ( std:: vector< std:: vector<Piece*>>& Board ,char player , int initial_rank , int initial_file ,int final_rank , int final_file );
    	  
    		void Board_transformation();
    		void White_Chess_Board_Display();
    		void Black_Chess_Board_Display();
    		bool King_In_check(char player);
    		bool Is_Game_Over();
    		bool Checkmate(char player);
    		void Whites_Turn();
    		void Blacks_Turn();
    		void Game_Winner(char player);
		void Game_Commands(string command , char player);
    		
    };
}
