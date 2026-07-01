#include "game_pieces.h"

using namespace std;

/*
	void Normal_move
    	  ( vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file );
    	  
    	     void Killer_move
    	  ( vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file );
    	  
    	     void Move_formatter
    	   ( vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file );

*/

//	---------- PAWN ---------

int chess :: Pawn :: get_rank()
{
	if ( this == nullptr )
	{
		return -1; // ERROR
	}
	return rank ;
};

int chess :: Pawn :: get_file()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return file ;
};

char chess :: Pawn :: get_id()
{
	return id ;
};

/*
void chess :: Pawn :: Promotion_move
( std:: vector< std:: vector<Piece*>>& Board ,char player , int initial_rank , int initial_file ,int final_rank , int final_file );
{
	Piece* current_pawn = Board[rank][file];
	
	Piece* promoted_piece = nullptr;
	
	cout << "Select the promotion piece (Q = Queen, R = Rook, B = Bishop, N = Knight): ";
	
	string promotionChoice;
	cin>>promotionChoice ;
	
	if(promotionChoice== "Q"){
		promoted_piece = new chess :: Piece('Q',player,final_rank,final_file);
	}
	else if(promotionChoice == "R"){
		promoted_piece = new chess :: Piece('R',player,final_rank,final_file);
	}
	else if(promotionChoice == "B" ){
		promoted_piece = new chess :: Piece('B',player,final_rank,final_file);
	}
	else if(promotionChoice == "N" ){ 
		promoted_piece = new chess :: Piece('N',player,final_rank,final_file);
	}
	else
	{
		cout<<"Invalid Command !"<<endl;
		Promotion_move(Board ,id ,player ,final_rank , final_file );
		return ;
	}

	Board[final_rank][final_file] = promoted_piece ;
	current_pawn = nullptr ;
	
};

/*
void chess :: Pawn :: Normal_move(vector<vector<Piece*>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	int initial_rank = get_rank();
	int initial_file = get_file();
	
	if((player == 'W' && final_rank == 7) || (player=='B' && final_file ==0)){
		Promotion_move(Board , id, player , final_rank , final_file);
	}
	this->rank = final_rank , this->file = final_file;
	
	Board[initial_rank][initial_file] = nullptr;
	Board[final_rank][final_file] = this;
	
};


void chess :: Pawn :: Killer_move(vector<vector<Piece*>>& Board ,char player ,int ,int final_rank , int final_file)
{
	int initial_rank = this->get_rank();
	int initial_file = get_file();
	
	this->rank = final_rank , this->file = final_file;
	
	// INSERT THE Board[final_rank][final_file] piece into the captured one
	
	Board[initial_rank][initial_file] = nullptr ;
	Board[final_rank][final_file] = this ;
};
*/

bool chess :: Pawn :: Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file )
{	
	
	if(final_rank >=8 || final_rank< 0 || final_file>=8 || final_file < 0 ) // OUT OF BOUNDS AND NOT MOVE
	{
		cout << " Invalid Move " << endl; 
		return false;
	}	
	
	if( initial_rank == final_rank && initial_file == final_file ){
		return false;
	}
	if(player == 'W' )
	{
		if(final_rank != initial_rank+1 || abs(final_file - initial_file)>1 || final_rank <= initial_rank ){
			cout << " Invalid Move " << endl; 
			return false;
		}
		/*
		Piece* destination = Board[final_rank][final_file];
		if(destination == nullptr && final_file == initial_file ){
			//Normal_move( Board , player , initial_rank, initail_file , final_rank , final_file);
			return {true,false};
		}
		else{
			char destined_player = destination->get_player();
			if(destined_player == player){ // self- move
				cout << " Invalid Move " << endl; 
				return {false,false};
			}
			else{
				return {false,true};
			}
		}
		*/
	}
	else{ // 'B'
		if(final_rank != initial_rank-1 || abs(final_file - initial_file)>1){
			cout << " Invalid Move " << endl; 
			return false;
		}
		/*
		Piece* destination = Board[final_rank][final_file];
		if(destination == nullptr && final_file == initial_file ){
			return {true,false};
		}
		else{
			char destined_player = destination->get_player();
			if(destined_player == player){ // self- move
				cout << " Invalid Move " << endl; 
				return {false,false};
			}
			else{
				return {false,true};
			}
		}
		*/
	}
	return true;
};
    	  
