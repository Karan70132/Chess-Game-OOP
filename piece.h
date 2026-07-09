#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>

namespace chess
{
	 class Piece 
	 {
	     protected :
	 	 char player , id ;
	 	 bool status {false} ; // Stores whether the piece has moved from its starting position. (Initialized to false)
	 	/*
	 		FOR A PIECE ID AND COLOR/PLAYER IS SECURED
	 	*/
	     public:
	 	 Piece( char color , char item): player(color) , id(item) {}
		
		 char get_id() const;
		 
		 char get_player() const;
		 
		 bool Has_moved() const;
		 
    	  	 void Deployed() ; 
    	  	 
    	  	 virtual bool Validate_move(
    	  	  std :: vector< std :: vector<Piece*>>& Board, int source_rank, int source_file, int destined_rank, int destined_file ) = 0;
    	  	 
    	  	 virtual void Update_position(int new_rank , int new_file ) = 0 ;
    	  	 
		 virtual ~Piece() = default;
	 };
}

#endif
