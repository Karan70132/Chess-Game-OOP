#include <iostream>
#include "game_board.h"
#include "helpers.h"


using namespace std;

// --------------------------   Constructors and Destructors  ---------------------------------------

chess :: Chess_Board :: Chess_Board()  	
{
	Board.resize(8,vector<Piece*>(8,nullptr));
	
	white_board.resize(8,vector<string>(8," "));
	black_board.resize(8,vector<string>(8," " ));
	
	for(int rank = 0 ; rank< 8 ; rank ++ ){
		if(rank<=1){		// WHITE PIECES
			if(rank == 1){
				for(int file =0 ; file < 8 ; file++ ){
					Board[rank][file] = new chess :: Pawn(rank,file,'W');
				}
			}
			else{
				int left_file = 0 , right_file = 7;
				
				Board[rank][left_file] = new chess :: Rook(rank,left_file,'W');
				Board[rank][right_file] = new chess :: Rook(rank,right_file,'W');
				
				left_file++ , right_file--;
				
				Board[rank][left_file] = new chess :: Knight(rank,left_file,'W');
				Board[rank][right_file] = new chess :: Knight(rank,right_file,'W');
				
				left_file++ , right_file--;
				
				Board[rank][left_file] = new chess :: Bishop(rank,left_file,'W');
				Board[rank][right_file] = new chess :: Bishop(rank,right_file,'W');
				
				left_file++ , right_file--;
				
				Board[rank][left_file] = new chess :: Queen(rank,left_file,'W');
				Board[rank][right_file] = new chess :: King(rank,right_file,'W');
				
				White_King = {rank,right_file};

			}
			
		}
		else if(rank>=6){ 		// BLACK PIECES
			if(rank == 6){
				for(int file =0 ; file < 8 ; file++ ){
					Board[rank][file] = new chess :: Pawn(rank,file,'B');
				}
			}
			else{
				int left_file = 0 , right_file = 7;
				
				Board[rank][left_file] = new chess :: Rook(rank,left_file,'B');
				Board[rank][right_file] = new chess :: Rook(rank,right_file,'B');
				left_file++ , right_file--;
				
				Board[rank][left_file] = new chess :: Knight(rank,left_file,'B');
				Board[rank][right_file] = new chess :: Knight(rank,right_file,'B');
				left_file++ , right_file--;
				
				Board[rank][left_file] = new chess :: Bishop(rank,left_file,'B');
				Board[rank][right_file] = new chess :: Bishop(rank,right_file,'B');
				left_file++ , right_file--;
				
				Board[rank][left_file] = new chess :: Queen(rank,left_file,'B');
				Board[rank][right_file] = new chess :: King(rank,right_file,'B');
				
				Black_King = {rank,right_file};
			}
		}
	}
};

chess :: Chess_Board :: ~Chess_Board()  
{
	for(int i =0 ; i < 8 ; i++ )
	{	
		for(int j =0 ; j < 8 ; j++ )
		{
			delete Board[i][j];
		}
	}
	white_board.clear();
	black_board.clear();
	
	Captured_Black_Pieces.clear() ;
	Captured_White_Pieces .clear() ;
	
	History.clear();
};

// --------------------------   ConsoleUI functions ---------------------------------------

void chess :: Chess_Board :: Board_transformation() 
{
	for(int row =0 ; row< 8 ; row++ ){
		for(int col =0 ; col <8 ; col ++){
			Piece* current_piece = Board[row][col];
			if(current_piece == nullptr){
				white_board[row][col] = black_board[7-row][col] = " ";
			}
			else{
				char current_id = current_piece->get_id() , current_player = current_piece->get_player();
				
				// UPDATE KINGS POSITIONS
				if(current_id == 'K'){
					if(current_player =='W'){
						White_King = {row,col};
					}
					else{
						Black_King = {row,col};
					}
				}
				string key;
				key += current_player;
				key += current_id;
				
				// SIMULTANEOUSLY ASSIGN BOTH BOARDS
				white_board[row][col] = black_board[7-row][col] = symbols[key];
			}
		}
	}
	return ;
};

