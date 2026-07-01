#ifndef PIECE_h
#define PIECE_h

#include "helpers.h"
// All re-arrange
#include "game_pieces.h"

namespace chess
{
	 class Piece : public Pawn , public Rook , public Knight , public Bishop , public Quen , public King 
	 {
	     protected :
	 	 char player , id ;
	 	// int rank, file;
	 	
	 	/*
	 		FOR A PIECE LOCATION , ID , COLOR/PLAYER IS SECURED
	 	*/
	     public:
	 	Piece( char color , char item) player(color) , id(item) {};
	 	/*{
		 	id = i;
		 	player = color;
		};*/
		// Destructor
		/*
			SEE IF ANY INCLUSION OF ANY FUNCTIONS POSSIBLE
		*/
		
		 char get_id();
		 char get_player();
		
    	  	
    	  	
		/*
		virtual void Move_formatter(
		std :: vector<std :: vector<Piece*>>& Board , char id , char player , int final_rank ,  int final_file 
		 ) = 0 ;
		virtual ~Piece() = default;
		*/
	 };
}

#endif
