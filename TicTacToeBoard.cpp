#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  turn_count = 0;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
    if (turn == X) {
		turn = O;
	} else {
		turn = X;
	}
	return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	if (row > 2 || row < 0 || column > 2 || column < 0) {
		return Invalid;
	}
	if (turn_count > 8) {
		return Blank;
	}
	if (board[row][column] != Blank) {
		return board[row][column];
	}
	toggleTurn();
	turn_count++;
	if (turn == X) {
		board[row][column] = O;
		return O;
	} else {
		board[row][column] = X;
		return X;
	}
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if (row > 2 || row < 0 || column > 2 || column < 0) {
		return Invalid;
	}
	return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	//rows
	if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != Blank) 
		return board[0][0];
	if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != Blank) 
		return board[1][0];
	if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != Blank) 
		return board[2][0];

	//columns
	if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != Blank) 
		return board[0][0];
	if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != Blank) 
		return board[0][1];
	if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != Blank) 
		return board[0][2];

	//diags
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != Blank) 
		return board[0][0];
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != Blank) 
		return board[0][2];

	//no winner, game is still going
	if (turn_count < 9) {
		return Invalid;
	}

	//stalemate
	return Blank;
}
