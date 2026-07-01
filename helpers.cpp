#include "helpers.h"

using namespace std;

unordered_map<string, string> chess:: map = {
    // White pieces
    
    {"WK",u8"♔"} ,
    {"WQ" , u8"♕"},
    {"WR" , u8"♖"},
    {"WB" , u8"♗"},
    {"WN" , u8"♘"},
    {"WP" , u8"♙" } ,

    // Black pieces
    { "BK" , u8"♚"},
    {"BQ" , u8"♛"},
    {"BR" , u8"♜"},
    {"BB" , u8"♝"},
    {"BN" , u8"♞"},
    {"BP" , u8"♟"}
};

const string chess :: RESET = "\033[0m";
const string chess :: DARK  = "\033[100;98m";  // Gray background, White text
const string chess :: LIGHT = "\033[97m";         // Bright white
	
void chess :: error_handle()
{
	cout<<"COMMAND NOT FOUND! "<<endl;
};


bool chess :: correct_format(string& moveInput )
{	
	if(moveInput.size() != 8 || moveInput.substr(2,4) != " to "){
		return false;
	}
	if(moveInput[0]<'A' || moveInput[0]>'H' || moveInput[0]<'1' || moveInput[0]>'8' ){
		return false;
	}
	if(moveInput[6]<'A' || moveInput[6]>'H' || moveInput[7]<'1' || moveInput[7]>'8' ){
		return false;
	}
	return true;
};

void chess :: Help()
{
	cout<< "This implementation uses simplified chess rules. Castling is not supported. "<<endl;
	cout<<"Both players will have to make a valid move to proceed further"<<endl;
	cout<<"Each player has the option to \"resign\" , offer \" draw\" and \"flip\" only when it's player's turn"<<endl;
	cout<<"You have to make a move in a specified format "<<endl;
	cout<<"example: \"A5 to A6\" take not of initial positions of moving piece and it's final position and then enter it"<<endl;
	cout<<"You can also type help to access the ruke and typing format on the player's turn"<<endl;
	
}

