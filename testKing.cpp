/***********************************************************************
 * Source File:
 *    TEST KING
 * Author:
 *    Chris Mijangos and Seth Chen
 * Summary:
 *    The unit tests for the King
 ************************************************************************/

#include "testKing.h"
#include "pieceRook.h"
#include "pieceKing.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6       p p p         6
  * 5       p(k)p         5
  * 4       p p p         4
  * 3                     3
  * 2                     2
  * 1                     1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestKing::getMoves_blocked()
{
    // SETUP
    BoardEmpty board;
    King king(3, 4, true /*white*/); // King is on D5
    king.position.set(4, 3);
    board.board[3][4] = &king;

    // Surround the king with pawns (all positions around D5)
    White w1(PAWN);
    board.board[5][2] = &w1; // C6
    White w2(PAWN);
    board.board[5][3] = &w2; // D6
    White w3(PAWN);
    board.board[5][4] = &w3; // E6
    White w4(PAWN);
    board.board[4][2] = &w4; // C5
    White w5(PAWN);
    board.board[4][4] = &w5; // E5
    White w6(PAWN);
    board.board[3][2] = &w6; // C4
    White w7(PAWN);
    board.board[3][3] = &w7; // D4
    White w8(PAWN);
    board.board[3][4] = &w8; // E4

    set <Move> moves;

    // EXERCISE
    king.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.empty());

    // TEARDOWN
    board.board[3][4] = nullptr; // king
    board.board[5][2] = nullptr; // white pawn 1
    board.board[5][3] = nullptr; // white pawn 2
    board.board[5][4] = nullptr; // white pawn 3
    board.board[4][2] = nullptr; // white pawn 4
    board.board[4][4] = nullptr; // white pawn 5
    board.board[3][2] = nullptr; // white pawn 6
    board.board[3][3] = nullptr; // white pawn 7
    board.board[3][4] = nullptr; // white pawn 8
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       P P P         6
 * 5       P(k)P         5
 * 4       P P P         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_capture()
{
    // SETUP
    BoardEmpty board;
    King king(3, 4, true /*white*/); // King is on D5 
    king.position.set(3, 4);
    board.board[3][4] = &king;

    // Surround the king with pawns (all positions around D5)
    Black w1(PAWN);
    board.board[5][2] = &w1; // C6
    Black w2(PAWN);
    board.board[5][3] = &w2; // D6
    Black w3(PAWN);
    board.board[5][4] = &w3; // E6
    Black w4(PAWN);
    board.board[4][2] = &w4; // C5
    Black w5(PAWN);
    board.board[4][4] = &w5; // E5
    Black w6(PAWN);
    board.board[3][2] = &w6; // C4
    Black w7(PAWN);
    board.board[3][3] = &w7; // D4
    Black w8(PAWN);
    board.board[3][4] = &w8; // E4

    set <Move> moves;

    // EXERCISE
    king.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 8);
    assertUnit(moves.find(Move("d5c6p")) != moves.end());
    assertUnit(moves.find(Move("d5d6p")) != moves.end());
    assertUnit(moves.find(Move("d5e6p")) != moves.end());
    assertUnit(moves.find(Move("d5c5p")) != moves.end());
    assertUnit(moves.find(Move("d5e5p")) != moves.end());
    assertUnit(moves.find(Move("d5c4p")) != moves.end());
    assertUnit(moves.find(Move("d5d4p")) != moves.end());
    assertUnit(moves.find(Move("d5e4p")) != moves.end());

    // TEARDOWN
    board.board[3][4] = nullptr; // king
    board.board[5][2] = nullptr; // white pawn 1
    board.board[5][3] = nullptr; // white pawn 2
    board.board[5][4] = nullptr; // white pawn 3
    board.board[4][2] = nullptr; // white pawn 4
    board.board[4][4] = nullptr; // white pawn 5
    board.board[3][2] = nullptr; // white pawn 6
    board.board[3][3] = nullptr; // white pawn 7
    board.board[3][4] = nullptr; // white pawn 8
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       . . .         6
 * 5       .(k).         5
 * 4       . . .         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_free()
{
    // SETUP
    BoardEmpty board;
    King king(3, 4, true /*white*/); // King is on D5 
    king.position.set(3, 4);
    board.board[3][4] = &king;

    // Surround the king with pawns (all positions around D5)
    Black w1(PAWN);
    board.board[5][2] = &w1; // C6
    Black w2(PAWN);
    board.board[5][3] = &w2; // D6
    Black w3(PAWN);
    board.board[5][4] = &w3; // E6
    Black w4(PAWN);
    board.board[4][2] = &w4; // C5
    Black w5(PAWN);
    board.board[4][4] = &w5; // E5
    Black w6(PAWN);
    board.board[3][2] = &w6; // C4
    Black w7(PAWN);
    board.board[3][3] = &w7; // D4
    Black w8(PAWN);
    board.board[3][4] = &w8; // E4

    set <Move> moves;

    // EXERCISE
    king.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 8);
    assertUnit(moves.find(Move("d5c6")) != moves.end());
    assertUnit(moves.find(Move("d5d6")) != moves.end());
    assertUnit(moves.find(Move("d5e6")) != moves.end());
    assertUnit(moves.find(Move("d5c5")) != moves.end());
    assertUnit(moves.find(Move("d5e5")) != moves.end());
    assertUnit(moves.find(Move("d5c4")) != moves.end());
    assertUnit(moves.find(Move("d5d4")) != moves.end());
    assertUnit(moves.find(Move("d5e4")) != moves.end());

    // TEARDOWN
    board.board[3][4] = nullptr; // king
    board.board[5][2] = nullptr; // white pawn 1
    board.board[5][3] = nullptr; // white pawn 2
    board.board[5][4] = nullptr; // white pawn 3
    board.board[4][2] = nullptr; // white pawn 4
    board.board[4][4] = nullptr; // white pawn 5
    board.board[3][2] = nullptr; // white pawn 6
    board.board[3][3] = nullptr; // white pawn 7
    board.board[3][4] = nullptr; // white pawn 8
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2   . .               2
 * 1  (k).               1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_end()
{
    // SETUP
    BoardEmpty board;
    King king(0, 0, true /*white*/); // King is on A1 
    king.position.set(0, 0);
    board.board[0][0] = &king;
    set <Move> moves;

    // EXERCISE
    king.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 3);
    assertUnit(moves.find(Move("a1b1")) != moves.end());
    assertUnit(moves.find(Move("a1a2")) != moves.end());
    assertUnit(moves.find(Move("a1b2")) != moves.end());

    // TEARDOWN
    board.board[0][0] = nullptr; // king

}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r   . .(k). . r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastle()
{
    // SETUP
    BoardEmpty board;
    King king(4, 0, true); // King on e1
    board.board[4][0] = &king;
    Rook* rookKing = new Rook(7, 0, true);
    board.board[7][0] = rookKing;
    Rook* rookQueen = new Rook(0, 0, true);
    board.board[0][0] = rookQueen;

    // Manually place pawns around the king's potential move positions
    White w1(PAWN);
    board.board[3][1] = &w1; // Pawn on d2

    White w2(PAWN);
    board.board[4][1] = &w2; // Pawn on e2

    White w3(PAWN);
    board.board[5][1] = &w3; // Pawn on f2
    set<Move> moves;

    // EXERCISE
    king.getMoves(moves, board);


    // VERIFY:
    // King-side and Queen-side castling
    assertUnit(moves.size() == 6);  // 2 castling moves

    // Verify regular moves (king can move one square in any direction)
    assertUnit(moves.find(Move("e1d1")) != moves.end());  // Move to d1
    assertUnit(moves.find(Move("e1f1")) != moves.end());  // Move to f1

    // Verify castling moves
    assertUnit(moves.find(Move("e1g1")) != moves.end());  // King-side castle
    assertUnit(moves.find(Move("e1c1")) != moves.end());  // Queen-side castle


    // TEARDOWN
    delete rookKing;
    delete rookQueen;

}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R   . .(K). . R   8
 * 7         P P P       7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blackCastle()
{
    // SETUP
    BoardEmpty board;
    King king(4, 7, false); // Black King on e8 (e8 -> col=4, row=7)
    board.board[4][7] = &king;
    Rook* rookKing = new Rook(7, 7, false); // Rook on h8
    board.board[7][7] = rookKing;
    Rook* rookQueen = new Rook(0, 7, false); // Rook on a8
    board.board[0][7] = rookQueen;

    // Place pawns of the **same color** (black) around the king's potential move positions
    Black b1(PAWN);
    board.board[3][6] = &b1; // Pawn on d7

    Black b2(PAWN);
    board.board[4][6] = &b2; // Pawn on e7

    Black b3(PAWN);
    board.board[5][6] = &b3; // Pawn on f7

    set<Move> moves;

    // EXERCISE
    king.getMoves(moves, board);

    // PRINT MOVES
    //std::cout << "Moves for Black King:" << std::endl;
    //for (const auto& move : moves)
    //{
    //    std::cout << const_cast<Move&>(move).getText() << std::endl;
    //}

    // VERIFY:
    assertUnit(moves.size() == 6);

    // Verify regular moves (king can move one square left or right)
    assertUnit(moves.find(Move("e8d8")) != moves.end());  // Move to d8
    assertUnit(moves.find(Move("e8f8")) != moves.end());  // Move to f8

    // Verify castling moves
    assertUnit(moves.find(Move("e8g8")) != moves.end());  // King-side castle (e8 to g8)
    assertUnit(moves.find(Move("e8c8")) != moves.end());  // Queen-side castle (e8 to c8)



    // TEARDOWN
    delete rookKing;
    delete rookQueen;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleKingMoved()
{
    // SETUP
    BoardEmpty board;
    King king(4, 0, true); // White King on e1 
    king.setLastMove(2);
    board.board[4][0] = &king;

    Rook* rookKing = new Rook(7, 0, true); // Rook on h1
    board.board[7][0] = rookKing;
    Rook* rookQueen = new Rook(0, 0, true); // Rook on a1
    board.board[0][0] = rookQueen;

    // Place pawns of the **same color** (white) around the king's potential move positions
    White w1(PAWN);
    board.board[3][1] = &w1; // Pawn on d2

    White w2(PAWN);
    board.board[4][1] = &w2; // Pawn on e2

    White w3(PAWN);
    board.board[5][1] = &w3; // Pawn on f2

    set<Move> moves;

    // EXERCISE
    king.getMoves(moves, board);

    // VERIFY:
    assertUnit(moves.size() == 2);

    // Verify regular moves (king can move one square left or right)
    assertUnit(moves.find(Move("e1d1")) != moves.end());  // Move to d1
    assertUnit(moves.find(Move("e1f1")) != moves.end());  // Move to f1

    // Verify that castling moves are no longer available since the king has moved
    assertUnit(moves.find(Move("e1g1")) == moves.end());  // No king-side castle
    assertUnit(moves.find(Move("e1c1")) == moves.end());  // No queen-side castle



    // TEARDOWN
    delete rookKing;
    delete rookQueen;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R   . .(K). . R   8
 * 7         P P P       7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blackCastleKingMoved()
{
    // SETUP
    BoardEmpty board;
    King king(4, 7, false); // Black King on e8 (e8 -> col=4, row=7)
    king.setLastMove(2); // Mark the king as having moved
    board.board[4][7] = &king;

    Rook* rookKing = new Rook(7, 7, false); // Rook on h8
    board.board[7][7] = rookKing;
    Rook* rookQueen = new Rook(0, 7, false); // Rook on a8
    board.board[0][7] = rookQueen;

    // Place pawns of the **same color** (black) around the king's potential move positions
    Black b1(PAWN);
    board.board[3][6] = &b1; // Pawn on d7

    Black b2(PAWN);
    board.board[4][6] = &b2; // Pawn on e7

    Black b3(PAWN);
    board.board[5][6] = &b3; // Pawn on f7

    set<Move> moves;

    // EXERCISE
    king.getMoves(moves, board);

    // VERIFY:
    assertUnit(moves.size() == 2);

    // Verify regular moves (king can move one square left or right)
    assertUnit(moves.find(Move("e8d8")) != moves.end());  // Move to d8
    assertUnit(moves.find(Move("e8f8")) != moves.end());  // Move to f8


    // Verify that castling moves are no longer available since the king has moved
    assertUnit(moves.find(Move("e8g8")) == moves.end());  // No king-side castle
    assertUnit(moves.find(Move("e8c8")) == moves.end());  // No queen-side castle

    // Ensure total number of moves (only the two regular moves are possible, no castling)
    assertUnit(moves.size() == 2);

    // TEARDOWN
    delete rookKing;
    delete rookQueen;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleRookMoved()
{

    // SETUP
    BoardEmpty board;
    King king(4, 0, true); // White King on e1
    board.board[4][0] = &king;

    Rook* rookKing = new Rook(7, 0, true); // Rook on h1 (King-side)
    Rook* rookQueen = new Rook(0, 0, true); // Rook on a1 (Queen-side)

    // Mark the King-side rook as having moved
    rookKing->setLastMove(1); // Simulate that the rook has moved
    board.board[7][0] = rookKing;
    board.board[0][0] = rookQueen;

    // Place black pawns on d2, e2, f2
    White p1(PAWN);
    board.board[3][1] = &p1; // Pawn on d2

    White p2(PAWN);
    board.board[4][1] = &p2; // Pawn on e2

    White p3(PAWN);
    board.board[5][1] = &p3; // Pawn on f2

    set<Move> moves;

    // EXERCISE
    king.getMoves(moves, board);

    // VERIFY:
    assertUnit(moves.size() == 4);

    // Verify regular moves (king can move one square left or right)
    assertUnit(moves.find(Move("e1d1")) != moves.end());  // Move to d1
    assertUnit(moves.find(Move("e1f1")) != moves.end());  // Move to f1

    // Verify that castling moves are no longer available on the King-side since the rook has moved
    assertUnit(moves.find(Move("e1g1")) == moves.end());  // No king-side castle

    // Verify that castling moves are still available on the Queen-side since that rook has not moved
    assertUnit(moves.find(Move("e1c1")) != moves.end());  // Queen-side castle still available

    // TEARDOWN
    delete rookKing;
    delete rookQueen;
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
    // SETUP
    King king(4, 0, true); // King on e1 (White King)
    PieceType pt;

    // EXERCISE
    pt = king.getType();

    // VERIFY
    assertEquals(KING, pt);
}



