#ifndef HELPERS_h
#define HELPERS_h


#include <bits/stdc++.h>
// #include <windows.h>

namespace chess
{

	extern std:: unordered_map< std :: string , std :: string > map ;

	extern const std:: string RESET ;
	extern const std:: string DARK  ;  // Gray background, White text
	extern const std:: string LIGHT ;         // Bright white
	
	/*
	extern const std:: string White_label = "White";
	extern const std:: string Black_label = "Black";
	*/
	
	void error_handle() ;

	bool correct_format ( std :: string& moveInput );

	void Help() ;
}

#endif
