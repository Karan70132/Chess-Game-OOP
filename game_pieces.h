#ifndef game_pieces_h
#define game_pieces_h

// # include "piece.h"
//#include<bits/stdc++.h>

namespace chess
{
    class Pawn 
    {	
    	protected :
    		char id ;
    		int rank , file ;
    		
    	public :
    	    Pawn( int square_rank , int square_file) : id('P') ,rank(square_rank) , file(square_file) {};
    	    
    	    /*
    	       killer_move()
    	       normal_move()
    	       Promotion()
    	     */
    	     int get_rank();
    	     int get_file();
    	     char get_id();
    	     /*
    	     void Promotion_move
    	  ( std:: vector< std:: vector<Piece*>>& Board ,char player , int initial_rank , int initial_file ,int final_rank , int final_file );
    	  
    	   pair<int,int>  Move_formatter
    	  ( std:: vector< std:: vector<Piece*>>& Board ,char player , int initial_rank , int initial_file ,int final_rank , int final_file );
    	 	*/
    	     bool Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file );
    };
    
    class Knight 
    {
    	protected :
    		char id ;
    		int rank , file ;
    		
    	public :
    		Knight( int square_rank , int square_file) : id('N') ,rank(square_rank) , file(square_file) {};
    		
    		int get_rank();
    	        int get_file();
    	        char get_id();
    		
    	  bool Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file );
    	    
    };
    
    class Bishop 
    {
    	protected :
    		char id ;
    		int rank , file ;
    	
    	public:
    		Bishop( int square_rank , int square_file) : id('B') ,rank(square_rank) , file(square_file) {};
    		
    		
    		int get_rank();
    	        int get_file();
    	        char get_id();
    		
    	  bool Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file );
    };
    
    class Rook 
    {
    	protected :
    		char id ;
    		int rank , file ;
    	
    	public:
    		Rook( int square_rank , int square_file) : id('R') ,rank(square_rank) , file(square_file) {};
    		
    		
    		int get_rank();
    	        int get_file();
    	        char get_id();
    		
    	  bool Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file );
    };
    
    class Queen 
    {
    	protected :
    		char id ;
    		int rank , file ;
    	
    	public:
    		Queen( int square_rank , int square_file) : id('Q') ,rank(square_rank) , file(square_file) {};
    		
    		
    		int get_rank();
    	        int get_file();
    	        char get_id();
    		
    	  bool Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file );
    };
    
    class King 
    {
    	protected :
    		char id ;
    		int rank , file ;
    	
    	public:
    		King( int square_rank , int square_file) : id('K') ,rank(square_rank) , file(square_file) {};
    		
    		int get_rank();
    	        int get_file();
    	        char get_id();
    		
    	  bool Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file );
    };
}

#endif
