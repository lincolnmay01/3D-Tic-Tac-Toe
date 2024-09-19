#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class TicTacToe { //class for the game rules 

protected:
    char board[3][3]; //2d array used to store what moves have been made
    char currentPlayer; 

public:
    void initialize() {  //this is used to initialize the array with dashes that signify an empty square, the function can also be used to reset the board if the user plays again
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                board[i][j] = '-';
            }
        }
        
        srand(time(0));
        currentPlayer = (rand() % 2 == 0) ? 'X' : 'O'; //randomly choose if x or o goes first
    }

    
    void displayBoard() {  //function to display the board and fill it with the moves occupied within the array 
        
		cout << "   0   1   2\n";
        cout << " -------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i << "| ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << endl << " -------------" << endl;
        }
    }

   
    void makeMove(int row, int col) {
       
	    if(row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') { //this function checks if the user enters the wrong numbers or chooses an occupied square
            cout << "Invalid move. Please try again.\n";
            return;
        }
        board[row][col] = currentPlayer; //fill the array with the move if valid
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; //switch player
    }

    
    bool gameOver() {
        
        for(int i = 0; i < 3; i++) { //checks for horizontal and vertical wins
            if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
                return true; 
            if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true; 
        }
        if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) //these two if statements check for diagonal win
            return true; 
        if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true; 

       
        for(int i = 0; i < 3; i++) { //check if there is still an empty square if so, return false
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == '-') {
                    return false; 
                }
            }
        }
        
        return true; //return true in the only other case that the board is full and there is no win
    }

    
    char getCurrentPlayer() { //this function allows me to display whose turn it is
        return currentPlayer;
    }
    
    char getBoard(int row, int col) {//this function allows me to ensure the computer makes a valid move
    	return board[row][col];
	}
};