//		Suggestion to take two function in helper to reduce the same code again re-written
void chess :: Chess_Board :: Black_Chess_Board_Display() // Print The Chess Board with The 2D string 
{
    cout<< "\n";
    cout<< "      A      B      C      D      E      F      G      H \n";
    cout<< "  #";
    for( int edges = 0 ; edges < 56 ; edges ++ )
    {
        cout << "─";
    }
    cout << "# \n";

    for( int i = 0 ; i < 8 ; i++ )
    {
        // Top padding
        cout<< "  │";
        for( int j = 0 ; j < 8 ; j++ )
        {
            string bg = ((i+j)%2==0)?LIGHT:DARK;
            cout<< bg << "       " << RESET;
        }
        cout<< "│ \n";

        // Middle line with piece
        cout<< i+1 << " │";
        for( int j = 0 ;j < 8; j++ )
        {
            string bg = ((i+j)%2==0)?LIGHT:DARK;

            cout<< bg << "   " << white_board[i][j]<< "   " << RESET;
        }
        cout<< "│  " << i+1 << "\n";

        // Bottom padding
        cout<< "  │";
        for(int j = 0 ; j < 8 ; j++ )
        {
            string bg = ((i+j)%2==0)?LIGHT:DARK;
            cout<< bg << "       " << RESET;
        }
        cout<< "│ \n";
    }

    cout<< "  #";
    for( int edges = 0 ; edges < 56 ; edges ++ ){
        cout<< "─";
    }
    cout<< "# \n";
    cout<< "      A      B      C      D      E      F      G      H \n \n \n";
    
    return ;
};

void chess :: Chess_Board :: White_Chess_Board_Display() // Print The Chess Board with The 2D string 
{
    cout<< "\n";
    cout<< "      A      B      C      D      E      F      G      H \n";
    cout<< "  #";
    for( int edges = 0 ; edges < 56 ; edges ++ )
    {
        cout << "─";
    }
    cout << "# \n";

    for( int i = 0 ; i < 8 ; i++ )
    {
        // Top padding
        cout<< "  │";
        for( int j = 0 ; j < 8 ; j++ )
        {
            string bg = ((i+j)%2==0)?LIGHT:DARK;
            cout<< bg << "       " << RESET;
        }
        cout<< "│ \n";

        // Middle line with piece
        cout<< 8-i << " │";
        for( int j = 0 ;j < 8; j++ )
        {
            string bg = ((i+j)%2==0)?LIGHT:DARK;

            cout<< bg << "   " << black_board[i][j]<< "   " << RESET;
        }
        cout<< "│  " << 8-i << "\n";

        // Bottom padding
        cout<< "  │";
        for(int j = 0 ; j < 8 ; j++ )
        {
            string bg = ((i+j)%2==0)?LIGHT:DARK;
            cout<< bg << "       " << RESET;
        }
        cout<< "│ \n";
    }

    cout<< "  #";
    for( int edges = 0 ; edges < 56 ; edges ++ ){
        cout<< "─";
    }
    cout<< "# \n";
    cout<< "      A      B      C      D      E      F      G      H \n \n \n";
    return ;
};

void chess :: Chess_Board :: Print_Chess_Board()
{
	Board_transformation();
	PlayerTurn == 'W' ? White_Chess_Board_Display() : Black_Chess_Board_Display() ;
	
	return ;
};

char chess :: Chess_Board :: get_turncolour()
{
    return PlayerTurn;
};

void chess :: Chess_Board :: alternate_turn()
{
    PlayerTurn = (PlayerTurn == 'W') ? 'B' : 'W' ;
    
    return ;
};


void chess :: Chess_Board :: start_message()
{
    cout << "\n=============================================================\n";
    cout << "                    THE BATTLE BEGINS\n";
    cout << "=============================================================\n\n";

    cout << "White moves first.\n";
    cout << "Study the board carefully before making your move.\n";
    cout << "Every move counts—protect your King and seize every opportunity.\n\n";

    cout << "May the better strategist prevail.\n";
    cout << "Good luck to both players!\n";

    cout << "\n=============================================================\n";
    cout << "\n\n\n";
    
    return ;
};

