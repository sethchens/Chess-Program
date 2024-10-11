/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#include "testKnight.h"
#include "pieceKnight.h"     
#include "board.h"
#include "uiDraw.h"
#include "pieceSpace.h"
#include <cassert>

 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5                     5
  * 4                     4
  * 3             p   .   3
  * 2           P         2
  * 1              (n)    1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestKnight::getMoves_end()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(6, 0);
   board.board[6][0] = &knight;
   Black black(PAWN);
   board.board[4][1] = &black;
   White white(PAWN);
   board.board[5][2] = &white;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(Move("g1e2p")) != moves.end());
   assertUnit(moves.find(Move("g1h3")) != moves.end());

   // TEARDOWN
   board.board[6][0] = nullptr; // white knight
   board.board[4][1] = nullptr; // black pawn
   board.board[5][2] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(4, 3);
   board.board[4][3] = &knight;
   White w1(PAWN);
   board.board[6][2] = &w1;
   White w2(PAWN);
   board.board[6][4] = &w2;
   White w3(PAWN);
   board.board[5][1] = &w3;
   White w4(PAWN);
   board.board[5][5] = &w4;
   White w5(PAWN);
   board.board[2][2] = &w5;
   White w6(PAWN);
   board.board[2][4] = &w6;
   White w7(PAWN);
   board.board[3][1] = &w7;
   White w8(PAWN);
   board.board[3][5] = &w8;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);  // many possible moves

   // TEARDOWN
   board.board[4][3] = nullptr; // white knight
   board.board[6][2] = nullptr; // white pawn 1
   board.board[6][4] = nullptr; // white pawn 2
   board.board[5][1] = nullptr; // white pawn 3
   board.board[5][5] = nullptr; // white pawn 4
   board.board[2][2] = nullptr; // white pawn 5
   board.board[2][4] = nullptr; // white pawn 6
   board.board[3][1] = nullptr; // white pawn 7
   board.board[3][5] = nullptr; // white pawn 8
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (N)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_capture()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, true /*white*/);
   knight.fWhite = false;
   knight.position.set(4, 3);
   board.board[4][3] = &knight;
   White w1(PAWN);
   board.board[6][2] = &w1;
   White w2(PAWN);
   board.board[6][4] = &w2;
   White w3(PAWN);
   board.board[5][1] = &w3;
   White w4(PAWN);
   board.board[5][5] = &w4;
   White w5(PAWN);
   board.board[2][2] = &w5;
   White w6(PAWN);
   board.board[2][4] = &w6;
   White w7(PAWN);
   board.board[3][1] = &w7;
   White w8(PAWN);
   board.board[3][5] = &w8;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);  // many possible moves
   assertUnit(moves.find(Move("e4g5p")) != moves.end()); // g5
   assertUnit(moves.find(Move("e4c5p")) != moves.end()); // c5
   assertUnit(moves.find(Move("e4g3p")) != moves.end()); // g3
   assertUnit(moves.find(Move("e4c3p")) != moves.end()); // c3
   assertUnit(moves.find(Move("e4f6p")) != moves.end()); // f6
   assertUnit(moves.find(Move("e4f2p")) != moves.end()); // f2
   assertUnit(moves.find(Move("e4d6p")) != moves.end()); // d6
   assertUnit(moves.find(Move("e4d2p")) != moves.end()); // d2


   // TEARDOWN
   board.board[4][3] = nullptr; // black knight
   board.board[6][2] = nullptr; // white pawn 1
   board.board[6][4] = nullptr; // white pawn 2
   board.board[5][1] = nullptr; // white pawn 3
   board.board[5][5] = nullptr; // white pawn 4
   board.board[2][2] = nullptr; // white pawn 5
   board.board[2][4] = nullptr; // white pawn 6
   board.board[3][1] = nullptr; // white pawn 7
   board.board[3][5] = nullptr; // white pawn 8
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       .   .         7
 * 6     .       .       6
 * 5        (n)          5
 * 4     .       .       4
 * 3       .   .         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_free()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(3, 4);
   board.board[3][4] = &knight;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);  // many possible moves

   // TEARDOWN
   board.board[3][4] = nullptr; // white knight
}



/*************************************
 * GET TYPE : knight
 * Input:
 * Output: KNIGHT
 **************************************/
void TestKnight::getType()
{
   // SETUP
   Knight knight(7, 7, false);
   PieceType pt;
   
   // EXERCISE
   pt = knight.getType();
   
   // VERIFY
   assertEquals(KNIGHT, pt);
}  // TEARDOWN