class TicTacToe3D : public TicTacToe { //derived class from lab 9 class

private:
    char board[3][3][3]; //new array for the 3d board 

public:
    void initialize() { //used function overriding to modify this function from the base class
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
            	for(int k = 0; k < 3; k++) {          		
                	board[i][j][k] = '-';
				}
            }
        }
        
        srand(time(0));
        currentPlayer = (rand() % 2 == 0) ? 'X' : 'O'; //radomly choose if x or o goes first
    }

    
    void displayBoard() {  //used function overriding to modify this function from the base class
	    
	    for (int i = 0; i < 3; i++) {
	    	
	    	cout << "\nlayer " << i << ":" << endl;
			cout << "  0 1 2" << endl;
	       
		       
		    for (int j = 0; j < 3; j++) {
	            cout << j << " ";
	            for (int k = 0; k < 3; k++) {
	                cout << board[i][j][k] << " ";
	            }
	            cout << endl;
	        }
		}
	}
	    

	void makeMove(int layer, int row, int col) { //used function overriding to modify this function from the base class
       
	    if(row < 0 || row >= 3 || col < 0 || col >= 3 || layer < 0 || layer >= 3 || board[layer][row][col] != '-') { 
            cout << "Invalid move. Please try again.\n";
            return;
        }
        board[layer][row][col] = currentPlayer; //fill the array with the move if valid
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; //switch player
    }
    
	bool gameOver() { //used function overriding to modify this function from the base class 
		
	    for (int i = 0; i < 3; i++) {
	        for (int j = 0; j < 3; j++) {
	            for (int k = 0; k < 3; k++) {
	                if (board[i][j][k] == '-') {
	                    return false;
	                }
	            }
	        }
	    }
	    
    	return true;
	}

    char getBoard(int layer, int row, int col) {//used function overriding to modify this function from the base class
    	return board[layer][row][col];
	}
	
	string checkwins() { //this function checks how many 3 in a row each player got and returns a string that says who won based on who had more "3 in a row's"
		int winO = 0;
		int winX = 0;
		
		for (int i = 0; i < 3; i++) { // Loop through layers
    // Check horizontal wins on the same layer
		    for (int j = 0; j < 3; j++) { // Loop through rows
		        if (board[i][j][0] == 'O' && board[i][j][0] == board[i][j][1] && board[i][j][1] == board[i][j][2]) {
		            winO++;
		        }
		        if (board[i][0][j] == 'O' && board[i][0][j] == board[i][1][j] && board[i][1][j] == board[i][2][j]) {
		            winO++;
		        }
		    }
		    // Check diagonal wins on the same layer
		    if (board[i][0][0] == 'O' && board[i][0][0] == board[i][1][1] && board[i][1][1] == board[i][2][2]) {
		        winO++;
		    }
		    if (board[i][0][2] == 'O' && board[i][0][2] == board[i][1][1] && board[i][1][1] == board[i][2][0]) {
		        winO++;
		    }
		}
		
		for (int j = 0; j < 3; j++) { // Loop through rows
		    // Check vertical wins across different layers
		    if (board[0][0][j] == 'O' && board[0][0][j] == board[1][1][j] && board[1][1][j] == board[2][2][j]) {
		        winO++;
		    }
		    if (board[0][0][2 - j] == 'O' && board[0][0][2 - j] == board[1][1][1 - j] && board[1][1][1 - j] == board[2][2][0 - j]) {
		        winO++;
		    }
		    if (board[0][j][0] == 'O' && board[0][j][0] == board[1][j][1] && board[1][j][1] == board[2][j][2]) {
		        winO++;
		    }
		    if (board[0][j][2] == 'O' && board[0][j][2] == board[1][j][1] && board[1][j][1] == board[2][j][0]) {
		        winO++;
		    }
		}
		
		// Check additional diagonal wins across different layers
		if (board[0][0][0] == 'O' && board[0][0][0] == board[1][1][1] && board[1][1][1] == board[2][2][2]) {
		    winO++;
		}
		if (board[0][0][2] == 'O' && board[0][0][2] == board[1][1][1] && board[1][1][1] == board[2][2][0]) {
		    winO++;
		}
		if (board[0][2][0] == 'O' && board[0][2][0] == board[1][1][1] && board[1][1][1] == board[2][0][2]) {
		    winO++;
		}
		if (board[0][2][2] == 'O' && board[0][2][2] == board[1][1][1] && board[1][1][1] == board[2][0][0]) {
		    winO++;
		}
		
		for (int j = 0; j < 3; j++) { // Loop through rows
		    // Check vertical wins on the same column across different layers
		    if (board[0][j][0] == 'O' && board[0][j][0] == board[1][j][0] && board[1][j][0] == board[2][j][0]) {
		        winO++;
		    }
		    if (board[0][j][1] == 'O' && board[0][j][1] == board[1][j][1] && board[1][j][1] == board[2][j][1]) {
		        winO++;
		    }
		    if (board[0][j][2] == 'O' && board[0][j][2] == board[1][j][2] && board[1][j][2] == board[2][j][2]) {
		        winO++;
		    }
		}
	//the code below checks for the same win conditions for X
		for (int i = 0; i < 3; i++) { // Loop through layers
	    // Check horizontal wins on the same layer
		    for (int j = 0; j < 3; j++) { // Loop through rows
		        if (board[i][j][0] == 'X' && board[i][j][0] == board[i][j][1] && board[i][j][1] == board[i][j][2]) {
		            winX++;
		        }
		        if (board[i][0][j] == 'X' && board[i][0][j] == board[i][1][j] && board[i][1][j] == board[i][2][j]) {
		            winX++;
		        }
		    }
		    // Check diagonal wins on the same layer
		    if (board[i][0][0] == 'X' && board[i][0][0] == board[i][1][1] && board[i][1][1] == board[i][2][2]) {
		        winX++;
		    }
		    if (board[i][0][2] == 'X' && board[i][0][2] == board[i][1][1] && board[i][1][1] == board[i][2][0]) {
		        winX++;
		    }
		}
	
		for (int j = 0; j < 3; j++) { // Loop through rows
		    // Check vertical wins across different layers
		    if (board[0][0][j] == 'X' && board[0][0][j] == board[1][1][j] && board[1][1][j] == board[2][2][j]) {
		        winX++;
		    }
		    if (board[0][0][2 - j] == 'X' && board[0][0][2 - j] == board[1][1][1 - j] && board[1][1][1 - j] == board[2][2][0 - j]) {
		        winX++;
		    }
		    if (board[0][j][0] == 'X' && board[0][j][0] == board[1][j][1] && board[1][j][1] == board[2][j][2]) {
		        winX++;
		    }
		    if (board[0][j][2] == 'X' && board[0][j][2] == board[1][j][1] && board[1][j][1] == board[2][j][0]) {
		        winX++;
		    }
		}
		
		// Check additional diagonal wins across different layers
		if (board[0][0][0] == 'X' && board[0][0][0] == board[1][1][1] && board[1][1][1] == board[2][2][2]) {
		    winX++;
		}
		if (board[0][0][2] == 'X' && board[0][0][2] == board[1][1][1] && board[1][1][1] == board[2][2][0]) {
		    winX++;
		}
		if (board[0][2][0] == 'X' && board[0][2][0] == board[1][1][1] && board[1][1][1] == board[2][0][2]) {
		    winX++;
		}
		if (board[0][2][2] == 'X' && board[0][2][2] == board[1][1][1] && board[1][1][1] == board[2][0][0]) {
		    winX++;
		}
		
		for (int j = 0; j < 3; j++) { // Loop through rows
		    // Check vertical wins on the same column across different layers
		    if (board[0][j][0] == 'X' && board[0][j][0] == board[1][j][0] && board[1][j][0] == board[2][j][0]) {
		        winX++;
		    }
		    if (board[0][j][1] == 'X' && board[0][j][1] == board[1][j][1] && board[1][j][1] == board[2][j][1]) {
		        winX++;
		    }
		    if (board[0][j][2] == 'X' && board[0][j][2] == board[1][j][2] && board[1][j][2] == board[2][j][2]) {
		        winX++;
		    }
		}
	
	
		if (winO > winX) {
			return "You lose.";
		}
		else if (winO == winX) {
			return "Tie.";
		}
		
		return "You win!!";		
	}
};

