/***********************************************************************
 * Source File:
 *    TEST BISHOP
 * Author:
 *    Chris Mijangos and Seth Chen
 * Summary:
 *    The unit tests for a bishop
 ************************************************************************/


#include "testBishop.h"
#include "pieceBishop.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      




 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5                     5
  * 4                     4
  * 3     p   p           3
  * 2      (b)            2
  * 1     p   p           1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestBishop::getMoves_blocked()
{
    // Setup
    BoardEmpty board;
    Bishop* bishop = new Bishop(2, 1, true); // White bishop at c2
    board.board[2][1] = bishop;
    // Place blocking pieces
    board.board[1][0] = new PieceSpy(1, 0, true, PAWN); // Pawn at b1
    board.board[1][2] = new PieceSpy(1, 2, true, PAWN); // Pawn at b3
    board.board[3][0] = new PieceSpy(3, 0, true, PAWN); // Pawn at d1
    board.board[3][2] = new PieceSpy(3, 2, true, PAWN); // Pawn at d3

    // Exercise
    set<Move> moves;
    bishop->getMoves(moves, board);

    // Verify
    assertUnit(moves.empty());

    // Teardown
    delete bishop;
    delete board.board[1][0]; // b1
    delete board.board[1][2]; // b3
    delete board.board[3][0]; // d1
    delete board.board[3][2]; // d3
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 .   7
 * 6               .     6
 * 5             .       5
 * 4   .       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     .   .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToEnd()
{
    // Setup
    BoardEmpty board;
    Bishop* bishop = new Bishop(2, 1, true); // White bishop at c2
    board.board[2][1] = bishop;

    // Exercise
    set<Move> moves;
    bishop->getMoves(moves, board);

    // Verify
    assertUnit(moves.size() == 9);  // Bishop can move to 11 squares from c2
    assertUnit(moves.find(Move("c2b1")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2a4")) != moves.end());
    assertUnit(moves.find(Move("c2d1")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());
    assertUnit(moves.find(Move("c2h7")) != moves.end());

    // Teardown
    delete bishop;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 p   7
 * 6               .     6
 * 5             .       5
 * 4   p       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToBlock()
{
    // Setup
    BoardEmpty board;
    Bishop* bishop = new Bishop(2, 1, true); // White bishop at c2
    board.board[2][1] = bishop;
    // Place blocking pieces
    board.board[7][6] = new PieceSpy(7, 6, true, PAWN);  // Pawn at h7
    board.board[0][3] = new PieceSpy(0, 3, true, PAWN);  // Pawn at a4
    board.board[1][0] = new PieceSpy(1, 0, true, PAWN);  // Pawn at b1
    board.board[3][0] = new PieceSpy(3, 0, true, PAWN);  // Pawn at d1

    // Exercise
    set<Move> moves;
    bishop->getMoves(moves, board);

    // Verify
    assertUnit(moves.size() == 5);
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());

    // Teardown
    delete bishop;
    delete board.board[7][6];
    delete board.board[0][3];
    delete board.board[1][0];
    delete board.board[3][0];
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 P   7
 * 6               .     6
 * 5             .       5
 * 4   P       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     P   P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToCapture()
{
    // Setup
    BoardEmpty board;
    Bishop* bishop = new Bishop(2, 1, true); // White bishop at c2
    board.board[2][1] = bishop;
    // Place blocking pieces
    board.board[0][3] = new PieceSpy(0, 3, false, PAWN); // Black pawn at a4
    board.board[7][6] = new PieceSpy(7, 6, false, PAWN); // Black pawn at h7
    board.board[1][0] = new PieceSpy(1, 0, false, PAWN); // Black pawn at b1
    board.board[3][0] = new PieceSpy(3, 0, false, PAWN); // Black pawn at d1

    // Exercise
    set<Move> moves;
    bishop->getMoves(moves, board);

    // Verify
    assertUnit(moves.size() == 9);
    assertUnit(moves.find(Move("c2b1p")) != moves.end());
    assertUnit(moves.find(Move("c2d1p")) != moves.end());
    assertUnit(moves.find(Move("c2a4p")) != moves.end());
    assertUnit(moves.find(Move("c2h7p")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());

    // Teardown
    delete bishop;
    delete board.board[0][3]; // a4
    delete board.board[7][6]; // h7
    delete board.board[1][0]; // b1
    delete board.board[3][0]; // d1
}


/*************************************
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
    // Setup
    Bishop bishop(0, 0, true);

    // Exercise
    PieceType type = bishop.getType();

    // Verify
    assertUnit(type == BISHOP);
}

