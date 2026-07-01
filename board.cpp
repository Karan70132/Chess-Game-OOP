#include "board.h"

using namespace std ;

Chess_Board :: Chess_board()
{
	Game_Over = false;
	Board.resize(8,vector<piece*>(8,nullptr));
	 
	for(int rank = 0 ; rank<8 ; rank ++ ){
		if(rank<=1){// White pieces
			if(rank == 1){
				for(int file =0 ; file < 8 ; file++ ){
					Board[rank][file] = new chess :: Pawn('W',rank,file);
				}
			}
			else{
				int left_file = 0 , right_file = 7;
				
				Board[rank][left_file] = Board[rank][right_file] = new chess :: Rook('W',rank,file);
				left_file++ , right_file--;
				
				Board[rank][left_file] = Board[rank][right_file] = new chess :: Knight('W',rank,file);
				left_file++ , right_file--;
				
				Board[rank][left_file] = Board[rank][right_file] = new chess :: Bishop('W',rank,file);
				left_file++ , right_file--;
				
				Board[rank][left_file] = new chess :: Queen('W',rank,file);
				Board[rank][right_file] = new chess :: King('W',rank,file);
				White_King = {rank,right_file};

			}
			
		}
		else if(rank>=6){ //Black pieces
			if(rank == 6){
				for(int file =0 ; file < 8 ; file++ ){
					Board[rank][file] = new Pawn('B',rank,file);
				}
			}
			else{
				int left_file = 0 , right_file = 7;
				
				Board[rank][left_file] = Board[rank][right_file] = new chess :: Rook('B',rank,file);
				left_file++ , right_file--;
				
				Board[rank][left_file] = Board[rank][right_file] = new chess :: Knight('B',rank,file);
				left_file++ , right_file--;
				
				Board[rank][left_file] = Board[rank][right_file] = new chess :: Bishop('B',rank,file);
				left_file++ , right_file--;
				
				Board[rank][left_file] = new chess :: Queen('B',rank,file);
				Board[rank][right_file] = new chess :: King('B',rank,file);
				
				Black_King = {rank,right_file};
			}
		}
	}
};


bool Chess_Board  ::Is_Game_Over()
{
	return Game_Over;
};

void Chess_Board  :: Game_Winner(char player)
{	
	Game_Over = true;
	if(player =='N'){
		cout<<"DRAW!"<<endl;
		return;
	}
	
	string color = player =='W' ? "White" : "Black";
	cout<<"Conjurer is "<<color<<endl;
	cout<<"Congratulations!"<<endl;
};

void Chess_Board  :: Game_Commands(string& command , char player)
{
	command.to_lowercase();
	string color = player =='W' ? "White" : "Black";
	if(command == "resign"){
	
		cout<<color<<"'s Player has resigned"<<endl;
		Game_Winner(player =='W' ? 'B' : 'W');
	}
	else if(command == "draw"){
		cout<<color<<"'s "<<"Player has offered @ DRAW"<<endl;
		
		cout<<"Does the "<<player=='W'? "Black" :"White"<<"'s player accept it ? (Y/N) : ";
		char response;
		cin>>response;
		if(response =='Y' || response=='y'){
			Game_Winner('N');
		}
		else{
			cout<<player=='W'? "Black" :"White"<<"'s player has rejected ! " <<endl;
			cout<<"The Game Continues!"<<endl;
			player =='W' ? Whites_Turn() : Blacks_Turn();
		}
	}
	else if(command == flip){
		if(player =='W'){
			// CLEAN UP
			Black_Chess_Board_Display();
		}
		else{
			// CLEAN UP
			White_Chess_Board_Display();
		}
		player =='W' ? Whites_Turn() : Blacks_Turn();
	}
	else{
		cout<<"INVALID COMMAND"<<endl;
		player =='W' ? Whites_Turn() : Blacks_Turn();
	}
};

void Chess_Board :: Board_transformation() 
{
	for(int row =0 ; row< 8 ; row++ ){
		for(int col =0 ; col <8 ; col ++){
			piece* current_piece = Board[row][col];
			if(current_piece == nullptr){
				white_board[row][col] = black_board[7-row][col] = " ";
			}
			else{
				char current_id = current_piece.get_id() , current_player = current_piece.get_player();
				if(current_id == 'K'){
					if(current_player =='W'){
						White_King = {row,col};
					}
					else{
						Black_King = {row,col};
					}
				}
				string key {current_player , current_id};
				white_board[row][col] = black_board[7-row][col] = map[key];
			}
		}
	}
	return ;
};

