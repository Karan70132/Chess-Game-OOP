#include <iostream>
#include "chess_arsenal.h"


using namespace std;

// ----------------------------  PAWN  ------------------------------------

int chess :: Pawn  :: get_rank() const
{
	return rank ;
};

int chess :: Pawn :: get_file() const
{
	return file ; 
};

bool chess :: Pawn :: Validate_move(vector<vector<Piece*>>& Board , int source_rank, int source_file, int destined_rank, int destined_file )
{
	char color = this->get_player() ; // color of moving piece
	
	
	if ( abs(destined_file-source_file) > 1 ) return false;
	if ( abs(destined_rank-source_rank) > 2 ) return false;
	
	Piece* destined_position = Board[destined_rank][destined_file] ;
	
	
	bool Is_empty = true ;
	if( destined_position != nullptr)
	{
		if(color == destined_position->get_player()) return false;
		Is_empty = false;
	}
	
	int delta = destined_rank - source_rank ;
	if ( color == 'W' )
	{	
		if( destined_rank <= source_rank ) return false;
		
		
		if( abs(destined_file-source_file) == 1 ) // CROSS-MOVE
		{
			if(Is_empty)return false;
			if(delta !=1 )return false;
			return true;
		}
		else // FORWARD-MOVE
		{
			if(!Is_empty || delta >2 )return false;
			if( source_rank == 1 ) // TWO-STEP or ONE-STEP
			{
				if( delta == 2 )
				{
					Piece* In_between = Board[destined_rank-1][destined_file];
					if(In_between != nullptr )return false;
				}
				return true;
			}
			else{ // ONE-STEP
				if(delta !=1 )return false;
				return true;
			}
		}
		
		
	}
	// Black
	if(destined_rank >= source_rank ) return false;
	
	if( abs(destined_file-source_file) == 1 ) // CROSS-MOVE
	{
		if(Is_empty)return false;
		if( delta !=-1 )return false;
		return true;
	}
	else // FORWARD-MOVE
	{
		if(!Is_empty || delta <-2 )return false;
		if( source_rank == 6 ) // TWO-STEP or ONE-STEP
		{
			if(delta== -2 )
			{
				Piece* In_between = Board[destined_rank+1][destined_file];
				if(In_between != nullptr )return false;
			}
			return true;
		}
		else{ // ONE-STEP
			if(delta !=-1 )return false;
			return true;
		}
	}
	return false;
};

void chess :: Pawn :: Update_position(int new_rank , int new_file )
{

	rank = new_rank , file = new_file ;
	return ;
}

// ---------------------------   KNIGHT   ------------------------------------------

int chess :: Knight :: get_rank() const
{
	return rank ;
};

int chess :: Knight :: get_file() const
{
	return file ; 
};

bool chess :: Knight :: Validate_move(vector<vector<Piece*>>& Board , int source_rank, int source_file, int destined_rank, int destined_file )
{
	// Irrespective of White or Black
	char color = this->get_player() ; // color of moving piece
	
	
	Piece* destined_position = Board[destined_rank][destined_file] ;
	
	
	bool Is_empty = true ;
	if( destined_position != nullptr)
	{
		if(color == destined_position->get_player()) return false;
		Is_empty = false;
	}
	
	int delta = destined_rank - source_rank ;
	int beta = destined_file - source_file ;
	
	if ( abs(delta) + abs(beta) !=3 ) return false;
	 
	if ( delta ==0 || beta == 0 ) return false;
	
	return true;
};

void chess :: Knight :: Update_position(int new_rank , int new_file )
{

	rank = new_rank , file = new_file ;
	return ;
}

// ------------------------------   ROOK   -------------------------------------------

int chess :: Rook :: get_rank() const
{
	return rank ;
};

int chess :: Rook :: get_file() const
{
	return file ; 
};

bool chess :: Rook :: Validate_move(vector<vector<Piece*>>& Board , int source_rank, int source_file, int destined_rank, int destined_file )
{
	// Irrespective of White or Black
	char color = this->get_player() ; // color of moving piece
	
	
	Piece* destined_position = Board[destined_rank][destined_file] ;
	
	
	bool Is_empty = true ;
	if( destined_position != nullptr)
	{
		if(color == destined_position->get_player()) return false;
		Is_empty = false;
	}
	
	int delta = destined_rank - source_rank ;
	int beta = destined_file - source_file ;
	
	if (delta !=0 && beta!=0) return false;
	
	int rank_tr = ( delta > 0)? 1 : ( delta ==0 ) ? 0 : -1 ; // rank traverse
	int file_tr = ( beta > 0 )? 1 : ( beta == 0 ) ? 0 : -1 ; // file traverse
	
	int row = source_rank + rank_tr , col = source_file + file_tr ;
	while( row != destined_rank || col != destined_file ){
		if( Board[row][col] != nullptr )
		{
			return  false;
		}
		row += rank_tr ;
		col += file_tr ;
	}
	
	return true;
};