void chess :: Chess_Board :: end_message_win(std::string player)
{
    	cout<<"      Conjurer is "<<player<<" !"<<endl;
	cout<<"Congratulations!"<<endl;
    	Game_Over = true ;
    
    return ;
};

void chess :: Chess_Board :: end_message_draw()
{
    cout << "\n       It's a stalemate!  Draw!\n" << endl;
    Game_Over = true ;
    
    return ;
};

bool chess :: Chess_Board  :: Is_Game_Over() 
{
	return Game_Over;
};

// --------------------------   Input and Move functions  ---------------------------------------


void chess :: Chess_Board :: input_checker( string& input )
{
    while (true) {
    
    	cout << "\n State your intended move  :  "; // like Ex - A8 to B7
        getline(cin >> ws, input);
        if ( input == "resign")
        {
        	if ( PlayerTurn == 'W' )
        	{
        		cout<<"\n White has resigned! "<<endl;
        		end_message_win("Black");
        	}
        	else
        	{
        		cout<<"\n Black has resigned! "<<endl;
        		end_message_win("White");
        	}
        	break;
        }
        else if (input == "offer draw")
        {
        	string response ;
        	cout<<"\n Please enter the response of ";
        	if ( PlayerTurn == 'W' )
        	{
        		cout<<"Black (Y/N) : "<<endl;
        		cin>>response;
        		if(response == "Y" || response == "y" )
        		{
        			end_message_draw();
        			break;
        		}
        		else
        		{
        			cout<<"Black has rejected the draw!"<<endl;
        			cout<<"Please continue the game "<<endl;
        		}
        	}
        	else
        	{
        		cout<<"White (Y/N) : "<<endl;
        		cin>>response;
        		if(response == "Y" || response == "y" )
        		{
        			end_message_draw();
        			break;
        		}
        		else
        		{
        			cout<<"  White has rejected the draw!"<<endl;
        			cout<<"  Please continue the game "<<endl;
        		}
        	}
        	break;
        }
        else if (input.length() != 8 )
        {
                cout << "\n Error: input must be made of 8 characters only. ( Ex - \"A2 to A4\" ) Try again!" << endl;
                Print_Chess_Board();
        }
        else if (!isalpha(input[0]) ||  !isdigit(input[1]) || !isalpha(input[6]) ||  !isdigit(input[7]) )
        {
                cout << "\n Error: input must be made of alphabhets, digits only ans spaces in correct order. ( Ex - \"B2 to B4\" ) Try again!" << endl;
                Print_Chess_Board();
        }
        else if( input[0] > 'H' || input[0] < 'A' || input[1] > '8' || input[1] < '1' 
        			   || input[6] > 'H' || input[6] < 'A' || input[7] > '8' || input[7] < '1')
        {
        	cout << "\n Error: The selected ones are out of bounds . ( Ex - \"D2 to D4\" ) Try again! " << endl;
        	Print_Chess_Board();
        }
        else if( input[0] == input[6] && input[1] == input[7])
        {
        	cout << "\n Error: The origin and destination squares must be different. ( Ex - \"C2 to C4\" ) Try again!" << endl;
        	Print_Chess_Board();
        } 
        else if( input[2] == ' ' && input[3] == 't' && input[4] =='o' && input[5] == ' ' )
        {
        	break ;
        }
        else
        {
            cout << "\n Error: please input a valid Move on the board. Try again!" << endl;
            Print_Chess_Board();
        }
    }
};

// Takes in and validates user input coordinates  then checks if move is legal