void Chess_Board :: White_Chess_Board_Display() // Print The Chess Board with The 2D string 
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

            cout<< bg << "   " << white_board[i][j]<< "   " << RESET;
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

void Chess_Board :: Black_Chess_Board_Display() // Print The Chess Board with The 2D string 
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

bool Chess_Board :: King_In_Check(char player)
{
	/*
		A0  A1 A2
		B0 King B2
		C0 C1  C2
	*/
	char opponent = player =='W' ? 'B' : 'W';
	
	auto [row , col ] = player =='W' ? Black_King : White_King ;
	
	// A1 and C1
	int col_up = col+1 , col_down = col -1;
	
	while(col_up < 8 || col_down>=0 ){
		if(col_up < 8 ){
			piece* current = Board[row][col_up];
			
			if(current == nullptr )col_up++;
			else{
				char current_piece_player = current.get_player();
				if(current_piece_player == player){
					col_up=8;
				}
				else{
					char current_piece_id = current.get_id();
					if(current_piece_id == 'Q' || current_piece_id == 'R'){
						return true ;
					}
					else if(col_up == col+1 && current_piece_id == 'K' ){
						return true;
					}
					else{
						col_up =8;
					}
				}
			}
		}
		if(col_down >=0  ){
			piece* current = Board[row][col_up];
			
			if(current == nullptr )col_down--;
			else{
				char current_piece_player = current.get_player();
				if(current_piece_player == player){
					col_down=-1;
				}
				else{
					char current_piece_id = current.get_id();
					if(current_piece_id == 'Q' || current_piece_id == 'R'){
						return true;
					}
					else if(col_up == col-1 && current_piece_id == 'K' ){
						return true;
					}
					else{
						col_down = -1;
					}
				}
			}
		}
	
	}
	
	// B0 and B2
	
	int row_up = row +1 , row_down = row -1;
	
	while(row_up < 8 || row_down>=0 ){
		if(row_up < 8 ){
			piece* current = Board[row_up][col];
			
			if(current == nullptr )row_up++;
			else{
				char current_piece_player = current.get_player();
				if(current_piece_player == player){
					row_up=8;
				}
				else{
					char current_piece_id = current.get_id();
					if(current_piece_id == 'Q' || current_piece_id == 'R'){
						return true;
					}
					else if(col_up == col+1 && current_piece_id == 'K' ){
						return true;
					}
					else{
						row_up =8;
					}
				}
			}
		}
		if(row_down >=0  ){
			piece* current = Board[row_down][col];
			
			if(current == nullptr )row_down--;
			else{
				char current_piece_player = current.get_player();
				if(current_piece_player == player){
					row_down=-1;
				}
				else{
					char current_piece_id = current.get_id();
					if(current_piece_id == 'Q' || current_piece_id == 'R'){
						return true;
					}
					else if(col_up == col-1 && current_piece_id == 'K' ){
						return true;
					}
					else{
						row_down = -1;
					}
				}
			}
		}
	
	}
	
	// A2 and C0
	
	pair<int,int> diag_up1 = {row+1,col+1} , diag_up2 = {row+1,col-1};
	pair<int,int> diag_down1 = {row-1,col-1} , diag_down2 = {row-1,col+1};
	
	while( max(diag_up1.first , diag_up1.second) < 8 || min(diag_down1.first , diag_down1.second)){
		if(max(diag_up1.first , diag_up1.second)< 8 ){
			piece* current = Board[diag_up1.first][diag_up1.second];
			
			if(current == nullptr ){
				diag_up1.second++;
				diag_up1.first++;
			}
			else{
				char current_piece_player = current.get_player();
				if(current_piece_player == player){
					diag_up1.second = 8;
					diag_up1.first = 8;
				}
				else{
					char current_piece_id = current.get_id();
					if(current_piece_id == 'Q' || current_piece_id == 'R'){
						return true;
					}
					else if(abs(diag_up1.first - row)+ abs(diag_up1.second - col) ==2 && (current_piece_id == 'K' || (current_piece_id == 'P' && current_piece_player=='B') )){
						return true;
					}
					else{
						diag_up1.second = 8;
						diag_up1.first = 8;
					}
				}
			}
		}
		if(min(diag_down1.first , diag_down1.second) ){
			piece* current = Board[diag_down1.first][diag_down1.second];
			
			if(current == nullptr ){
				diag_down1.second--;
				diag_down1.first--;
			}
			else{
				char current_piece_player = current.get_player();
				if(current_piece_player == player){
					diag_down1.second = -1;
					diag_down1.first = -1;
				}
				else{
					char current_piece_id = current.get_id();
					if(current_piece_id == 'Q' || current_piece_id == 'R'){
						return true;
					}
					else if(abs(diag_down1.first - row)+ abs(diag_down1.second - col) ==2 && (current_piece_id == 'K' || (current_piece_id == 'P' && current_piece_player=='W') ) ){
						return true;
					}
					else{
						diag_down1.second = -1;
						diag_down1.first = -1;
					}
				}
			}
		}
	
	}
	
	// A0 and C2
	
	while( ( diag_up2.first < 8 && diag_up2.second>=0 ) || ( diag_down2.first>=0 && diag_down2.second <8 )){
		if( diag_up2.first < 8 && diag_up2.second>=0 ){
			piece* current = Board[diag_up2.first][diag_up2.second];
			
			if(current == nullptr ){
				diag_up2.second--;
				diag_up2.first++;
			}
			else{
				char current_piece_player = current.get_player();
				if(current_piece_player == player){
					diag_up2.second = -1;
					diag_up2.first = 8;
				}
				else{
					char current_piece_id = current.get_id();
					if(current_piece_id == 'Q' || current_piece_id == 'R'){
						return true;
					}
					else if(abs(diag_up2.first - row)+ abs(diag_up2.second - col) ==2 && (current_piece_id == 'K' || (current_piece_id == 'P' && current_piece_player=='B') ) ){
						return true;
					}
					else{
						diag_up2.second = -1;
						diag_up2.first = 8;
					}
				}
			}
		}
		if(diag_down2.first>=0 && diag_down2.second <8 ){
			piece* current = Board[diag_down2.first][diag_down2.second];
			
			if(current == nullptr ){
				diag_down2.second++;
				diag_down2.first--;
			}
			else{
				char current_piece_player = current.get_player();
				if(current_piece_player == player){
					diag_down2.second = 8;
					diag_down2.first = -1;
				}
				else{
					char current_piece_id = current.get_id();
					if(current_piece_id == 'Q' || current_piece_id == 'R'){
						return true;
					}
					else if(abs(diag_down2.first - row)+ abs(diag_down2.second - col) ==2 && (current_piece_id == 'K' || (current_piece_id == 'P' && current_piece_player=='W') ) ){
						return true;
					}
					else{
						diag_down2.second = 8;
						diag_down2.first = -1;
					}
				}
			}
		}
	
	}
	
	// B1 || knight

	for(int jump_row = max(0,row-2) ; jump_row <= min( 7 , row+2) ; jump_row++ ){
		for(int jump_col = max(0,col-2) ; jump_col <= min( 7 , row+2) ; jump_col++ ){
			if(abs(jump_row -row) + abs(jump_col - col) ==3 && abs(jump_row -row)*abs(jump_col - col)!=0 ){
				piece* current = Board[jump_row][jump_col];
			
				if(current == nullptr ){
					continue;
				}
				else{
					char current_piece_player = current.get_player();
					char current_piece_id = current.get_id();
					if(current_piece_player != player && current_piece_id == 'k'){
						return true;
					}
				}
			}
		}
	}
	return false;
};

