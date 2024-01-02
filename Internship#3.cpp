#include<iostream>   //TIC TAC TOE
#include<conio.h>
using namespace std;
char currentPlayer = 'X';

class Game{
	private:      //To keep following data types hidding from public

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int moves=0;

public:
	  //Display headings and let the user to press any key to start to game
	void intro(){
    cout << "\t\t*******WELCOME TO TIC TAC TOE*******\n";
    cout<<"Press Enter to start the game...";
    getch();}
    
void displayBoard() {//To display 3x3 grid (tic tac toe board)
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "\t" << board[i][j];
        }
        cout << endl << endl;
    }
}

void enterMove() {//Checks all the conditions of user's move
    int move;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;//Prompt user to enter his/her move

    // Convert move to row and column indices
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    // Check if the entered move is valid and not already filled
    if (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
    } else {
        cout << "Invalid move. Try again.\n";
        enterMove();
    }
}

bool checkWin() {
    // Check conditions for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;  // Row win
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;  // Column win
        }
    }

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;  // Diagonal win (top-left to bottom-right)
    }

    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;  // Diagonal win (top-right to bottom-left)
    }

    return false;  // No win yet
}
bool checkDraw() {//Checking condition in case game is draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;  // At least one empty box
            }
        }
    }
    return true;  // All boxes filled yet no result (draw)
}
void result(){
    while (true) {
    	
        enterMove(); //calling function
        displayBoard();
        moves++;

        if (checkWin()) {//Displays winning result  by calling function
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw()) {//Display draw result by calling function
            cout << "The game is a draw!\n";
            break;
        }
      if(currentPlayer=='X')//For alternative tokens or for switching X and 0 player
      
      {currentPlayer='0';}
      
	   else if(currentPlayer=='0')
      {currentPlayer='X';}
	  }}};

int main() {
	Game g;  //object of class which through which functions of class could be accessed
	
    g.intro(); //Calling functions to perform their respective jobs
    g.displayBoard();
    g.result();
}