/*
//	---------- KNIGHT ---------

void chess :: Knight :: Normal_move(vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	int initial_rank = get_rank();
	int initial_file = get_file();
	
	this->rank = final_rank , this->file = final_file;
	
	Board[initial_rank][initial_file] = nullptr;
	Board[final_rank][final_file] = this;
	
};

void Knight :: Killer_move(vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	int initial_rank = get_rank();
	int initial_file = get_file();
	
	this->rank = final_rank , this->file = final_file;
	
	// INSERT THE Board[final_rank][final_file] piece into the captured one
	
	Board[initial_rank][initial_file] = nullptr ;
	Board[final_rank][final_file] = this ;
};
*/

bool chess :: Knight :: Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file )
{	
	
	
	if(final_rank >=8 || final_rank < 0 || final_file>=8 || final_file < 0 ) // OUT OF BOUNDS AND NOT MOVE
	{
		cout<<"Invalid Move!"<<endl;
		return false;
	}	
	if( initial_rank == final_rank && initial_file == final_file ){
		return false;
	}
	
	
	if( abs(final_rank-initial_rank)>2 || abs(final_file - initial_file)>2){
		return false;
	}
	if(abs(final_rank-initial_rank) + abs(final_file - initial_file) != 3 ){
		return false;
	}
		/*
		Piece* destination = Board[final_rank][final_file];
		if(destination == nullptr && final_file == initial_file ){
			Normal_move( Board , id , player , final_rank , final_file);
		}
		else{
			char destined_player = destination.get_player;
			if(destined_player == player){ // self- move
				// INVALID MOVE
			}
			else{
				Killer_move(Board ,id ,player , final_rank , final_file);
			}
		}
		*/
	
	/*else{ // 'B'
		if( abs(final_rank-initial_rank)>2 || abs(final_file - initial_file)>2){
			return false;
		}
		if(abs(final_rank-initial_rank) + abs(final_file - initial_file) != 3 ){
			return false;
		}
		
		Piece* destination = Board[final_rank][final_file];
		
		if(destination == nullptr && final_file == initial_file ){
			Normal_move( Board , id , player , final_rank , final_file);
		}
		else{
			char destined_player = destination.get_player;
			if(destined_player == player){ // self- move
				// INVALID MOVE
			}
			else{
				Killer_move(Board ,id ,player , final_rank , final_file);
			}
		}
		*/
	
      return true;
};

int chess :: Knight :: get_rank()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return rank ;
};

int chess :: Knight :: get_file()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return file ;
};

char chess :: Knight :: get_id()
{
	return id ;
};

//	---------- BISHOP ---------

/*
void Bishop :: Normal_move(vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	int initial_rank = get_rank();
	int initial_file = get_file();
	
	
	int rank_traverse = final_rank > initial_rank ? 1 :-1;
	int file_traverse = final_file > initial_file ? 1 :-1;
	int row = initial_rank , col = initial_file;
	while( row!=final_rank && col!=final_file){
		if( Board[row][col] != nullptr )
		{
			// INVALID MOVE
			return ;
		}
		row += rank_traverse ;
		col += file_traverse ;
	}
	
	this->rank = final_rank , this->file = final_file;
	
	Board[initial_rank][initial_file] = nullptr;
	Board[final_rank][final_file] = this;
	
};

void Bishop :: Killer_move(vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	int initial_rank = get_rank();
	int initial_file = get_file();
	
	
	
	int rank_traverse = final_rank > initial_rank ? 1 :-1;
	int file_traverse = final_file > initial_file ? 1 :-1;
	int row = initial_rank , col = initial_file;
	while( row!=final_rank && col!=final_file){
		if( Board[row][col] != nullptr )
		{
			// INVALID MOVE
			return ;
		}
		row += rank_traverse ;
		col += file_traverse ;
	}
	
	this->rank = final_rank , this->file = final_file;
	
	// INSERT THE Board[final_rank][final_file] piece into the captured one
	
	Board[initial_rank][initial_file] = nullptr ;
	Board[final_rank][final_file] = this ;
};
*/
bool chess :: Bishop :: Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file )
{	

	if(final_rank >=8 || final_rank < 0 || final_file>=8 || final_file < 0 ) // OUT OF BOUNDS AND NOT MOVE
	{
		return false;
	}	
	if( initial_rank == final_rank && initial_file == final_file ){
		return false;
	}
	//if(player == 'W' )
	//{
	if( abs(final_rank-initial_rank) !=  abs(final_file - initial_file) ){
		return false;
	}
		/*
		Piece* destination = Board[final_rank][final_file];
		if(destination == nullptr && final_file == initial_file ){
			Normal_move( Board , id , player , final_rank , final_file);
		}
		else{
			char destined_player = destination.get_player;
			if(destined_player == player){ // self- move
				// INVALID MOVE
			}
			else{
				Killer_move(Board ,id ,player , final_rank , final_file);
			}
		}
		*/
	//}
	/*else{ // 'B'
		if( abs(final_rank-initial_rank) !=  abs(final_file - initial_file) ){
			return false;
		}
		/*
		Piece* destination = Board[final_rank][final_file];
		
		if(destination == nullptr && final_file == initial_file ){
			Normal_move( Board , id , player , final_rank , final_file);
		}
		else{
			char destined_player = destination.get_player;
			if(destined_player == player){ // self- move
				// INVALID MOVE
			}
			else{
				Killer_move(Board ,id ,player , final_rank , final_file);
			}
		}
		*/
	//}
	return true;
};

