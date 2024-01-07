#include <iostream>
using namespace std;

class TicTacToe{
	// Keeping the following members hidden from public
private:	
    char board[3][3];
    char currentPlayer;
    int move;
    string playAgain;
    
   public: 
   //Constructor to initialize the boar and currentPlayer
   TicTacToe():currentPlayer('X'){
   	initBoard(board);
   }
   
   void displayHeading(){//For displaying main heading and wait for the user to input
   	cout<<"\t\t*******WELCOME TO TIC TAC TOE*******"<<endl<<endl;
	cout<<"Press Enter to continue...";
	cin.ignore();
   }
   
void playGame(){//Controls the major part of program
    do {
        // Initialize the board
        initBoard(board);
        currentPlayer = 'X';

        // Game loop
        do {
            displayBoard(board);//To display the board

            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;//Prompt user to enter a move

            if(move<1 || move>9)//checking input validation 
            {
            	cin.clear();
            	cin.ignore();
            	cout<<"Invalid input,please enter number in the range of 1 to 9: ";
            	continue;
			}

            if (makeMove(board, move, currentPlayer)) {
                if (checkWin(board, currentPlayer))//For Checking winning conditions
				 {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                } else if (checkDraw(board))//For Checking draw conditions
				 {
                    displayBoard(board);
                    cout << "It's a draw!" << endl;
                    break;
                }

                // Switch player for the next move
                switchPlayer(currentPlayer);
            } else {
                cout << "Invalid move. Try again." << endl;
            }

        } while (true);

        // Ask to play again
        cout << "Do you want to play again? (yes/no): ";
        cin >> playAgain;//taking yes/no as an input

    }
	 while (playAgain == "yes" || playAgain == "YES" ||playAgain == "Yes" );
	//if yes , program will execute again ignoring case sensitivity

 cout << "Thanks for playing Tic Tac Toe!" << endl;
 //else it ends by displaying thanks message

}

// Function to initialize the board
void initBoard(char board[3][3]) {
    char cell = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = cell++;//Assigning numbers to 3x3 board
        }
    }
}

// Function to display the board
void displayBoard(char board[3][3]) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl << endl;
    }
}

// Function to make a move
bool makeMove(char board[3][3], int move, char currentPlayer) {
    // Check if the move is valid
    if (move < 1 || move > 9) {
        return false;
    }

    // Convert move to array indices
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    // Check if the cell is empty
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        return false;
    }
}

// Function to check for a win
bool checkWin(char board[3][3], char currentPlayer) {
    for (int i = 0; i < 3; i++) {
      if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true; // Row win
      if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true; // Column win
    }

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true; // Diagonal win (top left to bottom right)
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true; // Diagonal win (top right to bottom left)

    return false;
}

// Function to check for a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false; // At least one empty box

    return true; // All boxes filled yet no winner, draw
}
      // Function to switch players
void switchPlayer(char& currentPlayer) {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else if (currentPlayer == 'O') {
        currentPlayer = 'X';
    }
}};

int main()
{
	TicTacToe game;// Creating object if class through which we access the member functions inside class
	game.displayHeading();//Calling for intro heading
	game.playGame();//Calling for playing the game (flow of actual program)
}


    


    
   
        
      
	