void chess :: Rook :: Update_position(int new_rank , int new_file )
{

	rank = new_rank , file = new_file ;
	return ;
}

// ------------------------------   BISHOP  ---------------------------------------------------

int chess :: Bishop :: get_rank() const
{
	return rank ;
};

int chess :: Bishop :: get_file() const
{
	return file ; 
};

bool chess :: Bishop :: Validate_move(vector<vector<Piece*>>& Board , int source_rank, int source_file, int destined_rank, int destined_file )
{
	// Irrespective of White or Black
	char color = this->get_player() ; // color of moving piece
	
	
	Piece* destined_position = Board[destined_rank][destined_file] ;
	
	
	bool Is_empty = true ;
	if( destined_position != nullptr)
	{
		if(color == destined_position->get_player()) return false;
		Is_empty = false;
	}
	
	int delta = destined_rank - source_rank ;
	int beta = destined_file - source_file ;
	
	if (abs(delta) != abs(beta) )return false;
	
	int rank_tr = ( delta > 0 ) ? 1 : -1 ;  // rank traverse
	int file_tr = ( beta > 0  ) ? 1 : -1 ;  // file traverse
	
	int row = source_rank + rank_tr , col = source_file + file_tr ;
	while( row!= destined_rank || col!= destined_file ){
		if( Board[row][col] != nullptr )
		{
			return false;
		}
		row += rank_tr ;
		col += file_tr ;
	}
	
	return true;
};

void chess :: Bishop :: Update_position(int new_rank , int new_file )
{

	rank = new_rank , file = new_file ;
	return ;
}

// ------------------------------   QUEEN   ---------------------------------------------------

int chess :: Queen :: get_rank() const
{
	return rank ;
};

int chess :: Queen :: get_file() const
{
	return file ; 
};

bool chess :: Queen :: Validate_move(vector<vector<Piece*>>& Board , int source_rank, int source_file, int destined_rank, int destined_file )
{
	// Irrespective of White or Black
	char color = this->get_player() ; // color of moving piece
	
	
	Piece* destined_position = Board[destined_rank][destined_file] ;
	
	
	bool Is_empty = true ;
	if( destined_position != nullptr)
	{
		if(color == destined_position->get_player()) return false;
		Is_empty = false;
	}
	
	int delta = destined_rank - source_rank ;
	int beta = destined_file - source_file ;
	
	if (abs(delta) != abs(beta) && delta !=0 && beta !=0 )return false;
	
	int rank_tr = ( delta > 0)? 1 : ( delta ==0 ) ? 0 : -1 ; // rank traverse
	int file_tr = ( beta > 0 )? 1 : ( beta == 0 ) ? 0 : -1 ; // file traverse
	
	int row = source_rank + rank_tr , col = source_file + file_tr ;
	while( row!= destined_rank || col!= destined_file ){
		if( Board[row][col] != nullptr )
		{
			return false;
		}
		row += rank_tr ;
		col += file_tr ;
	}
	
	return true;
};

void chess :: Queen :: Update_position(int new_rank , int new_file )
{

	rank = new_rank , file = new_file ;
	return ;
}

// ------------------------------   KING    ---------------------------------------------------

int chess :: King :: get_rank() const
{
	return rank ;
};

int chess :: King :: get_file() const
{
	return file ; 
};

bool chess :: King :: Validate_move(vector<vector<Piece*>>& Board , int source_rank, int source_file, int destined_rank, int destined_file )
{
	// Irrespective of White or Black
	char color = this->get_player() ; // color of moving piece
	
	
	Piece* destined_position = Board[destined_rank][destined_file] ;
	
	
	bool Is_empty = true ;
	if( destined_position != nullptr)
	{
		if(color == destined_position->get_player()) return false;
		Is_empty = false;
	}
	
	int delta = destined_rank - source_rank ;
	int beta = destined_file - source_file ;
	
	if ( abs(delta) + abs(beta) > 2 ) return false;
	
	if(abs(delta) == 0 && abs(delta) + abs(beta) == 2 )  return false;
	return true;
};

void chess :: King :: Update_position(int new_rank , int new_file )
{
	rank = new_rank , file = new_file ;
	return ;
}

// <------------------------------------------   END   ---------------------------------------------->