void chess :: Chess_Board :: make_move()
{
	/* only for the first time */			Print_Chess_Board();
    string input;
    int source_rank , source_file , destined_rank , destined_file ;
    
    while (true) 
    {
        if (PlayerTurn == 'W')
        {
            cout << "\n---------------     White player's turn   ----------------------" << endl;
        }
        else
        {
            cout << "\n---------------    Black player's turn   ----------------------" << endl;
        }

        cout << "\n ----- Your move ----- \n";
        
        input_checker(input);
        
        if(Is_Game_Over())return ;
        
        // ---------  Converting the Input  ----------
        
        source_rank = input[1] - '1' ; // start = '1' , end = '8'
        source_file = input[0] - 'A' ; // start = 'A' , end = 'H'

        destined_rank = input[7] - '1' ; // start = '1' , end = '8'
        destined_file = input[6] - 'A' ; // start = 'A' , end = 'H'


        if ( Board[source_rank][source_file] != nullptr )
        {
            if (Board[source_rank][source_file]->get_player() == PlayerTurn )
            {
                if ( Board[destined_rank][destined_file] == nullptr || Board[destined_rank][destined_file]->get_player() != PlayerTurn )
                {
                    if ( Board[source_rank][source_file]->get_id() == 'K') // King piece
                    {
                        if (!Board[source_rank][source_file]->Has_moved() && ( destined_file == 2 || destined_file == 6)) // asking for casl
                        {
                            
                            if (castling(PlayerTurn, destined_file))
                            {
                            	History.push_back(input);
                                Board[source_rank][source_file]->Deployed();
                                
                                Board[destined_rank][destined_file] = Board[source_rank][source_file];
                            	Board[source_rank][source_file] = nullptr;
                            	Board[destined_rank][destined_file]->Update_position(destined_rank , destined_file);
                            	
                                if(destined_file == 2)
                                {
                                	Board[source_rank][0]->Deployed();
                                	Board[destined_rank][destined_file+1] = Board[destined_rank][0];
                                	Board[destined_rank][0] = nullptr;
                                	Board[destined_rank][destined_file+1]->Update_position(destined_rank , destined_file+1);
                                }
                                else
                                {
                                	Board[source_rank][7]->Deployed();
                                	Board[destined_rank][destined_file-1] = Board[destined_rank][7];
                                	Board[destined_rank][7] = nullptr;
                                	Board[destined_rank][destined_file-1]->Update_position(destined_rank , destined_file-1);
                                }
                                
                                break;
                            }
                        }
                    }
                    
                    if ( Board[source_rank][source_file]->Validate_move( Board , source_rank , source_file , destined_rank , destined_file ))
                    {
                        if (!exposes_king_to_check(source_rank , source_file , destined_rank , destined_file , PlayerTurn ))
                        {
                             History.push_back(input);
                             
                            if(Board[destined_rank][destined_file] != nullptr ) // Adding it to fallen pieces
                            {
                            	PlayerTurn == 'W' ? 
                      			Captured_Black_Pieces.push_back(Board[destined_rank][destined_file]) : 	
                      				Captured_White_Pieces.push_back(Board[destined_rank][destined_file]) ;
                            }
                            Board[destined_rank][destined_file] = Board[source_rank][source_file];
                            Board[source_rank][source_file] = nullptr;
                            
                            if ( Board[destined_rank][destined_file]->get_id() == 'P')
                            {
                                if ( destined_rank == 0 || destined_rank == 7)
                                {
                                    pawn_promotion( destined_rank , destined_file );
                                }
                            }
                            Board[destined_rank][destined_file]->Update_position(destined_rank , destined_file);
                            Board[destined_rank][destined_file]->Deployed();
                            
                            break;
                        }
                        else
                        {
                            cout << "\nInvalid move: King will be in check, try again !" << endl;
                            Print_Chess_Board();
                        }
                    }
                    else 
                    {
                        cout << "\nInvalid move: piece movement is not allowed, try again ! " << endl;
                        Print_Chess_Board();
                    }
                }
                else
                {
                    cout << "\nInvalid move: cannot move to your own piece" << endl;
                    Print_Chess_Board();
                }
            }
            else
            {
                cout << "\nInvalid move: not your piece" << endl;
                Print_Chess_Board();
            }
        }
        else
        {
            cout << "\nInvalid move: there is no piece on that square" << endl;
            Print_Chess_Board();
        }
    }
};


// --------------------------   King handling functions    ---------------------------------------


