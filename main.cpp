#include <bits/stdc++.h>

#include "piece.h"
#include "chess_arsenal.h"
#include "helpers.h"
#include "game_board.h"

using namespace chess ;


int main (void)
{
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);

    std :: cout<< R"(

         ██████╗██╗  ██╗███████╗███████╗███████╗
        ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝
        ██║     ███████║█████╗  ███████╗███████╗
        ██║     ██╔══██║██╔══╝  ╚════██║╚════██║
        ╚██████╗██║  ██║███████╗███████║███████║

            ♔  WELCOME TO CONSOLE CHESS  ♚

        =================================================
                "The Game of Kings and Queens."
        =================================================

    )";
    
    while (true)
    {
        std :: string choice;
        std :: cout << "Would you like to start a new game? (Y/N): ";
        std :: cin>> choice;

        if (choice == "Y" || choice == "y" )
        {
            std :: cout << "\nLoading the chessboard...\n";
            break;
        }
        else
        {
            std :: cout << "\nThanks for visiting. Goodbye!\n";
            
            return 0 ;
        }
    }
	
    std :: cout<<"Let's start the game!"<< std :: endl;
    Help();
    
    while(true){
    	
    	Chess_Board  Game;
    	
    	Game.start_message();
    
    	while(!Game.Is_Game_Over())
    	{
    		Game.make_move();
    		
    		if ( Game.Is_checkmate('W')  )
    		{
    				Game.end_message_win("Black");
    				break;
    		}
    		else if ( Game.Is_checkmate('B') )
    		{
    				Game.end_message_win("White");
    				break;
    		}
    		else if ( Game.Is_stalemate('W') || Game.Is_stalemate('B') )
    		{
    				Game.end_message_draw();
    				break;
    		}
    		
    		Game.alternate_turn();
    	}
    	
    	std :: cout<<"<------------------------------  END  ------------------------------------->\n";
    	std :: string play ;
    	std :: cout << "Would you like to play a new game? (Y/N): ";
        std :: cin>> play;
        if(play == "Y" || play == "y"){
        	continue;
        }
        else break;
    }
    
    std :: cout<<"Thanks for playing the game visit again !"<< std :: endl;


    return 0;
}