bool Chess_Board :: Checkmate(char player)
{
	auto [row , col] = player == 'W' ? White_King : Black_King ;
	
	
	piece* kings_place = Board[row][col];
	Board[row][col] = nullptr; // Temporary
	for( int poss_row = row-1 ; poss_row <=row+1 ; poss_row++ ){
		for(int poss_col = col-1 ; pos_col<=col+1 ; pos_col++ ){
			if(!(King_In_Check(player)))return false;
		}
	}
	return true;
};


void Whites_Turn()
{
	if(Checkmate('W')){
		cout<<"Checkmate by Black's player!"<<endl;
		Game_Winner('B');
		return ;
	}
	string moveInput;
	
	cout<<"Enter the command :  "<<endl;
	// cout<<"Example A3 to G6";
	cin>>moveInput;
	// check for command 
	
	if(moveInput == "help"){
		Help();
		Whites_Turn() ;
		return;
	}
	
	if(moveInput == "resign" || moveInput== "draw" || moveInput== "flip"){
		Game_Commands(moveInput , 'W');
		Whites_Turn() ;
		return ;
	}
	
	
	// checking correct or not
	if(!correct_format(moveInput)){
		cout<<"Incorrect formatt of the move! try again ."<<endl;
		Whites_Turn();
		return ;
	}
	
	pair<int,int> initial_pos  = {moveInput[1] -'0',moveInput[0] -'A'} , final_pos = {moveInput[7] -'0',moveInput[6] -'A'} ;
	piece* Moving_piece = Board[initial_pos.first][initial_pos.second];
	
	char Moving_piece_id = Moving_piece.get_id();
	if(Moving_piece == nullptr || Moving_piece.get_player == 'B'){
		cout<<"Invalid move ! try again ."<<endl;
		Whites_Turn();
		return ;
	}
	if(Moving_piece_id == 'P'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'W' , final_pos.first , final_pos.second  );
	}
	else if(Moving_piece_id == 'R'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'W' , final_pos.first , final_pos.second  );
	}
	else if(Moving_piece_id == 'k'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'W' , final_pos.first , final_pos.second  );
	}
	else if(Moving_piece_id == 'B'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'W' , final_pos.first , final_pos.second  );
	}
	else if(Moving_piece_id == 'Q'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'W' , final_pos.first , final_pos.second  );
	}
	else if(Moving_piece_id == 'K'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'W' , final_pos.first , final_pos.second  );
	}
	else{
		error_handle();
		Game_Over = true;
		return ;	
	}
	
	Board_transformation();
	void Black_Chess_Board_Display();
	//Blacks_Turn();
};

