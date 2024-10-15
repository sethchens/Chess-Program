/***********************************************************************
 * Source File:
 *    TEST ROOK
 * Author:
 *    Chris Mijangos and Seth Chen
 * Summary:
 *    The unit tests for the rook
 ************************************************************************/

#include "testRook.h"
#include "pieceRook.h"     
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
  * 3       p             3
  * 2     p(r)p           2
  * 1       p             1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestRook::getMoves_blocked()
{
    // Setup
    BoardEmpty board;
    Rook* rook = new Rook(2, 1, true); // White rook at c2
    board.board[2][1] = rook;
    // Place blocking pieces
    board.board[2][0] = new PieceSpy(2, 0, true, PAWN); //C1
    board.board[1][1] = new PieceSpy(1, 1, true, PAWN); //B2
    board.board[2][2] = new PieceSpy(2, 2, true, PAWN); //C3
    board.board[3][1] = new PieceSpy(3, 1, true, PAWN); //D2

    // Exercise
    set<Move> moves;
    rook->getMoves(moves, board);

    // Verify
    assertUnit(moves.empty());

    // Teardown
    delete rook;
    delete board.board[2][0];
    delete board.board[1][1];
    delete board.board[2][2];
    delete board.board[3][1];
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   . .(r). . . . .   2
 * 1       .             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToEnd()
{
    // Setup
    BoardEmpty board;
    Rook* rook = new Rook(2, 1, true); // White rook at c2
    board.board[2][1] = rook;

    // Exercise
    set<Move> moves;
    rook->getMoves(moves, board);

    // Verify
    assertUnit(moves.size() == 14);
    assertUnit(moves.find(Move("c2c8")) != moves.end());
    assertUnit(moves.find(Move("c2c1")) != moves.end());
    assertUnit(moves.find(Move("c2a2")) != moves.end());
    assertUnit(moves.find(Move("c2h2")) != moves.end());

    // Teardown
    delete rook;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   p .(r). . . . p   2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToBlock()
{
    // Setup
    BoardEmpty board;
    Rook* rook = new Rook(2, 1, true); // White rook at c2
    board.board[2][1] = rook;
    // Place blocking pieces
    board.board[0][1] = new PieceSpy(1, 1, true, PAWN); //A2
    board.board[2][0] = new PieceSpy(2, 0, true, PAWN); //C1
    board.board[7][1] = new PieceSpy(7, 1, true, PAWN); //H2
    board.board[2][7] = new PieceSpy(2, 7, true, PAWN); //C8

    // Exercise
    set<Move> moves;
    rook->getMoves(moves, board);

    // Verify
    assertUnit(moves.size() == 10);
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());


    // Teardown
    delete rook;
    delete board.board[0][1];
    delete board.board[2][0];
    delete board.board[7][1];
    delete board.board[2][7];
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   P .(r). . . . P   2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToCapture()
{
    // Setup
    BoardEmpty board;
    Rook* rook = new Rook(2, 1, true); // White rook at c2
    board.board[2][1] = rook;
    // Place blocking pieces
    board.board[0][1] = new PieceSpy(1, 1, false, PAWN); //A2
    board.board[2][0] = new PieceSpy(2, 0, false, PAWN); //C1
    board.board[7][1] = new PieceSpy(7, 1, false, PAWN); //H2
    board.board[2][7] = new PieceSpy(2, 7, false, PAWN); //C8

    // Exercise
    set<Move> moves;
    rook->getMoves(moves, board);

    // Verify
    assertUnit(moves.size() == 14);
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2a2p")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2h2p")) != moves.end());
    assertUnit(moves.find(Move("c2c1p")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());
    assertUnit(moves.find(Move("c2c8p")) != moves.end());


    // Teardown
    delete rook;
    delete board.board[0][1];
    delete board.board[2][0];
    delete board.board[7][1];
    delete board.board[2][7];
}


/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
    // Setup
    Rook rook(0, 0, true);

    // Exercise
    PieceType type = rook.getType();

    // Verify
    assertUnit(type == ROOK);
}
