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
    // SETUP
    BoardEmpty board;
    Rook rook(7, 7, false /*white*/);
    rook.fWhite = true;
    rook.position.set(2, 1);
    board.board[2][1] = &rook;
    White w1(PAWN);
    board.board[2][0] = &w1; // C1
    White w2(PAWN);
    board.board[1][1] = &w2; // B2
    White w3(PAWN);
    board.board[2][2] = &w3; // C3
    White w4(PAWN);
    board.board[3][1] = &w4; // D2
    set <Move> moves;

    // EXERCISE
    rook.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.empty());

    // TEARDOWN
    board.board[2][1] = nullptr; // white rook
    board.board[2][0] = nullptr; // white pawn 1
    board.board[1][1] = nullptr; // white pawn 2
    board.board[2][2] = nullptr; // white pawn 3
    board.board[3][1] = nullptr; // white pawn 4
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
    // SETUP
    BoardEmpty board;
    Rook rook(7, 7, false /*white*/);
    rook.fWhite = true;
    rook.position.set(2, 1);
    board.board[2][1] = &rook;
    set <Move> moves;

    // EXERCISE
    rook.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 14);
    assertUnit(moves.find(Move("c2c8")) != moves.end());
    assertUnit(moves.find(Move("c2c1")) != moves.end());
    assertUnit(moves.find(Move("c2a2")) != moves.end());
    assertUnit(moves.find(Move("c2h2")) != moves.end());

    // TEARDOWN
    board.board[2][1] = nullptr; // white rook
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
    // SETUP
    BoardEmpty board;
    Rook rook(7, 7, false /*white*/);
    rook.fWhite = true;
    rook.position.set(2, 1);
    board.board[2][1] = &rook;
    White w1(PAWN);
    board.board[0][1] = &w1; // A2
    White w2(PAWN);
    board.board[2][0] = &w2; // C1
    White w3(PAWN);
    board.board[7][1] = &w3; // H2
    White w4(PAWN);
    board.board[2][7] = &w4; // C8
    set <Move> moves;

    // EXERCISE
    rook.getMoves(moves, board);

    // VERIFY
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

    // TEARDOWN
    board.board[2][1] = nullptr; // white rook
    board.board[0][1] = nullptr; // white pawn 1
    board.board[2][0] = nullptr; // white pawn 2
    board.board[7][1] = nullptr; // white pawn 3
    board.board[2][7] = nullptr; // white pawn 4
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
    // SETUP
    BoardEmpty board;
    Rook rook(7, 7, false /*white*/);
    rook.fWhite = true;
    rook.position.set(2, 1);
    board.board[2][1] = &rook;
    Black b1(PAWN);
    board.board[0][1] = &b1; // A2
    Black b2(PAWN);
    board.board[2][0] = &b2; // C1
    Black b3(PAWN);
    board.board[7][1] = &b3; // H2
    Black b4(PAWN);
    board.board[2][7] = &b4; // C8
    set <Move> moves;

    // EXERCISE
    rook.getMoves(moves, board);

    // VERIFY
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

    // TEARDOWN
    board.board[2][1] = nullptr; // white rook
    board.board[0][1] = nullptr; // black pawn 1
    board.board[2][0] = nullptr; // black pawn 2
    board.board[7][1] = nullptr; // black pawn 3
    board.board[2][7] = nullptr; // black pawn 4
}

/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
    // SETUP
    Rook rook(7, 7, false);
    PieceType pt;

    // EXERCISE
    pt = rook.getType();

    // VERIFY
    assertEquals(ROOK, pt);
}  // TEARDOWN