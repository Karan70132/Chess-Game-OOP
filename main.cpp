#include "board.h"




int main(void){

    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);

    cout<< R"(

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
        string choice;
        cout << "Would you like to start a new game? (Y/N): ";
        cin>> choice;

        if (choice == "Y" || choice == "y" )
        {
            cout << "\nLoading the chessboard...\n";
            break;
        }
        else
        {
            cout << "\nThanks for visiting. Goodbye!\n";
            continue;
        }
    }
	
    cout<<"Let's start the game!"<endl;
    cout<<"Rules and regulation :- "<<endl;
    Help();
    while(true){
    	
    	Chess_Board  Game;
    	
    	while(!Game.Is_Game_Over())
    	{
    		Game.Whites_Turn();
    		if(Game.Is_Game_Over())break;
    		
    		Game.Blacks_Turn();
    	}
    	
    	cout<<"<-------------  x  ---------->"
    	string play ;
    	cout << "Would you like to play a new game? (Y/N): ";
        cin>> play;
        if(play == "Y" || play == "y"){
        	continue;
        }
        else break;
    }
    
    cout<<"Thanks for Playing the Game Visit again"<<endl;

    

    return 0;
}

