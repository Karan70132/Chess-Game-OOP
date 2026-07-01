# include "piece.h"

using namespace std;
/*
chess :: Piece :: Piece( char item , char color , int square_rank , int square_file )
{
	player = color;
	
};
*/

char chess :: Piece :: get_id()
{
	
	return id ;
}

char chess :: Piece :: get_player()
{
	return player ;
}

/*
//using namespace chess;

int main() {
	cout<<"Hello World!" <<endl;
	chess::Piece* temp = new chess::Piece('K', 'W');
	//cout<<temp->get_id()<<endl;
}