int chess :: Bishop:: get_rank()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return rank ;
};

int chess :: Bishop:: get_file()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return file ;
};

char chess :: Bishop:: get_id()
{
	return id;
};

//	---------- ROOK ---------
/*
void Rook :: Normal_move(vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	int initial_rank = get_rank();
	int initial_file = get_file();
	
	
	int rank_traverse = final_rank > initial_rank ? 1 : final_rank == initial_rank ? 0 : -1;
	int file_traverse = final_file > initial_file ? 1 : final_file== initial_file ? 0 : -1 ;
	
	int row = initial_rank , col = initial_file;
	while( row!=final_rank && col!=final_file){
		if( Board[row][col] != nullptr )
		{
			// INVALID MOVE
			return ;
		}
		row += rank_traverse ;
		col += file_traverse ;
	}
	
	this->rank = final_rank , this->file = final_file;
	
	Board[initial_rank][initial_file] = nullptr;
	Board[final_rank][final_file] = this;
	
};

void Rook :: Killer_move(vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	int initial_rank = get_rank();
	int initial_file = get_file();
	
	if( initial_rank == final_rank && initial_file = final_file ){
		// INVALID MOVE
	}
	
	int rank_traverse = final_rank > initial_rank ? 1 : final_rank == initial_rank ? 0 : -1;
	int file_traverse = final_file > initial_file ? 1 : final_file== initial_file ? 0 : -1 ;
	int row = initial_rank , col = initial_file;
	while( row!=final_rank && col!=final_file){
		if( Board[row][col] != nullptr )
		{
			// INVALID MOVE
			return ;
		}
		row += rank_traverse ;
		col += file_traverse ;
	}
	
	this->rank = final_rank , this->file = final_file;
	
	// INSERT THE Board[final_rank][final_file] piece into the captured one
	
	Board[initial_rank][initial_file] = nullptr ;
	Board[final_rank][final_file] = this ;
};
*/
bool chess ::  Rook :: Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file )
{	
	
	if(final_rank >=8 || final_rank < 0 || final_file>=8 || final_file < 0 ) // OUT OF BOUNDS AND NOT MOVE
	{
		return false;
	}	
	if( initial_rank == final_rank && initial_file == final_file ){
		return false;
	}
	if( (final_rank - initial_rank) * (final_file - initial_file) != 0 ){
		return false;
	}
	/*
	if(player == 'W' )
	{
		
		
		Piece* destination = Board[final_rank][final_file];
		if(destination == nullptr && final_file == initial_file ){
			Normal_move( Board , id , player , final_rank , final_file);
		}
		else{
			char destined_player = destination.get_player;
			if(destined_player == player){ // self- move
				// INVALID MOVE
			}
			else{
				Killer_move(Board ,id ,player , final_rank , final_file);
			}
		}
	}
	else{ // 'B'
		if( (final_rank - initial_rank) * (final_file - initial_file) != 0 ){
			// INVALID MOVE
		}
		
		Piece* destination = Board[final_rank][final_file];
		
		if(destination == nullptr && final_file == initial_file ){
			Normal_move( Board , id , player , final_rank , final_file);
		}
		else{
			char destined_player = destination.get_player;
			if(destined_player == player){ // self- move
				// INVALID MOVE
			}
			else{
				Killer_move(Board ,id ,player , final_rank , final_file);
			}
		}
	}
	*/
	return true;
};

int chess :: Rook :: get_rank()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return rank ;
};

int chess :: Rook :: get_file()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return file ;
};