bool chess :: Chess_Board :: King_In_check(char player)
{

	auto [ krow , kcol ] = player =='W' ? White_King : Black_King ;
	
	
	// Linear checks (Rooks, Queens, Adjacent King)
	
    	if (Linear_Check(Board, krow, kcol,  0,  1, player)) return true;
   	if (Linear_Check(Board, krow, kcol,  0, -1, player)) return true;
    	if (Linear_Check(Board, krow, kcol,  1,  0, player)) return true;
    	if (Linear_Check(Board, krow, kcol, -1,  0, player)) return true;

    	// Diagonal checks (Bishops, Queens, Pawns, Adjacent King)
    	
    	if (Diagonal_Check(Board, krow, kcol,  1,  1, player)) return true;
    	if (Diagonal_Check(Board, krow, kcol,  1, -1, player)) return true;
    	if (Diagonal_Check(Board, krow, kcol, -1, -1, player)) return true;
    	if (Diagonal_Check(Board, krow, kcol, -1,  1, player)) return true;
    
    	// Knight checks
    	
    	if (Knight_Check(Board, krow, kcol, player)) return true;

    	return false;
};


bool chess :: Chess_Board :: exposes_king_to_check(int source_rank, int source_file, int destined_rank, int destined_file , char player)
{
	Piece* source =  Board[source_rank][source_file];
	Piece* destination = Board[destined_rank][destined_file];
	// Good case
	if ( destination!= nullptr && destination->get_id() == 'K' ) return true;
	
	 Board[destined_rank][destined_file] = source ;
	 Board[source_rank][source_file] = nullptr ;
	 if( Board[destined_rank][destined_file]->get_id() == 'K' )
	 {
	 	// Temporarily update the King's position
	 	if( player == 'W' )
	 	{
	 		White_King = { destined_rank , destined_file } ;
	 		if(King_In_check(player))
	 		{
	 			Board[destined_rank][destined_file] = destination ;
			 	Board[source_rank][source_file] = source ;
			 	White_King = { source_rank , source_file } ;
			 	return true ;
	 		}
	 		Board[destined_rank][destined_file] = destination ;
		 	Board[source_rank][source_file] = source ;
		 	White_King = { source_rank , source_file } ;
	 		
	 	}
	 	else
	 	{
	 		Black_King = { destined_rank , destined_file } ;
	 		if(King_In_check(player))
	 		{
	 			Board[destined_rank][destined_file] = destination ;
			 	Board[source_rank][source_file] = source ;
			 	Black_King = { source_rank , source_file } ;
			 	return true ;
	 		}
	 		Board[destined_rank][destined_file] = destination ;
		 	Board[source_rank][source_file] = source ;
		 	Black_King = { source_rank , source_file } ;
	 	}
	 	
	 }
	 else if ( King_In_check(player) )
	 {
	 	
	 	Board[destined_rank][destined_file] = destination ;
	 	Board[source_rank][source_file] = source ;
	 	return true ;
	 }
	
	 Board[destined_rank][destined_file] = destination ;
	 Board[source_rank][source_file] = source ;
	 return false ;
};


bool chess :: Chess_Board :: Is_checkmate(char player)
{
	/*
	auto [krow , kcol] = ( player == 'W' ) ? White_King : Black_King ;
	
	
	Piece* kings_place = Board[krow][kcol];
	Board[krow][kcol] = nullptr; 		// Temporarily
	for( int pos_row = max(0,krow-1) ; pos_row <= min(7,krow+1) ; pos_row++ ){
		for(int pos_col = max(0,col-1) ; pos_col <= min(7,kcol+1) ; pos_col++ ){
			Piece* current = Board[pos_row][pos_col];
			
			Board[pos_row][pos_col] = kings_place;
			
			if(!(King_In_Check(player)))
			{
				Board[krow][kcol] = kings_place;
				Board[pos_row][pos_col] = current;
				return false;
			}
			Board[krow][kcol] = kings_place;
			Board[pos_row][pos_col] = current;
		}
	}
	Board[krow][kcol] = kings_place;
	*/
	if( King_In_check(player) && !can_king_move(player) ) return true ;
	return false ;
};