void Blacks_Turn()
{
	if(Checkmate('B')){
		cout<<"Checkmate by White's player!"<<endl;
		Game_Winner('W');
		return ;
	}
	cout<<"Black's turn to move !"<<endl;
	string moveInput;
	
	
	cout<<"Enter the command : ";
	// cout<<"Example A3 to G6";
	cin>>moveInput;
	
	// check for command
	
	if(moveInput == "help"){
		Help();
		Blacks_Turn() ;
		return;
	}
	
	if(moveInput == "resign" || moveInput== "draw" || moveInput== "flip"){
		Game_Commands(moveInput , 'B');
		Blacks_Turn() ;
		return ;
	}
	
	// checking correct or not
	if(!correct_format(moveInput)){
		cout<<"Incorrect formatt of the move! try again ."<<endl;
		Blacks_Turn();
		return ;
	}
	
	pair<int,int> initial_pos  = {7 - (moveInput[1] -'0'),moveInput[0] -'A'} , final_pos = {7-(moveInput[7] -'0'),moveInput[6] -'A'} ;
	piece* Moving_piece = Board[initial_pos.first][initial_pos.second];
	char Moving_piece_id = Moving_piece.get_id();
	if(Moving_piece == nullptr || Moving_piece.get_player == 'W'){
		cout<<"Invalid move ! try again ."<<endl;
		Blacks_Turn();
		return ;
	}
	if(Moving_piece_id == 'P'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'B' , final_pos.first , final_pos.second  );
	}
	else if(Moving_piece_id == 'R'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'B' , final_pos.first , final_pos.second  );
	}
	else if(Moving_piece_id == 'k'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'B' , final_pos.first , final_pos.second  );
	}
	else if(Moving_piece_id == 'B'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'B' , final_pos.first , final_pos.second  );
	}
	else if(Moving_piece_id == 'Q'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'B' , final_pos.first , final_pos.second  );
	}
	else if(Moving_piece_id == 'K'){
		Moving_piece.Move_formatter(Board ,Moving_piece_id,'B' , final_pos.first , final_pos.second  );
	}
	else{
		error_handle();
		Game_Over = true;
		return ;	
	}
	
	Board_transformation();
	void whites_Chess_Board_Display();
	//Whites_Turn();
};

