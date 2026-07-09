#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include "piece.h"


bool Linear_Check ( std::vector<std::vector<chess::Piece*>>& Board, int krow, int kcol, int dr, int dc, char player );

bool Diagonal_Check (std::vector<std::vector<chess::Piece*>>& Board, int krow, int kcol, int dr, int dc, char player);

bool Knight_Check ( std::vector<std::vector<chess::Piece*>>& Board, int krow, int kcol, char player );


extern std:: unordered_map< std :: string , std :: string > symbols ;


extern const std:: string RESET ;
extern const std:: string DARK  ;  	// Gray background, White text
extern const std:: string LIGHT ;         // Bright white

void Help();

#endif
