/***********************************************************************
 * Source File:
 *    TEST PAWN
 * Author:
 *    Chris Mijangos and Seth Chen
 * Summary:
 *    The unit tests for the pawn
 ************************************************************************/

#include "testPawn.h"
#include "piecePawn.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>  
#include "pieceRook.h"



 /*************************************
  * GET MOVES TEST Simple
  * White pawn in the middle of the board: b4
  *
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5     .               5
  * 4    (p)              4
  * 3                     3
  * 2                     2
  * 1                     1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestPawn::getMoves_simpleWhite()
{
    // SETUP
    BoardEmpty board;
    Pawn pawn(1, 3, true); // White pawn at b4 
    board.board[1][3] = &pawn;
    set<Move> moves;

    // EXERCISE
    pawn.getMoves(moves, board);

    // PRINT MOVES
    // std::cout << "Moves for Pawn:" << std::endl;
    //for (const auto& move : moves)
    //{
    //    std::cout << const_cast<Move&>(move).getText() << std::endl;
    //}

    // VERIFY
    assertUnit(moves.size() == 1);
    // The only possible move should be to b5
    assertUnit(moves.find(Move("b4b5")) != moves.end());

    // TEARDOWN
    board.board[1][3] = nullptr;

}

/*************************************
 * GET MOVES TEST Simple
 * Black pawn in the middle of the board: b4
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4    (P)              4
 * 3     .               3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_simpleBlack()
{
    // SETUP
    BoardEmpty board;
    Pawn pawn(1, 3, false); // Black pawn at b4 (column 1, row 3)
    board.board[1][3] = &pawn;
    set<Move> moves;

    // EXERCISE
    pawn.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 1);

    // VERIFY
    assertUnit(moves.size() == 1);
    // The only possible move should be to b5
    assertUnit(moves.find(Move("b4b3")) != moves.end());

    // TEARDOWN
    board.board[1][3] = nullptr;
}


/*************************************
 * GET MOVES TEST InitialAdvance
 * White pawn initial advance
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4     .               4
 * 3     .               3
 * 2    (p)              2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceWhite()
{
    // SETUP
    BoardEmpty board;
    Pawn pawn(1, 1, true); // White pawn at b2
    board.board[1][1] = &pawn;
    set<Move> moves;

    // EXERCISE
    pawn.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 2);
    // Possible moves
    assertUnit(moves.find(Move("b2b3")) != moves.end());
    assertUnit(moves.find(Move("b2b4")) != moves.end());

    // TEARDOWN
    board.board[1][1] = nullptr;
}

/*************************************
 * GET MOVES TEST InitialAdvance
 * Black pawn initial advance
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7      (P)            7
 * 6       .             6
 * 5       .             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceBlack()
{
    // SETUP
    BoardEmpty board;
    Pawn pawn(2, 6, false); // Black pawn at c7
    board.board[2][6] = &pawn;
    set<Move> moves;

    // EXERCISE
    pawn.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 2);
    // Possible moves
    assertUnit(moves.find(Move("c7c6")) != moves.end());
    assertUnit(moves.find(Move("c7c5")) != moves.end());

    // TEARDOWN
    board.board[2][6] = nullptr;

}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move pawn to b6 and capture
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7   P P P             7
 * 6    (p)              6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureWhite()
{
    // SETUP
    BoardEmpty board;
    Pawn whitePawn(1, 5, true); // White pawn at b6
    board.board[1][5] = &whitePawn;

    Pawn blackPawn1(0, 6, false); // Black pawn at a7
    board.board[0][6] = &blackPawn1;

    Pawn blackPawn2(2, 6, false); // Black pawn at c7
    board.board[2][6] = &blackPawn2;

    Pawn blackPawn3(1, 6, false); // Black pawn at b7
    board.board[1][6] = &blackPawn3;

    set<Move> moves;

    // EXERCISE
    whitePawn.getMoves(moves, board);

    // VERIFY
    assertUnit(moves.size() == 2); // White pawn should have 2 capture moves
    // Possible moves
    assertUnit(moves.find(Move("b6a7p")) != moves.end());
    assertUnit(moves.find(Move("b6c7p")) != moves.end());


    // TEARDOWN
    board.board[1][5] = nullptr;
    board.board[0][6] = nullptr;
    board.board[1][6] = nullptr;
    board.board[2][6] = nullptr;
}


/*************************************
 * GET MOVES TEST Capture
 * 
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6    (P)              6
 * 5   p p p             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureBlack()
{
    // SETUP
    BoardEmpty board;
    Pawn blackPawn(1, 5, false); // Black pawn at b6
    board.board[1][5] = &blackPawn;

    Pawn whitePawn1(0, 4, true); // White pawn at a5
    board.board[0][4] = &whitePawn1;

    Pawn whitePawn2(1, 4, true); // White pawn at b5
    board.board[1][4] = &whitePawn2;

    Pawn whitePawn3(2, 4, true); // White pawn at c5
    board.board[2][4] = &whitePawn3;

    set<Move> moves;

    // EXERCISE
    blackPawn.getMoves(moves, board);

    // VERIFY
    // Black pawn should have 2 capture moves (a5 and c5)
    assertUnit(moves.size() == 2);

    // Possible moves
    assertUnit(moves.find(Move("b6a5p")) != moves.end()); // Capture left
    assertUnit(moves.find(Move("b6c5p")) != moves.end()); // Capture right

    // TEARDOWN
    board.board[1][5] = nullptr;
    board.board[0][4] = nullptr;
    board.board[1][4] = nullptr;
    board.board[2][4] = nullptr;
}

/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant b5a6E
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6   . P .             6
 * 5   P(p)P             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantWhite()
{
    // SETUP
    BoardEmpty board;
    board.moveNumber = 1; // Set the current move number

    Pawn whitePawn(1, 4, true); // White pawn at b5
    board.board[1][4] = &whitePawn;

    Pawn blackPawn1(0, 4, false); // Black pawn at a5
    board.board[0][4] = &blackPawn1;

    Pawn blackPawn2(2, 4, false); // Black pawn at c5
    board.board[2][4] = &blackPawn2;

    Pawn blackPawn3(1, 5, false); // Black pawn at b6
    blackPawn3.setLastMove(1);
    board.board[1][5] = &blackPawn3;

    set<Move> moves;

    // EXERCISE
    whitePawn.getMoves(moves, board);

    // VERIFY
    // White pawn should have 2 moves: en passant to a6 and en passant to c6
    assertUnit(moves.size() == 2);

    // Possible moves
    assertUnit(moves.find(Move("b5a6E")) != moves.end()); // En passant capture left (a6) IT goes a P 
                                                          // so I do not know if that is going to be a problem in the future
    assertUnit(moves.find(Move("b5c6E")) != moves.end()); // En passant capture right (c6)

    // TEARDOWN
    board.board[1][4] = nullptr;
    board.board[0][4] = nullptr;
    board.board[2][4] = nullptr;
    board.board[1][5] = nullptr;
}


/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant f4g3E
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4           p(P)p     4
 * 3           . p .     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantBlack()
{
    // SETUP
    BoardEmpty board;
    board.moveNumber = 1; // Set the current move number

    Pawn blackPawn(5, 3, false); // Black pawn at f4
    board.board[5][3] = &blackPawn;

    Pawn whitePawn1(6, 3, true); // White pawn at g4
    board.board[6][3] = &whitePawn1;

    Pawn whitePawn2(4, 3, true); // White pawn at e4
    board.board[4][3] = &whitePawn2;

    Pawn whitePawn3(5, 2, true); // White pawn at f3
    board.board[5][2] = &whitePawn3;
    whitePawn3.setLastMove(1);

    set<Move> moves;

    // EXERCISE
    blackPawn.getMoves(moves, board);

    // VERIFY
    // Black pawn should have 2 moves: en passant to e3 and en passant to g3
    assertUnit(moves.size() == 2);

    // Possible moves
    assertUnit(moves.find(Move("f4e3p")) != moves.end()); // En passant capture left (e3)
    assertUnit(moves.find(Move("f4g3p")) != moves.end()); // En passant capture right (g3)

    // TEARDOWN
    board.board[5][3] = nullptr;
    board.board[6][3] = nullptr;
    board.board[4][3] = nullptr;
    board.board[5][2] = nullptr;
}

/*************************************
 * GET MOVES TEST Promotion
 * Promotion: b6a7rQ
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   P . P             8
 * 7    (p)              7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionWhite()
{
    // SETUP
    BoardEmpty board;
    board.moveNumber = 1; // Set the current move number

    Pawn whitePawn(1, 6, true); // White pawn at b7
    board.board[1][6] = &whitePawn;

    Black blackPawn1(PAWN);
    board.board[0][7] = &blackPawn1; // Black pawn at a8

    Black blackPawn2(PAWN);
    board.board[2][7] = &blackPawn2; // Black pawn at c8

    set<Move> moves;

    // EXERCISE
    whitePawn.getMoves(moves, board);

    // PRINT MOVES (for debugging)
    //std::cout << "Moves for White Pawn (Promotion Test):" << std::endl;
    //for (const auto& move : moves)
    //{
    //    std::cout << const_cast<Move&>(move).getText() << std::endl;
    //}

    // VERIFY
    // White pawn should have 3 moves unless it is 12 if we are counting promotion
    assertUnit(moves.size() == 3);

    // Check for promotion to Queen
    assertUnit(moves.find(Move("b7a8p")) != moves.end());  
    assertUnit(moves.find(Move("b7b8C")) != moves.end());  
    assertUnit(moves.find(Move("b7c8p")) != moves.end());  

    // TEARDOWN
    board.board[1][6] = nullptr; // White pawn
    board.board[0][7] = nullptr; // Black pawn 1
    board.board[2][7] = nullptr; // Black pawn 2
}


/*************************************
 * GET MOVES TEST Promotion
 * Promotion: e2d1rQ
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2          (P)        2
 * 1         r   r       1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionBlack()
{
    // SETUP
    BoardEmpty board;
    board.moveNumber = 1; // Set the current move number

    // Black pawn at e2
    Pawn blackPawn(4, 1, false); // Black pawn at e2
    board.board[4][1] = &blackPawn;

    // White rooks at f1 and d1
    Rook whiteRook1(5, 0, true); // White rook at f1
    board.board[5][0] = &whiteRook1;

    Rook whiteRook2(3, 0, true); // White rook at d1
    board.board[3][0] = &whiteRook2;

    set<Move> moves;

    // EXERCISE
    blackPawn.getMoves(moves, board);

    // PRINT MOVES (for debugging)
    //std::cout << "Moves for Black Pawn (Rook Capture Test):" << std::endl;
    //for (const auto& move : moves)
    //{
    //    std::cout << const_cast<Move&>(move).getText() << std::endl;
    //}

    // VERIFY
    // Black pawn should have 3 moves: capture f1, move to e1, and capture d1
    assertUnit(moves.size() == 3);

    // Possible moves
    assertUnit(moves.find(Move("e2f1r")) != moves.end()); // Capture rook on f1
    assertUnit(moves.find(Move("e2e1C")) != moves.end()); // Move to e1
    assertUnit(moves.find(Move("e2d1r")) != moves.end()); // Capture rook on d1

    // TEARDOWN
    board.board[4][1] = nullptr;
    board.board[5][0] = nullptr;
    board.board[3][0] = nullptr;
}


/*************************************
 * GET TYPE : pawn
 * Input:
 * Output: PAWN
 **************************************/
void TestPawn::getType()
{
    // SETUP
    Pawn pawn(4, 1, true); // White Pawn at e2
    PieceType pt;

    // EXERCISE
    pt = pawn.getType();

    // VERIFY
    assertEquals(PAWN, pt);
}

