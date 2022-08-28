#include<iostream>
using namespace std;

//Defining the global variables
const int ROWS = 3;
const int COLUMNS = 3;

//Defining the function prototypes
void displayBoard(char[][COLUMNS]);
void playerTurn(char[][COLUMNS], char);
bool gameOver(char[][COLUMNS]);
bool playerWins(char[][COLUMNS], char);
bool playerCanWin(char[][COLUMNS], char);
void displayWinner(char[][COLUMNS]);

int main()
{
	//This line will be displaying the gameboard in 3x3, using the "*" symbol, basically the array.
	char gameBoard[ROWS][COLUMNS] = {'*', '*' , '*',
								   '*', '*' , '*',
								   '*', '*' , '*' };

	// This loop will continue until someone wins or when it's a tie
	do
	{
		displayBoard(gameBoard);
		playerTurn(gameBoard, 'X');
		displayBoard(gameBoard);

		if (!gameOver(gameBoard))
			playerTurn(gameBoard, 'O');

	} while(!gameOver(gameBoard));

	displayBoard(gameBoard);
	displayWinner(gameBoard); // This function will display the winner of the game or if the game is a tie

	return 0;
}
// This function will keep displaying the board after every turn
void displayBoard(char board[][COLUMNS])
{
	cout << "      Columns" << endl;
	cout << "       1  2  3" << endl;

	for (int row = 0; row < ROWS; row++)
	{
		cout << "Row" << (row + 1) << ":  ";

		for (int col = 0; col < COLUMNS; col++)
		{
			cout << board[row][col] << "  ";

		}
		cout << endl;
	}
}
// This function allows the players to take turns
void playerTurn(char board[][COLUMNS], char symbol)
{
	bool isAvailable = false;

	int row;
	int col;

	cout << "Player " << symbol << "'s turn" << endl;
	cout << "Enter a row and colum to a place an " << symbol << "." << endl;
	// Loop to verify the location
	while (!isAvailable)
	{
		cout << "Row: ";
		cin >> row;
		// Validate the row
		while (row < 1 || row > ROWS)
		{
			cout << "Invalid Row!" << endl;
			cout << "Row: ";
			cin >> row;
		}

		cout << "Column: ";
		cin >> col;
		// Validate the column
		while (col < 1 || col > COLUMNS)
		{
			cout << "Invalid Column!" << endl;
			cout << "Column: ";
			cin >> col;
		}

		if (board[row - 1][col - 1] == '*')
			isAvailable = true;
		else
		{
			cout << "That location is not available" << endl;
			cout << "Select another location" << endl;
		}
	}
	board[row - 1][col - 1] = symbol;
}

//This function will continue to check if the game has ended
bool gameOver(char board[][COLUMNS])
{
	bool status;

	if (playerWins(board, 'X') || playerWins(board, 'O'))
		status = true;
	else if (playerCanWin(board, 'X') || playerCanWin(board, 'O'))
		status = false;
	else
		status = true;

	return status;
}

bool playerWins(char board[][COLUMNS], char symbol)
{
	bool status = false;

	// These three "if" statements will check the horizontal row
	if (board[0][0] == symbol &&
		board[0][1] == symbol &&
		board[0][2] == symbol)
		status = true;
	if (board[1][0] == symbol &&
		board[1][1] == symbol &&
		board[1][2] == symbol)
		status = true;
	if (board[2][0] == symbol &&
		board[2][1] == symbol &&
		board[2][2] == symbol)
		status = true;

	// These three "if" statements will check the vertical row
	if (board[0][0] == symbol &&
		board[1][0] == symbol &&
		board[2][0] == symbol)
		status = true;
	if (board[0][1] == symbol &&
		board[1][1] == symbol &&
		board[2][1] == symbol)
		status = true;
	if (board[0][2] == symbol &&
		board[1][2] == symbol &&
		board[2][2] == symbol)
		status = true;

	// This "if" statement will check the diagonal
	if (board[0][0] == symbol &&
		board[1][1] == symbol &&
		board[2][2] == symbol)
		status = true;

	return status;
}
// If there is a "*" on the board, the game will continue
bool playerCanWin(char board[][COLUMNS], char symbol)
{
	bool status = false;
	// These 3 "if" statements will check the horizontal rows if there are any "*" remaining
	if ((board[0][0] == symbol || board[0][0] == '*') &&
		(board[0][1] == symbol || board[0][1] == '*') &&
		(board[0][2] == symbol || board[0][2] == '*'))
		status = true;
	if ((board[1][0] == symbol || board[1][0] == '*') &&
		(board[1][1] == symbol || board[1][1] == '*') &&
		(board[1][2] == symbol || board[1][2] == '*'))
		status = true;
	if ((board[2][0] == symbol || board[2][0] == '*') &&
		(board[2][1] == symbol || board[2][1] == '*') &&
		(board[2][2] == symbol || board[2][2] == '*'))
		status = true;

	// These 3 "if" statements will check the vertical rows if there are any "*" remaining
	if ((board[0][0] == symbol || board[0][0] == '*') &&
		(board[1][0] == symbol || board[1][0] == '*') &&
		(board[2][0] == symbol || board[2][0] == '*'))
		status = true;
	if ((board[0][1] == symbol || board[0][1] == '*') &&
		(board[1][1] == symbol || board[1][1] == '*') &&
		(board[2][1] == symbol || board[2][1] == '*'))
		status = true;
	if ((board[0][2] == symbol || board[0][2] == '*') &&
		(board[1][2] == symbol || board[1][2] == '*') &&
		(board[2][2] == symbol || board[2][2] == '*'))
		status = true;

	// These 3 "if" statements will check the horizontal rows if there are any "*" remaining
	if ((board[0][0] == symbol || board[0][0] == '*') &&
		(board[1][1] == symbol || board[1][1] == '*') &&
		(board[2][2] == symbol || board[2][2] == '*'))
		status = true;

	return status;
}
// This function will display the winner of the game
void displayWinner(char board[][COLUMNS])
{
	if (playerWins(board, 'X'))
		cout << "Player 1 (X) WINS!" << endl;
	else if (playerWins(board, 'O'))
		cout << "Player 2 (O) WINS!" << endl;
	else
		cout << "Game Over... It's a TIE" << endl;
}
