/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/*toggleTurn() tests*/
TEST(TicTacToeBoardTest, toggleTurnO) {
	TicTacToeBoard board;
	ASSERT_EQ(board.toggleTurn(), O);
}
TEST(TicTacToeBoardTest, toggleTurnX) {
	TicTacToeBoard board;
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), X);
}
TEST(TicTacToeBoardTest, toggleTurn3) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), O);
}

/*placePiece(row,column) tests*/
TEST(TicTacToeBoardTest, placePiece00) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,0), X);
}
TEST(TicTacToeBoardTest, placePiece01) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,1), X);
}
TEST(TicTacToeBoardTest, placePiece02) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,2), X);
}
TEST(TicTacToeBoardTest, placePiece10) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(1,0), X);
}
TEST(TicTacToeBoardTest, placePiece11) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(1,1), X);
}
TEST(TicTacToeBoardTest, placePiece12) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(1,2), X);
}
TEST(TicTacToeBoardTest, placePiece20) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(2,0), X);
}
TEST(TicTacToeBoardTest, placePiece21) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(2,1), X);
}
TEST(TicTacToeBoardTest, placePiece22) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(2,2), X);
}
TEST(TicTacToeBoardTest, placePieceOutofBoundsRowLess) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1,0), Invalid);
}
TEST(TicTacToeBoardTest, placePieceOutofBoundsRowGreater) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(3,0), Invalid);
}
TEST(TicTacToeBoardTest, placePieceOutofBoundsColumnLess) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,-1), Invalid);
}
TEST(TicTacToeBoardTest, placePieceOutofBoundsColumnGreater) {
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,3), Invalid);
}
TEST(TicTacToeBoardTest, placePieceTooManyTurns) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(1,0);
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.placePiece(2,0);
	board.placePiece(2,1);
	board.placePiece(2,2);
	ASSERT_EQ(board.placePiece(0,0), Blank);
}
TEST(TicTacToeBoardTest, placePieceAlmostTooManyTurns) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(1,0);
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.placePiece(2,0);
	board.placePiece(2,1);
	ASSERT_EQ(board.placePiece(2,2), X);
}
TEST(TicTacToeBoardTest, placePieceSamePlace) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.placePiece(0,0), X);
}

/*getPiece(row,column) tests*/
TEST(TicTacToeBoardTest, getPieceOutofBoundsRowLess) {
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(-1,0), Invalid);
}
TEST(TicTacToeBoardTest, getPieceOutofBoundsRowGreater) {
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(3,0), Invalid);
}
TEST(TicTacToeBoardTest, getPieceOutofBoundsColumnLess) {
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(0,-1), Invalid);
}
TEST(TicTacToeBoardTest, getPieceOutofBoundsColumnGreater) {
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(0,3), Invalid);
}
TEST(TicTacToeBoardTest, getPieceEmptySpace) {
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(1,1), Blank);
}
TEST(TicTacToeBoardTest, getPieceX) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.getPiece(0,0), X);
}
TEST(TicTacToeBoardTest, getPieceO) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.placePiece(0,0);
	ASSERT_EQ(board.getPiece(0,0), O);
}

/*getWinner() tests*/
TEST(TicTacToeBoardTest, getWinnerRow0) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(1,0);
	board.placePiece(0,1);
	board.placePiece(2,0);
	board.placePiece(0,2);
	ASSERT_EQ(board.getWinner(), X);
}
TEST(TicTacToeBoardTest, getWinnerRow1) {
	TicTacToeBoard board;
	board.placePiece(1,0);
	board.placePiece(0,0);
	board.placePiece(1,1);
	board.placePiece(2,0);
	board.placePiece(1,2);
	ASSERT_EQ(board.getWinner(), X);
}
TEST(TicTacToeBoardTest, getWinnerRow2) {
	TicTacToeBoard board;
	board.placePiece(2,0);
	board.placePiece(0,0);
	board.placePiece(2,1);
	board.placePiece(1,0);
	board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(), X);
}
TEST(TicTacToeBoardTest, getWinnerColumn0) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(2,0);
	board.placePiece(1,0);
	board.placePiece(2,1);
	board.placePiece(2,0);
	ASSERT_EQ(board.getWinner(), X);
}
TEST(TicTacToeBoardTest, getWinnerColumn1) {
	TicTacToeBoard board;
	board.placePiece(0,1);
	board.placePiece(2,0);
	board.placePiece(1,1);
	board.placePiece(2,2);
	board.placePiece(2,1);
	ASSERT_EQ(board.getWinner(), X);
}
TEST(TicTacToeBoardTest, getWinnerColumn2) {
	TicTacToeBoard board;
	board.placePiece(0,2);
	board.placePiece(2,0);
	board.placePiece(1,2);
	board.placePiece(0,1);
	board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(), X);
}
TEST(TicTacToeBoardTest, getWinnerDiag0) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(2,0);
	board.placePiece(1,1);
	board.placePiece(0,1);
	board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(), X);
}
TEST(TicTacToeBoardTest, getWinnerDiag1) {
	TicTacToeBoard board;
	board.placePiece(0,2);
	board.placePiece(2,2);
	board.placePiece(1,1);
	board.placePiece(0,1);
	board.placePiece(2,0);
	ASSERT_EQ(board.getWinner(), X);
}
TEST(TicTacToeBoardTest, getWinnerNoWinnerGameOn) {
	TicTacToeBoard board;
	board.placePiece(0,2);
	board.placePiece(2,2);
	board.placePiece(1,1);
	board.placePiece(0,1);
	ASSERT_EQ(board.getWinner(), Invalid);
}
TEST(TicTacToeBoardTest, getWinnerStalemate) {
	TicTacToeBoard board;
	board.placePiece(0,1);
	board.placePiece(0,0);
	board.placePiece(1,1);
	board.placePiece(0,2);
	board.placePiece(1,2);
	board.placePiece(1,0);
	board.placePiece(2,0);
	board.placePiece(2,1);
	board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(), Blank);
}