//	---------- QUEEN ---------
/*
void Queen :: Normal_move(vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	int initial_rank = get_rank();
	int initial_file = get_file();
	
	
	int rank_traverse = final_rank > initial_rank ? 1 : final_rank == initial_rank ? 0 : -1;
	int file_traverse = final_file > initial_file ? 1 : final_file == initial_file ? 0 : -1 ;
	
	int row = initial_rank , col = initial_file;
	while( row!=final_rank && col!=final_file){
		if( Board[row][col] != nullptr )
		{
			// INVALID MOVE
			return ;
		}
		row += rank_traverse ;
		col += file_traverse ;
	}
	
	this->rank = final_rank , this->file = final_file;
	
	Board[initial_rank][initial_file] = nullptr;
	Board[final_rank][final_file] = this;
	
};

void Queen :: Killer_move(vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	int initial_rank = get_rank();
	int initial_file = get_file();
	
	if( initial_rank == final_rank && initial_file = final_file ){
		// INVALID MOVE
	}
	
	int rank_traverse = final_rank > initial_rank ? 1 : final_rank == initial_rank ? 0 : -1;
	int file_traverse = final_file > initial_file ? 1 : final_file== initial_file ? 0 : -1 ;
	int row = initial_rank , col = initial_file;
	while( row!=final_rank && col!=final_file){
		if( Board[row][col] != nullptr )
		{
			// INVALID MOVE
			return ;
		}
		row += rank_traverse ;
		col += file_traverse ;
	}
	
	this->rank = final_rank , this->file = final_file;
	
	// INSERT THE Board[final_rank][final_file] piece into the captured one
	
	Board[initial_rank][initial_file] = nullptr ;
	Board[final_rank][final_file] = this ;
};
*/
bool chess :: Queen :: Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file )
{	
	
	if(final_rank >=8 || final_rank < 0 || final_file>=8 || final_file < 0 ) // OUT OF BOUNDS AND NOT MOVE
	{
		return false;
	}	
	
	if(initial_rank ==final_rank && initial_file== final_file ){
		return false;
	}
	
	if( abs(final_rank - initial_rank) != abs(final_file - initial_file) || final_rank!= initial_rank || final_file != initial_file)
	{
			return false;
	}
		
	/*
	if(player == 'W' )
	{
		if( abs(final_rank - initial_rank) != abs(final_file - initial_file) && final_rank!= initial_rank && final_file != initial_file){
			// INVALID MOVE
		}
		
		Piece* destination = Board[final_rank][final_file];
		if(destination == nullptr && final_file == initial_file ){
			Normal_move( Board , id , player , final_rank , final_file);
		}
		else{
			char destined_player = destination.get_player;
			if(destined_player == player){ // self- move
				// INVALID MOVE
			}
			else{
				Killer_move(Board ,id ,player , final_rank , final_file);
			}
		}
	}
	else{ // 'B'
		if( abs(final_rank - initial_rank) != abs(final_file - initial_file) && final_rank!= initial_rank && final_file != initial_file){
			// INVALID MOVE
		}
		
		Piece* destination = Board[final_rank][final_file];
		
		if(destination == nullptr && final_file == initial_file ){
			Normal_move( Board , id , player , final_rank , final_file);
		}
		else{
			char destined_player = destination.get_player;
			if(destined_player == player){ // self- move
				// INVALID MOVE
			}
			else{
				Killer_move(Board ,id ,player , final_rank , final_file);
			}
		}
	}
	*/
	return true;
};

int chess :: Queen :: get_rank()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return rank ;
};

int chess :: Queen :: get_file()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return file ;
};
char chess :: Queen :: get_id()
{
	return id;
};

//	---------- KING ---------