int main() {  
    TicTacToe3D game; //object of class tictactoe3D
    int layer, row, col;
    char playAgain;
    
    cout << "Welcome to TicTacToe, 3D!\n" << "Simply imagine the boards as if they were stacked on top of each other." << endl;
    cout << "You will be playing against the computer, good luck." << endl;
    
    do{
		game.initialize(); //initialize the board
		
		while(!game.gameOver()) { //keep going while gameover is false
	        cout << "\nCurrent board:\n";
	        game.displayBoard(); // display board each time
	        
			cout << "Current player: " << game.getCurrentPlayer() << endl;
	        if(game.getCurrentPlayer() == 'X') { //if it is x then player goes, if its o then computer goes
	           
	            cout << "Enter layer, row, and column (0-2) to make a move (Example:0 0 0): ";
	            cin >> layer >> row >> col;
	             
	            game.makeMove(layer, row, col);
	        
			} else {
				
				do { 
				layer = rand() % 3; 
		        row = rand() % 3; 
	            col = rand() % 3; 
				} while (game.getBoard(layer, row, col) != '-'); //make sure the computer doesnt try and choose occupied cell
				         
				cout << "Computer chose layer " << layer <<", row " << row << ", and column " << col << endl;
	            game.makeMove(layer, row, col);
	            	            
	        }
	    }
	    
		cout << "Final board:\n"; //display final board 
	    game.displayBoard();
	    
	    cout << "Game Over, " << game.checkwins() << endl; // display who won based on who has more wins
	    cout << "\nWould you like to play again?(y/n)\n";
	    cin >> playAgain;
	    
	} while(playAgain == 'y' || playAgain == 'Y');
	 
	cout << "Goodbye!";  
    return 0;
}
