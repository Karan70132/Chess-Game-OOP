#include <iostream>
#include "piece.h"


using namespace std;

char chess :: Piece :: get_id() const
{
	return id ;
};

char chess :: Piece :: get_player() const
{
	return player ;
}

bool chess :: Piece :: Has_moved() const
{
	return status;
};

void chess :: Piece :: Deployed()
{
	status = true;
};


// <------------------------------------------   END   ---------------------------------------------->
