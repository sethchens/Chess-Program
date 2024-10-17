/***********************************************************************
 * Source File:
 *    TEST QUEEN
 * Author:
 *    Chris Mijangos and Seth Chen
 * Summary:
 *    The unit tests for the queen
 ************************************************************************/

#include "testQueen.h"
#include "pieceQueen.h"     
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
  * 3     p p p           3
  * 2     p(q)p           2
  * 1     p p p           1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestQueen::getMoves_blocked()
{
    // SETUP
    BoardEmpty board;
    Queen queen(7, 7, false /*white*/);
    queen.fWhite = true;
    queen.position.set(2, 1);
    board.board[2][1] = &queen;
    White w1(PAWN);
    board.board[1][0] = &w1; // B1
    White w2(PAWN);
    board.board[1][1] = &w2; // B2
    White w3(PAWN);
    board.board[1][2] = &w3; // B3
    White w4(PAWN);
    board.board[2][0] = &w4; // C1
    White w5(PAWN);
    board.board[2][2] = &w5; // C3
    White w6(PAWN);
    board.board[3][0] = &w6; // D1
    White w7(PAWN);
    board.board[3][1] = &w7; // D2
    White w8(PAWN);
    board.board[3][2] = &w8; // D3
    set <Move> moves;

    // EXERCISE
    queen.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.empty());

    // TEARDOWN
    board.board[2][1] = nullptr; // white queen
    board.board[1][0] = nullptr; // white pawn 1
    board.board[1][1] = nullptr; // white pawn 2
    board.board[1][2] = nullptr; // white pawn 3
    board.board[2][0] = nullptr; // white pawn 4
    board.board[2][2] = nullptr; // white pawn 5
    board.board[3][0] = nullptr; // white pawn 6
    board.board[3][1] = nullptr; // white pawn 7
    board.board[3][2] = nullptr; // white pawn 8
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .         .   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   .   .   .         4
 * 3     . . .           3
 * 2   . .(q). . . . .   2
 * 1     . . .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToEnd()
{
    // SETUP
    BoardEmpty board;
    Queen queen(7, 7, false /*white*/);
    queen.fWhite = true;
    queen.position.set(2, 1);
    board.board[2][1] = &queen;
    set <Move> moves;

    // EXERCISE
    queen.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 23);

    // Check moves
    assertUnit(moves.find(Move("c2a2")) != moves.end());
    assertUnit(moves.find(Move("c2a4")) != moves.end());
    assertUnit(moves.find(Move("c2b1")) != moves.end());
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2c1")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());
    assertUnit(moves.find(Move("c2c8")) != moves.end());
    assertUnit(moves.find(Move("c2d1")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2h2")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());
    assertUnit(moves.find(Move("c2h7")) != moves.end());

    // TEARDOWN
    board.board[2][1] = nullptr; // white queen
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .         p   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   p   .   .         4
 * 3     . . .           3
 * 2   p .(q). . . . p   2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToBlock()
{
    // SETUP
    BoardEmpty board;
    Queen queen(7, 7, false /*white*/);
    queen.fWhite = true;
    queen.position.set(2, 1);
    board.board[2][1] = &queen;
    White w1(PAWN);
    board.board[2][7] = &w1; // C8
    White w2(PAWN);
    board.board[7][6] = &w2; // H7
    White w3(PAWN);
    board.board[0][3] = &w3; // A4
    White w4(PAWN);
    board.board[0][1] = &w4; // A2
    White w5(PAWN);
    board.board[7][1] = &w5; // H2
    White w6(PAWN);
    board.board[1][0] = &w6; // B1
    White w7(PAWN);
    board.board[2][0] = &w7; // C1
    White w8(PAWN);
    board.board[3][0] = &w8; // D1
    set <Move> moves;

    // EXERCISE
    queen.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 15);
    // Check moves
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());

    // TEARDOWN
    board.board[2][1] = nullptr; // white queen
    board.board[2][7] = nullptr; // white pawn 1
    board.board[7][6] = nullptr; // white pawn 2
    board.board[0][3] = nullptr; // white pawn 3
    board.board[0][1] = nullptr; // white pawn 4
    board.board[7][1] = nullptr; // white pawn 5
    board.board[1][0] = nullptr; // white pawn 6
    board.board[2][0] = nullptr; // white pawn 7
    board.board[3][0] = nullptr; // white pawn 8
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .         P   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   P   .   .         4
 * 3     . . .           3
 * 2   P .(q). . . . P   2
 * 1     P P P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToCapture()
{
    // SETUP
    BoardEmpty board;
    Queen queen(7, 7, false /*white*/);
    queen.fWhite = true;
    queen.position.set(2, 1);
    board.board[2][1] = &queen;
    Black b1(PAWN);
    board.board[2][7] = &b1; // C8
    Black b2(PAWN);
    board.board[7][6] = &b2; // H7
    Black b3(PAWN);
    board.board[0][3] = &b3; // A4
    Black b4(PAWN);
    board.board[0][1] = &b4; // A2
    Black b5(PAWN);
    board.board[7][1] = &b5; // H2
    Black b6(PAWN);
    board.board[1][0] = &b6; // B1
    Black b7(PAWN);
    board.board[2][0] = &b7; // C1
    Black b8(PAWN);
    board.board[3][0] = &b8; // D1
    set <Move> moves;

    // EXERCISE
    queen.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 23);
    // Check some key moves
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());
    assertUnit(moves.find(Move("c2a2p")) != moves.end());
    assertUnit(moves.find(Move("c2a4p")) != moves.end());
    assertUnit(moves.find(Move("c2b1p")) != moves.end());
    assertUnit(moves.find(Move("c2c1p")) != moves.end());
    assertUnit(moves.find(Move("c2c8p")) != moves.end());
    assertUnit(moves.find(Move("c2d1p")) != moves.end());
    assertUnit(moves.find(Move("c2h2p")) != moves.end());
    assertUnit(moves.find(Move("c2h7p")) != moves.end());

    // TEARDOWN
    board.board[2][1] = nullptr; // white queen
    board.board[2][7] = nullptr; // black pawn 1
    board.board[7][6] = nullptr; // black pawn 2
    board.board[0][3] = nullptr; // black pawn 3
    board.board[0][1] = nullptr; // black pawn 4
    board.board[7][1] = nullptr; // black pawn 5
    board.board[1][0] = nullptr; // black pawn 6
    board.board[2][0] = nullptr; // black pawn 7
    board.board[3][0] = nullptr; // black pawn 8
}

/*************************************
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
    // SETUP
    Queen queen(7, 7, false);
    PieceType pt;

    // EXERCISE
    pt = queen.getType();

    // VERIFY
    assertEquals(QUEEN, pt);
}  // TEARDOWN