bool chess :: Chess_Board :: can_king_move(char player)
{
	auto [krow , kcol] = ( player == 'W' ) ? White_King : Black_King ;
	
	
	Piece* kings_place = Board[krow][kcol];
	Board[krow][kcol] = nullptr; // Temporary
	for( int pos_row = max(0,krow-1) ; pos_row <= min(7,krow+1) ; pos_row++ ){
		for(int pos_col = max( 0,kcol-1) ; pos_col<= min(7,kcol+1) ; pos_col++ ){
			if(pos_row == krow && pos_col == kcol )continue;
			Piece* current = Board[pos_row][pos_col];
			
			Board[pos_row][pos_col] = kings_place;
			
			if(!(King_In_check(player)))
			{
				Board[krow][kcol] = kings_place;
				Board[pos_row][pos_col] = current;
				return true;
			}
			Board[krow][kcol] = kings_place;
			Board[pos_row][pos_col] = current;
		}
	}
	Board[krow][kcol] = kings_place;
	return false;
};


bool chess :: Chess_Board :: can_any_move(char player)		// Checks if any other piece other than King can move
{
	
	for(int row = 0 ; row < 8 ; row++ )
	{
		for(int col = 0 ; col < 8 ; col++ )
		{
			if( Board[row][col] == nullptr || Board[row][col]->get_player() != player ) continue;
			Piece* current = Board[row][col] ;
			
			if(current->get_id() =='K' )continue;
			
			// 		Try to see all possible moves to all different squares present
			for(int rt = 0 ; rt < 8 ; rt++ )
			{
				for(int ct = 0 ; ct < 8 ; ct++ )
				{
					if(row == rt && col == ct )continue;
					
					if(current->Validate_move(Board , row,col , rt,ct) &&
					 	!exposes_king_to_check(row,col,rt,ct,player) )return true;
				}
			}
		}
	}
	return false ;
	
};


bool chess :: Chess_Board :: Is_stalemate(char player)
{
	if( !King_In_check(player) && !can_any_move(player) && !can_king_move(player) ) return true ;
	
	return false ;
};


// ----------------------------   Special move functions    ---------------------------------------


void chess :: Chess_Board :: pawn_promotion( int row , int col )
{
	string input;
	
	cout<<"\n\n Select the piece to which the pawn shall be promoted (Q/R/B/N): ";
	cin>>input ;
	
	
	if(input == "q" || input == "Q" )
	{
		Board[row][col] = new Queen(row,col,PlayerTurn);
	}
	else if(input == "r" || input == "R" )
	{
		Board[row][col] = new Rook(row,col,PlayerTurn);
	}
	else if(input == "n" || input == "N" )
	{
		Board[row][col] = new Knight(row,col,PlayerTurn);
	}
	else if(input == "b" || input =="B" ) 
	{
		Board[row][col] = new Bishop(row,col,PlayerTurn);
	}
	else
	{
		cout<<"\n Error : Invalid input!"<<endl;
		cout<<".....System will assign the pawn promotion to Queen as default !"<<endl;
		Board[row][col] = new Queen(row,col,PlayerTurn);
	}
	
	return ;
};


bool chess :: Chess_Board :: castling( char king_color, int destined_file )
{	
	if( King_In_check(king_color) )return false ;
	
	auto [krow , kcol ] = (king_color == 'W' )? White_King : Black_King ;
	
	if( destined_file ==2 ) //		Queen side castling
	{
		if( Board[krow][0] == nullptr )return false ;
		if( Board[krow][0]->Has_moved() || Board[krow][0]->get_id()!='R' || Board[krow][0]->get_player()!= king_color)return false ;
		
		for( int col = kcol-1 ; col>0 ; col-- )
		{
			if( Board[krow][col] != nullptr || exposes_king_to_check(krow,kcol,krow,col,king_color))return false ;
		}
		
		return true ;
	
	}
	else	// 			King side castling
	{
		if( Board[krow][7] == nullptr )return false ;
		if( Board[krow][7]->Has_moved() || Board[krow][7]->get_id()!='R' || Board[krow][7]->get_player()!= king_color)return false ;
		
		for( int col = kcol+1 ; col<7 ; col++ )
		{
			if( Board[krow][col] != nullptr || exposes_king_to_check(krow,kcol,krow,col,king_color))return false ;
		}
		
		return true ;
	}
	
	return false ;
};
		
// ------------------------------------------   END   ----------------------------------------------