/*
void King :: Safe_move(vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	
	
	/*
		A0  A1 A2
		B0 King B2
		C0 C1  C2
	*
	int row = final_rank , col = final_file ;
	
	// A1 and C1
	int col_up = final_file+1 , col_down = final_file -1;
	
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
						// CHECK INVALID MOVE
					}
					else if(col_up == col+1 && current_piece_id == 'K' ){
						// CHECK INVALID MOVE
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
						// CHECK INVALID MOVE
					}
					else if(col_up == col-1 && current_piece_id == 'K' ){
						// CHECK INVALID MOVE
					}
					else{
						col_down = -1;
					}
				}
			}
		}
	
	}
	
	// B0 and B2
	
	int row_up = final_rank+1 , row_down = final_rank -1;
	
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
						// CHECK INVALID MOVE
					}
					else if(col_up == col+1 && current_piece_id == 'K' ){
						// CHECK INVALID MOVE
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
						// CHECK INVALID MOVE
					}
					else if(col_up == col-1 && current_piece_id == 'K' ){
						// CHECK INVALID MOVE
					}
					else{
						row_down = -1;
					}
				}
			}
		}
	
	}
	
	// A2 and C0
	
	pair<int,int> diag_up1 = {final_rank+1,final_file +1} , diag_up2 = {final_rank+1,final_file-1};
	pair<int,int> diag_down1 = {final_rank-1,final_file -1} , diag_down2 = {final_rank-1,final_file+1};
	
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
						// CHECK INVALID MOVE
					}
					else if(abs(diag_up1.first - row)+ abs(diag_up1.second - col) ==2 && (current_piece_id == 'K' || (current_piece_id == 'P' && current_piece_player=='B') )){
						// CHECK INVALID MOVE
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
						// CHECK INVALID MOVE
					}
					else if(abs(diag_down1.first - row)+ abs(diag_down1.second - col) ==2 && (current_piece_id == 'K' || (current_piece_id == 'P' && current_piece_player=='W') ) ){
						// CHECK INVALID MOVE
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
						// CHECK INVALID MOVE
					}
					else if(abs(diag_up2.first - row)+ abs(diag_up2.second - col) ==2 && (current_piece_id == 'K' || (current_piece_id == 'P' && current_piece_player=='B') ) ){
						// CHECK INVALID MOVE
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
						// CHECK INVALID MOVE
					}
					else if(abs(diag_down2.first - row)+ abs(diag_down2.second - col) ==2 && (current_piece_id == 'K' || (current_piece_id == 'P' && current_piece_player=='W') ) ){
						// CHECK INVALID MOVE
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
						// CHECK INVALID MOVE
					}
				}
			}
		}
	}
	
	this->rank = final_rank , this->file = final_file;
	
	Board[initial_rank][initial_file] = nullptr;
	Board[final_rank][final_file] = this;
	
};

void King :: Killer_move(vector<vector<Piece>>& Board ,char id ,char player ,int final_rank , int final_file)
{
	int initial_rank = get_rank();
	int initial_file = get_file();
	
	if( initial_rank == final_rank && initial_file = final_file ){
		// INVALID MOVE
	}
	
	int rank_traverse = final_rank > initial_rank ? 1 : final_rank == initial_rank ? 0 : -1;
	int file_traverse = final_file > initial_file ? 1 : final_file== initial_file ? 0 : -1 ;
	int row = initial_rank , col = initial_file;
	while( row!=final_rank && col!=final_file){
		if( Board[row][col] != nullptr )
		{
			// INVALID MOVE
			return ;
		}
		row += rank_traverse ;
		col += file_traverse ;
	}
	
	this->rank = final_rank , this->file = final_file;
	
	// INSERT THE Board[final_rank][final_file] piece into the captured one
	
	Board[initial_rank][initial_file] = nullptr ;
	Board[final_rank][final_file] = this ;
};
*/
bool chess :: King :: Validate_Move( char player , int initial_rank , int initial_file ,int final_rank , int final_file )
{	
	
	if(final_rank >=8 || final_rank < 0 || final_file>=8 || final_file < 0 ) // OUT OF BOUNDS AND NOT MOVE
	{
		return false;
	}	
	
	if(initial_rank ==final_rank && initial_file== final_file ){
		return false;
	}
	
	if(abs(final_rank - initial_rank) >1 || abs(final_file - initial_file) >1){
		return false;
	}
	
	/*
	if(player == 'W' )
	{
		if( abs(final_rank - initial_rank) + abs(final_file - initial_file) >2 ){
			// INVALID MOVE
		}
		else{
			if(abs(final_rank - initial_rank) ==0 || abs(final_file - initial_file)==0){
				// INVALID MOVE
			}
		}
		/*
		Piece* destination = Board[final_rank][final_file];
		if(destination == nullptr && final_file == initial_file ){
			Normal_move( Board , id , player , final_rank , final_file);
		}
		else{
			char destined_player = destination.get_player;
			if(destined_player == player){ // self- move
				// INVALID MOVE
			}
			else{
				Killer_move(Board ,id ,player , final_rank , final_file);
			}
		}
		
	}
	else{ // 'B'
		if( abs(final_rank - initial_rank) != abs(final_file - initial_file) && final_rank!= initial_rank && final_file != initial_file){
			// INVALID MOVE
		}
		
		Piece* destination = Board[final_rank][final_file];
		
		if(destination == nullptr && final_file == initial_file ){
			Normal_move( Board , id , player , final_rank , final_file);
		}
		else{
			char destined_player = destination.get_player;
			if(destined_player == player){ // self- move
				// INVALID MOVE
			}
			else{
				Killer_move(Board ,id ,player , final_rank , final_file);
			}
		}
	}
	*/
	return true;
};

int chess :: King :: get_rank()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return rank ;
};

int chess :: King :: get_file()
{
	if ( this == nullptr )
	{
		return -1;
	}
	return file ;
};
char chess :: King :: get_id()
{
	return id;
};
/*
int main(){
	cout<<"Hello World!"<<endl;
}
*/
