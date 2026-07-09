#ifndef CHESS_ARSENAL_H
#define CHESS_ARSENAL_H

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include "piece.h"

namespace chess
{
    class Pawn : public Piece
    {	
    	protected :
    		int rank , file ;
    		
    	public :
    	    Pawn( int square_rank , int square_file , char color ) : Piece(color,'P') ,rank(square_rank) , file(square_file) {}
    	    
    	    /*
    	       killer_move()
    	       normal_move()
    	       Promotion()
    	     */
    	     
    	     int get_rank() const ;
    	     
    	     int get_file() const ;
    	     
    	     bool Validate_move(
    	  std :: vector< std :: vector<Piece*> >& Board, int source_rank, int source_file, int destined_rank, int destined_file ) override;
    	  
    	     void Update_position(int new_rank , int new_file ) override ;
    	     
    };
    
    class Knight : public Piece
    {
    	protected :
    		int rank , file ;
    		
    	public :
    		Knight( int square_rank , int square_file , char color ) : Piece(color,'N') ,rank(square_rank) , file(square_file) {}
    		
    		int get_rank() const ;
    	     
    	     	int get_file() const ;
    	     	
    	     	bool Validate_move(
    	  std :: vector< std :: vector<Piece*> >& Board, int source_rank, int source_file, int destined_rank, int destined_file ) override;
    	  
    	  	void Update_position(int new_rank , int new_file ) override ;
    	    
    };
    
    class Bishop : public Piece
    {
    	protected :
    		int rank , file ;
    	
    	public:
    		Bishop( int square_rank , int square_file , char color ) : Piece(color,'B') ,rank(square_rank) , file(square_file) {};
    		
    		int get_rank() const ;
    	     
    	     	int get_file() const ;
    	     	
    	     	bool Validate_move(
    	  std :: vector< std :: vector<Piece*> >& Board, int source_rank, int source_file, int destined_rank, int destined_file ) override;
    	  
    	  	void Update_position(int new_rank , int new_file ) override ;
    };
    
    class Rook : public Piece
    {
    	protected :
    		int rank , file ;
    	
    	public:
    		Rook( int square_rank , int square_file , char color ) : Piece(color,'R') ,rank(square_rank) , file(square_file) {}
    		
    		int get_rank() const ;
    	     
    	     	int get_file() const ;
    	     	
    	    	bool Validate_move(
    	  std :: vector< std :: vector<Piece*> >& Board, int source_rank, int source_file, int destined_rank, int destined_file ) override;
    	  
    	  	void Update_position(int new_rank , int new_file ) override ;
    };
    
    class Queen : public Piece
    {
    	protected :
    		int rank , file ;
    	
    	public:
    		Queen( int square_rank , int square_file , char color ) : Piece(color,'Q') ,rank(square_rank) , file(square_file) {}
    		
    		int get_rank() const ;
    	     
    	     	int get_file() const ;
    	     	
    	     	bool Validate_move(
    	  std :: vector< std :: vector<Piece*> >& Board, int source_rank, int source_file, int destined_rank, int destined_file ) override;
    	  
    	  	void Update_position(int new_rank , int new_file ) override ;
    };
    
    class King : public Piece
    {
    	protected :
    		int rank , file ;
    	
    	public:
    		King( int square_rank , int square_file , char color ) : Piece(color,'K') ,rank(square_rank) , file(square_file) {}
    		
    		int get_rank() const ;
    	     
    	     	int get_file() const ;
    	     	
    	     	bool Validate_move(
    	  std :: vector< std :: vector<Piece*> >& Board, int source_rank, int source_file, int destined_rank, int destined_file ) override;
    	  
    	  	void Update_position(int new_rank , int new_file ) override ;
    };
}

#endif
