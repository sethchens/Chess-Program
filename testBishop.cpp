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
    // SETUP
    BoardEmpty board;
    Bishop bishop(7, 7, false /*white*/);
    bishop.fWhite = true;
    bishop.position.set(2, 1);
    board.board[2][1] = &bishop;
    White w1(PAWN);
    board.board[1][0] = &w1;
    White w2(PAWN);
    board.board[1][2] = &w2;
    White w3(PAWN);
    board.board[3][0] = &w3;
    White w4(PAWN);
    board.board[3][2] = &w4;
    set <Move> moves;

    // EXERCISE
    bishop.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.empty());

    // TEARDOWN
    board.board[2][1] = nullptr; // white bishop
    board.board[1][0] = nullptr; // white pawn 1
    board.board[1][2] = nullptr; // white pawn 2
    board.board[3][0] = nullptr; // white pawn 3
    board.board[3][2] = nullptr; // white pawn 4
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
    // SETUP
    BoardEmpty board;
    Bishop bishop(7, 7, false /*white*/);
    bishop.fWhite = true;
    bishop.position.set(2, 1);
    board.board[2][1] = &bishop;
    set <Move> moves;

    // EXERCISE
    bishop.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 9);  // Bishop can move to 9 squares from c2
    assertUnit(moves.find(Move("c2b1")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2a4")) != moves.end());
    assertUnit(moves.find(Move("c2d1")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());
    assertUnit(moves.find(Move("c2h7")) != moves.end());

    // TEARDOWN
    board.board[2][1] = nullptr; // white bishop
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
    // SETUP
    BoardEmpty board;
    Bishop bishop(7, 7, false /*white*/);
    bishop.fWhite = true;
    bishop.position.set(2, 1);
    board.board[2][1] = &bishop;
    White w1(PAWN);
    board.board[7][6] = &w1;
    White w2(PAWN);
    board.board[0][3] = &w2;
    White w3(PAWN);
    board.board[1][0] = &w3;
    White w4(PAWN);
    board.board[3][0] = &w4;
    set <Move> moves;

    // EXERCISE
    bishop.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 5);
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());

    // TEARDOWN
    board.board[2][1] = nullptr; // white bishop
    board.board[7][6] = nullptr; // white pawn 1
    board.board[0][3] = nullptr; // white pawn 2
    board.board[1][0] = nullptr; // white pawn 3
    board.board[3][0] = nullptr; // white pawn 4
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
    // SETUP
    BoardEmpty board;
    Bishop bishop(7, 7, false /*white*/);
    bishop.fWhite = true;
    bishop.position.set(2, 1);
    board.board[2][1] = &bishop;
    Black b1(PAWN);
    board.board[0][3] = &b1;
    Black b2(PAWN);
    board.board[7][6] = &b2;
    Black b3(PAWN);
    board.board[1][0] = &b3;
    Black b4(PAWN);
    board.board[3][0] = &b4;
    set <Move> moves;

    // EXERCISE
    bishop.getMoves(moves, board);

    // VERIFY
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

    // TEARDOWN
    board.board[2][1] = nullptr; // white bishop
    board.board[0][3] = nullptr; // black pawn 1
    board.board[7][6] = nullptr; // black pawn 2
    board.board[1][0] = nullptr; // black pawn 3
    board.board[3][0] = nullptr; // black pawn 4
}

/*************************************
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
    // SETUP
    Bishop bishop(7, 7, false);
    PieceType pt;

    // EXERCISE
    pt = bishop.getType();

    // VERIFY
    assertEquals(BISHOP, pt);
}  // TEARDOWN

