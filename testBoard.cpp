/***********************************************************************
 * Source File:
 *    TEST BOARD
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for board
 ************************************************************************/


#include "testBoard.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "pieceKing.h"
#include "pieceQueen.h"
#include "piecePawn.h"
#include "pieceRook.h"
#include "pieceBishop.h"
#include "board.h"
#include <cassert>




/***********************************************
 * CREATE DUMMY BOARD : Constructor for DummyBoard
 * Setup:
 * VERIFY: all squares have the null pointer
 ***********************************************/
void TestBoard::construct_dummyBoard()
{  // SETUP
  // EXERCISE
  BoardDummy board;
  // VERIFY
  assertUnit(0 == board.numMoves);
  assertUnit(nullptr == board.board[0][0]);
  assertUnit(nullptr == board.board[1][0]);
  assertUnit(nullptr == board.board[2][0]);
  assertUnit(nullptr == board.board[3][0]);
  assertUnit(nullptr == board.board[4][0]);
  assertUnit(nullptr == board.board[5][0]);
  assertUnit(nullptr == board.board[6][0]);
  assertUnit(nullptr == board.board[7][0]);
  assertUnit(nullptr == board.board[0][1]);
  assertUnit(nullptr == board.board[1][1]);
  assertUnit(nullptr == board.board[2][1]);
  assertUnit(nullptr == board.board[3][1]);
  assertUnit(nullptr == board.board[4][1]);
  assertUnit(nullptr == board.board[5][1]);
  assertUnit(nullptr == board.board[6][1]);
  assertUnit(nullptr == board.board[7][1]);
  assertUnit(nullptr == board.board[0][2]);
  assertUnit(nullptr == board.board[1][2]);
  assertUnit(nullptr == board.board[2][2]);
  assertUnit(nullptr == board.board[3][2]);
  assertUnit(nullptr == board.board[4][2]);
  assertUnit(nullptr == board.board[5][2]);
  assertUnit(nullptr == board.board[6][2]);
  assertUnit(nullptr == board.board[7][2]);
  assertUnit(nullptr == board.board[0][3]);
  assertUnit(nullptr == board.board[1][3]);
  assertUnit(nullptr == board.board[2][3]);
  assertUnit(nullptr == board.board[3][3]);
  assertUnit(nullptr == board.board[4][3]);
  assertUnit(nullptr == board.board[5][3]);
  assertUnit(nullptr == board.board[6][3]);
  assertUnit(nullptr == board.board[7][3]);
  assertUnit(nullptr == board.board[0][4]);
  assertUnit(nullptr == board.board[1][4]);
  assertUnit(nullptr == board.board[2][4]);
  assertUnit(nullptr == board.board[3][4]);
  assertUnit(nullptr == board.board[4][4]);
  assertUnit(nullptr == board.board[5][4]);
  assertUnit(nullptr == board.board[6][4]);
  assertUnit(nullptr == board.board[7][4]);
  assertUnit(nullptr == board.board[0][5]);
  assertUnit(nullptr == board.board[1][5]);
  assertUnit(nullptr == board.board[2][5]);
  assertUnit(nullptr == board.board[3][5]);
  assertUnit(nullptr == board.board[4][5]);
  assertUnit(nullptr == board.board[5][5]);
  assertUnit(nullptr == board.board[6][5]);
  assertUnit(nullptr == board.board[7][5]);
  assertUnit(nullptr == board.board[0][6]);
  assertUnit(nullptr == board.board[1][6]);
  assertUnit(nullptr == board.board[2][6]);
  assertUnit(nullptr == board.board[3][6]);
  assertUnit(nullptr == board.board[4][6]);
  assertUnit(nullptr == board.board[5][6]);
  assertUnit(nullptr == board.board[6][6]);
  assertUnit(nullptr == board.board[7][6]);
  assertUnit(nullptr == board.board[0][7]);
  assertUnit(nullptr == board.board[1][7]);
  assertUnit(nullptr == board.board[2][7]);
  assertUnit(nullptr == board.board[3][7]);
  assertUnit(nullptr == board.board[4][7]);
  assertUnit(nullptr == board.board[5][7]);
  assertUnit(nullptr == board.board[6][7]);
  assertUnit(nullptr == board.board[7][7]);
}  // TEARDOWN

/***********************************************
 * CREATE EMPTY BOARD : Constructor for BoardEmpty
 * Setup:
 * VERIFY: all squares have the null pointer
 ***********************************************/
void TestBoard::construct_emptyBoard()
{  // SETUP
  // EXERCISE
  BoardEmpty board;
  // VERIFY
  assertUnit(0 == board.numMoves);
  assertUnit(nullptr == board.board[0][0]);
  assertUnit(nullptr == board.board[1][0]);
  assertUnit(nullptr == board.board[2][0]);
  assertUnit(nullptr == board.board[3][0]);
  assertUnit(nullptr == board.board[4][0]);
  assertUnit(nullptr == board.board[5][0]);
  assertUnit(nullptr == board.board[6][0]);
  assertUnit(nullptr == board.board[7][0]);
  assertUnit(nullptr == board.board[0][1]);
  assertUnit(nullptr == board.board[1][1]);
  assertUnit(nullptr == board.board[2][1]);
  assertUnit(nullptr == board.board[3][1]);
  assertUnit(nullptr == board.board[4][1]);
  assertUnit(nullptr == board.board[5][1]);
  assertUnit(nullptr == board.board[6][1]);
  assertUnit(nullptr == board.board[7][1]);
  assertUnit(nullptr == board.board[0][2]);
  assertUnit(nullptr == board.board[1][2]);
  assertUnit(nullptr == board.board[2][2]);
  assertUnit(nullptr == board.board[3][2]);
  assertUnit(nullptr == board.board[4][2]);
  assertUnit(nullptr == board.board[5][2]);
  assertUnit(nullptr == board.board[6][2]);
  assertUnit(nullptr == board.board[7][2]);
  assertUnit(nullptr == board.board[0][3]);
  assertUnit(nullptr == board.board[1][3]);
  assertUnit(nullptr == board.board[2][3]);
  assertUnit(nullptr == board.board[3][3]);
  assertUnit(nullptr == board.board[4][3]);
  assertUnit(nullptr == board.board[5][3]);
  assertUnit(nullptr == board.board[6][3]);
  assertUnit(nullptr == board.board[7][3]);
  assertUnit(nullptr == board.board[0][4]);
  assertUnit(nullptr == board.board[1][4]);
  assertUnit(nullptr == board.board[2][4]);
  assertUnit(nullptr == board.board[3][4]);
  assertUnit(nullptr == board.board[4][4]);
  assertUnit(nullptr == board.board[5][4]);
  assertUnit(nullptr == board.board[6][4]);
  assertUnit(nullptr == board.board[7][4]);
  assertUnit(nullptr == board.board[0][5]);
  assertUnit(nullptr == board.board[1][5]);
  assertUnit(nullptr == board.board[2][5]);
  assertUnit(nullptr == board.board[3][5]);
  assertUnit(nullptr == board.board[4][5]);
  assertUnit(nullptr == board.board[5][5]);
  assertUnit(nullptr == board.board[6][5]);
  assertUnit(nullptr == board.board[7][5]);
  assertUnit(nullptr == board.board[0][6]);
  assertUnit(nullptr == board.board[1][6]);
  assertUnit(nullptr == board.board[2][6]);
  assertUnit(nullptr == board.board[3][6]);
  assertUnit(nullptr == board.board[4][6]);
  assertUnit(nullptr == board.board[5][6]);
  assertUnit(nullptr == board.board[6][6]);
  assertUnit(nullptr == board.board[7][6]);
  assertUnit(nullptr == board.board[0][7]);
  assertUnit(nullptr == board.board[1][7]);
  assertUnit(nullptr == board.board[2][7]);
  assertUnit(nullptr == board.board[3][7]);
  assertUnit(nullptr == board.board[4][7]);
  assertUnit(nullptr == board.board[5][7]);
  assertUnit(nullptr == board.board[6][7]);
  assertUnit(nullptr == board.board[7][7]);
}  // TEARDOWN


/***********************************************
* GET CURRENT MOVE : initially the board is empty
* Setup:  board.numMoves=0
* VERIFY: moveNumber=0
***********************************************/
void TestBoard::getCurrentMove_initial()
{  // SETUP
  Board board;
  createDummyBoard(board);
  board.numMoves = 0;
  int moveNumber = -1;
  // EXERCISE
  moveNumber = board.getCurrentMove();
  // VERIFY
  assertUnit(0 == board.numMoves);
  assertUnit(moveNumber == 0);
}  // TEARDOWN

/***********************************************
* GET CURRENT MOVE : second move
* Setup:  board.numMoves=1
* VERIFY: moveNumber=1
***********************************************/
void TestBoard::getCurrentMove_second()
{  // SETUP
  Board board;
  createDummyBoard(board);
  board.numMoves = 1;
  int moveNumber = -1;
  // EXERCISE
  moveNumber = board.getCurrentMove();
  // VERIFY
  assertUnit(1 == board.numMoves);
  assertUnit(moveNumber == 1);
}  // TEARDOWN

/***********************************************
* GET CURRENT MOVE : white turn in the middle of the game
* Setup:  board.numMoves=4
* VERIFY: moveNumber=4
***********************************************/
void TestBoard::getCurrentMove_middleWhite()
{  // SETUP
  Board board;
  createDummyBoard(board);
  board.numMoves = 4;
  int moveNumber = -1;
  // EXERCISE
  moveNumber = board.getCurrentMove();
  // VERIFY
  assertUnit(4 == board.numMoves);
  assertUnit(moveNumber == 4);
}  // TEARDOWN

/***********************************************
* GET CURRENT MOVE : black turn in the middle of the game
* Setup:  board.numMoves=5
* VERIFY: moveNumber=5
***********************************************/
void TestBoard::getCurrentMove_middleBlack()
{  // SETUP
  Board board;
  createDummyBoard(board);
  board.numMoves = 5;
  int moveNumber = -1;
  // EXERCISE
  moveNumber = board.getCurrentMove();
  // VERIFY
  assertUnit(5 == board.numMoves);
  assertUnit(moveNumber == 5);
}  // TEARDOWN

/***********************************************
* WHITE TURN : initially the board is empty
* Setup:  board.numMoves=0
* VERIFY: isWhiteTurn=true
***********************************************/
void TestBoard::whiteTurn_initial()
{  // SETUP
  Board board;
  board.numMoves = 0;
  createDummyBoard(board);
  bool isWhiteTurn;
  // EXERCISE
  isWhiteTurn = board.whiteTurn();
  // VERIFY
  assertUnit(0 == board.numMoves);
  assertUnit(isWhiteTurn == true);
}  // TEARDOWN

/***********************************************
* WHITE TURN : second move
* Setup:  board.numMoves=1
* VERIFY: isWhiteTurn=false
***********************************************/
void TestBoard::whiteTurn_second()
{  // SETUP
  Board board;
  createDummyBoard(board);
  board.numMoves = 1;
  bool isWhiteTurn;
  // EXERCISE
  isWhiteTurn = board.whiteTurn();
  // VERIFY
  assertUnit(1 == board.numMoves);
  assertUnit(isWhiteTurn == false);
}  // TEARDOWN

/***********************************************
* WHITE TURN : white turn in the middle of the game
* Setup:  board.numMoves=4
* VERIFY: isWhiteTurn=true
***********************************************/
void TestBoard::whiteTurn_middleWhite()
{  // SETUP
  Board board;
  createDummyBoard(board);
  board.numMoves = 4;
  bool isWhiteTurn;
  // EXERCISE
  isWhiteTurn = board.whiteTurn();
  // VERIFY
  assertUnit(4 == board.numMoves);
  assertUnit(isWhiteTurn == true);
}  // TEARDOWN

/***********************************************
* WHITE TURN : black turn in the middle of the game
* Setup:  board.numMoves=5
* VERIFY: isWhiteTurn=false
***********************************************/
void TestBoard::whiteTurn_middleBlack()
{  // SETUP
  Board board;
  createDummyBoard(board);
  board.numMoves = 5;
  bool isWhiteTurn;
  // EXERCISE
  isWhiteTurn = board.whiteTurn();
  // VERIFY
  assertUnit(5 == board.numMoves);
  assertUnit(isWhiteTurn == false);
}  // TEARDOWN

class Position00 : public Position
{
public:
  int getRow() const { return 0; }
  int getCol() const { return 0; }
};

/***********************************************
* FETCH : a1
* +---a-b-c-d-e-f-g-h---+
* |                     |
* 8                     8
* 7                     7
* 6                     6
* 5                     5
* 4                     4
* 3                     3
* 2                     2
* 1  (x)                1
* |                     |
* +---a-b-c-d-e-f-g-h---+
***********************************************/
void TestBoard::fetch_a1()
{  // setup
  Board board;
  PieceDummy piece;
  Piece* pSave = board.board[0][0];
  board.board[0][0] = &piece;
  Position00 pos;
  Piece* p = nullptr;
  // exercise
  p = &(board[pos]);
  // verify
  assertUnit(p == &piece);
  // teardown
  board.board[0][0] = pSave;
}

void TestBoard::set_a1()
{  // setup
  Board board;
  PieceDummy piece;
  piece.fWhite = true;
  Piece* pSave = board.board[0][0];
  board.board[0][0] = &piece;
  Position00 pos;
  Piece* p = nullptr;
  // exercise
  board[pos].fWhite = false;
  // verify
  assertUnit(piece.fWhite == false);
  assertUnit(board.board[0][0]->fWhite == false);
  // teardown
  board.board[0][0] = pSave;
}

class Position77 : public Position
{
public:
  int getRow() const { return 7; }
  int getCol() const { return 7; }
};

/***********************************************
* FETCH : h8
* +---a-b-c-d-e-f-g-h---+
* |                     |
* 8                (x)  8
* 7                     7
* 6                     6
* 5                     5
* 4                     4
* 3                     3
* 2                     2
* 1                     1
* |                     |
* +---a-b-c-d-e-f-g-h---+
***********************************************/
void TestBoard::fetch_h8()
{  // setup
  Board board;
  PieceDummy piece;
  Piece* pSave = board.board[7][7];
  board.board[7][7] = &piece;
  Position77 pos;
  Piece* p = nullptr;
  // exercise
  p = &(board[pos]);
  // verify
  assertUnit(p == &piece);
  // teardown
  board.board[7][7] = pSave;
}

void TestBoard::set_h8()
{  // setup
  Board board;
  PieceDummy piece;
  piece.fWhite = true;
  Piece* pSave = board.board[7][7];
  board.board[7][7] = &piece;
  Position77 pos;
  Piece* p = nullptr;
  // exercise
  board[pos].fWhite = false;
  // verify
  assertUnit(piece.fWhite == false);
  assertUnit(board.board[7][7]->fWhite == false);
  // teardown
  board.board[7][7] = pSave;
}

class Position07 : public Position
{
public:
  int getRow() const { return 7; }
  int getCol() const { return 0; }
};

/***********************************************
* FETCH : a8
* +---a-b-c-d-e-f-g-h---+
* |                     |
* 8  (x)                8
* 7                     7
* 6                     6
* 5                     5
* 4                     4
* 3                     3
* 2                     2
* 1                     1
* |                     |
* +---a-b-c-d-e-f-g-h---+
***********************************************/
void TestBoard::fetch_a8()
{  // setup
  Board board;
  PieceDummy piece;
  Piece* pSave = board.board[0][7];
  board.board[0][7] = &piece;
  Position07 pos;
  Piece* p = nullptr;
  // exercise
  p = &(board[pos]);
  // verify
  assertUnit(p == &piece);
  // teardown
  board.board[0][7] = pSave;
}

void TestBoard::set_a8()
{  // setup
  Board board;
  PieceDummy piece;
  piece.fWhite = true;
  Piece* pSave = board.board[0][7];
  board.board[0][7] = &piece;
  Position07 pos;
  Piece* p = nullptr;
  // exercise
  board[pos].fWhite = false;
  // verify
  assertUnit(piece.fWhite == false);
  assertUnit(board.board[0][7]->fWhite == false);
  // teardown
  board.board[0][7] = pSave;
}


/***********************************************
* CREATE DUMMY BOARD
* Utility function - not a unit test
* Just fill the board with the known pieces
***********************************************/
void TestBoard::createDummyBoard(Board& board)
{
  for (int r = 0; r < 8; r++)
     for (int c = 0; c < 8; c++)
     {
        board.board[c][r] = new PieceDummy;
     }
}



/********************************************************
 *    e5c6
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6       .             6       6       n             6
 * 5          (n)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_knightMove()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(2, 5);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, KNIGHT);
   board.board[2][5] = new PieceSpy(2, 5, false /*isWhite*/, SPACE);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(KNIGHT == (board.board[2][5])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);   
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[2][5];
   delete board.board[4][4];
   board.board[2][5] = board.board[4][4] = nullptr;
}

 /********************************************************
 *    e5c6r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7       R             7       7                     7
 * 6                     6       6       n             6
 * 5          (n)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_knightAttack()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(2, 5);
   move.capture = ROOK;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new Knight(4, 4, true  /*isWhite*/);
   board.board[2][5] = new Rook(2, 5, false /*isWhite*/);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(KNIGHT == (board.board[2][5])->getType());
   assertUnit(ROOK == move.getCapturedPieceType());

   // TEARDOWN
   delete board.board[2][5];
   delete board.board[4][4];
   board.board[2][5] = board.board[4][4] = nullptr;


}

/********************************************************
  *   a2a3
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5                     5       5                     5
  * 4                     4  -->  4                     4
  * 3   .                 3       3   p                 3
  * 2  (p)                2       2   .                 2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_pawnSimple()
{  // SETUP
   Move move;
   move.source.set(1, 0);
   move.dest.set(1, 1);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[1][0] = new Pawn(1, 0, true  /*isWhite*/);
   board.board[1][1] = new PieceSpy(1, 1, true  /*isWhite*/, SPACE);
   board.board[1][0]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[1][0])->getType());
   assertUnit(PAWN == (board.board[1][1])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[1][0];
   delete board.board[1][1];
   board.board[1][0] = board.board[1][1] = nullptr;
}


/********************************************************
 *     a6b7r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7     R               7       7    (p)              7
 * 6  (p)                6       6   .                 6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnCapture()
{  // SETUP
   Move move;
   move.source.set(0, 5);
   move.dest.set(1, 6);
   move.capture = ROOK;                                  // Brother Helfrich, so how we do it is like we have a set of moves which keeps track of all mvoes
   move.promote = SPACE;                                 // throughout the game, and board.move() is simply taking the last element out from that set to
   move.isWhite = true;                                  // swap pieces and stuff. That's why we directly set move.capture to the captured piece type.
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[0][5] = new Pawn(0, 5, true  /*isWhite*/);
   board.board[1][6] = new Rook(1, 6, true  /*isWhite*/);
   board.board[0][5]->nMoves = 0;

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[0][5])->getType());
   assertUnit(PAWN == (board.board[1][6])->getType());
   assertUnit(ROOK == move.getCapturedPieceType());

   // TEARDOWN
   delete board.board[0][5];
   delete board.board[1][6];
   board.board[0][5] = board.board[1][6] = nullptr;
}


/********************************************************
 *    e2e4
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4           .         4  -->  4          (p)        4
 * 3                     3       3                     3
 * 2          (p)        2       2           .         2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnDouble()
{  // SETUP
   Move move;
   move.source.set(4, 1);
   move.dest.set(4, 3);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][1] = new Pawn(4, 1, true  /*isWhite*/);
   board.board[4][3] = new PieceSpy(4, 3, true  /*isWhite*/);
   board.board[4][1]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[4][1])->getType());
   assertUnit(PAWN == (board.board[4][3])->getType());
   assertUnit(SPACE == move.getCapturedPieceType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][1];
   delete board.board[4][3];
   board.board[4][1] = board.board[4][3] = nullptr;
}


/********************************************************
*     a5b6E
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6     .               6       6     p               6
 * 5  (p)P               5       5   . .               5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnEnpassant()
{  // SETUP
   Move move;
   move.source.set(0, 4);
   move.dest.set(1, 5);
   move.capture = PAWN;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::ENPASSANT;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[0][4] = new Pawn(4, 1, true  /*isWhite*/);
   board.board[1][5] = new Pawn(4, 3, true  /*isWhite*/);
   board.board[0][4]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[0][4])->getType());
   assertUnit(PAWN == (board.board[1][5])->getType());
   assertUnit(PAWN == move.getCapturedPieceType());
   assertUnit(Move::ENPASSANT == move.getMoveType());

   // TEARDOWN
   delete board.board[0][4];
   delete board.board[1][5];
   board.board[0][4] = board.board[1][5] = nullptr;
}


/********************************************************
 *    a7a8Q
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8   .                 8       8  (r)                8
 * 7  (p)                7       7   .                 7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnPromotion()
{  // SETUP
   Move move;
   move.source.set(0, 6);
   move.dest.set(0, 7);
   move.capture = SPACE;
   move.promote = QUEEN;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[0][6] = new Pawn(0, 6, true  /*isWhite*/);
   board.board[0][7] = new PieceSpy(0, 7, true  /*isWhite*/);
   board.board[0][6]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[0][6])->getType());
   assertUnit(QUEEN == (board.board[0][7])->getType());
   assertUnit(SPACE == move.getCapturedPieceType());
   assertUnit(Move::MOVE == move.getMoveType());

   // TEARDOWN
   delete board.board[0][6];
   delete board.board[0][7];
   board.board[0][6] = board.board[0][7] = nullptr;
}


/********************************************************
 *    e5a5
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5   .      (r)        5       5  (r)      .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_rookSlide()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(0, 4);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][4] = new Rook(4, 4, true  /*isWhite*/);
   board.board[0][4] = new PieceSpy(0, 4, true  /*isWhite*/);
   board.board[0][4]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(ROOK == (board.board[0][4])->getType());
   assertUnit(SPACE == move.getCapturedPieceType());
   assertUnit(Move::MOVE == move.getMoveType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[0][4];
   board.board[4][4] = board.board[0][4] = nullptr;
}



/********************************************************
 *    e5a5b
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5   B      (r)        5       5  (r)      .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_rookAttack()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(0, 4);
   move.capture = BISHOP;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][4] = new Rook(4, 4, true  /*isWhite*/);
   board.board[0][4] = new Bishop(0, 4, false  /*isWhite*/);
   board.board[0][4]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(ROOK == (board.board[0][4])->getType());
   assertUnit(BISHOP == move.getCapturedPieceType());
   assertUnit(Move::MOVE == move.getMoveType());

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[0][4];
   board.board[4][4] = board.board[0][4] = nullptr;
}


/********************************************************
 *    e5g3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (b)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3               .     3       3               b     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_bishopSlide()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(0, 4);
   move.capture = BISHOP;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][4] = new Rook(4, 4, true  /*isWhite*/);
   board.board[0][4] = new Bishop(0, 4, true  /*isWhite*/);
   board.board[0][4]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(ROOK == (board.board[0][4])->getType());
   assertUnit(BISHOP == move.getCapturedPieceType());
   assertUnit(Move::MOVE == move.getMoveType());

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[0][4];
   board.board[4][4] = board.board[0][4] = nullptr;
}


/********************************************************
 *    e5g3q
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (b)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3               Q     3       3               b     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_bishopAttack()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(6, 2);
   move.capture = QUEEN;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][4] = new Bishop(4, 4, true  /*isWhite*/);
   board.board[6][2] = new Bishop(6, 2, false  /*isWhite*/);
   board.board[4][4]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(BISHOP == (board.board[6][2])->getType());
   assertUnit(QUEEN == move.getCapturedPieceType());
   assertUnit(Move::MOVE == move.getMoveType());

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[6][2];
   board.board[4][4] = board.board[6][2] = nullptr;
}

/********************************************************
 *    e5g3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (q)        5       5                     5
 * 4                     4  -->  4           .         4
 * 3                .    3       3               q     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_queenSlide()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(6, 2);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][4] = new Queen(4, 4, true  /*isWhite*/);
   board.board[6][2] = new PieceSpy(6, 2, true  /*isWhite*/);
   board.board[4][4]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(QUEEN == (board.board[6][2])->getType());
   assertUnit(SPACE == move.getCapturedPieceType());
   assertUnit(Move::MOVE == move.getMoveType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[6][2];
   board.board[4][4] = board.board[6][2] = nullptr;
}


/********************************************************
*    e5a5b
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
* |                     |       |                     |
* 8                     8       8                     8
* 7                     7       7                     7
* 6                     6       6                     6
* 5   B      (q)        5       5  (q)      .         5
* 4                     4  -->  4                     4
* 3                     3       3                     3
* 2                     2       2                     2
* 1                     1       1                     1
* |                     |       |                     |
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
********************************************************/
void TestBoard::move_queenAttack()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(0, 4);
   move.capture = BISHOP;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][4] = new Queen(4, 4, true  /*isWhite*/);
   board.board[0][4] = new Bishop(0, 4, false  /*isWhite*/);
   board.board[4][4]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(QUEEN == (board.board[0][4])->getType());
   assertUnit(BISHOP == move.getCapturedPieceType());
   assertUnit(Move::MOVE == move.getMoveType());

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[0][4];
   board.board[4][4] = board.board[0][4] = nullptr;
}


/********************************************************
 *  e1f1
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k).       1       1           . k       1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingMove()
{  // SETUP
   Move move;
   move.source.set(4, 0);
   move.dest.set(5, 0);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][0] = new King(4, 0, true  /*isWhite*/);
   board.board[5][0] = new PieceSpy(5, 0, true  /*isWhite*/);
   board.board[4][0]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[4][0])->getType());
   assertUnit(KING == (board.board[5][0])->getType());
   assertUnit(SPACE == move.getCapturedPieceType());
   assertUnit(Move::MOVE == move.getMoveType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][0];
   delete board.board[5][0];
   board.board[4][0] = board.board[5][0] = nullptr;
}


/********************************************************
 *    e1f1r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k)R       1       1           . k       1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingAttack()
{  // SETUP
   Move move;
   move.source.set(4, 0);
   move.dest.set(5, 0);
   move.capture = ROOK;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][0] = new King(4, 0, true  /*isWhite*/);
   board.board[5][0] = new Rook(5, 0, false  /*isWhite*/);
   board.board[4][0]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(SPACE == (board.board[4][0])->getType());
   assertUnit(KING == (board.board[5][0])->getType());
   assertUnit(ROOK == move.getCapturedPieceType());
   assertUnit(Move::MOVE == move.getMoveType());

   // TEARDOWN
   delete board.board[4][0];
   delete board.board[5][0];
   board.board[4][0] = board.board[5][0] = nullptr;
}

/********************************************************
 *    e1g1c
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k). . r   1       1           . r k .   1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingShortCastle()
{  // SETUP
   Move move;
   move.source.set(4, 0);
   move.dest.set(6, 0);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::CASTLE_KING;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][0] = new King(4, 0, true  /*isWhite*/);
   board.board[6][0] = new Rook(6, 0, true  /*isWhite*/);
   board.board[4][0]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(ROOK == (board.board[4][0])->getType());
   assertUnit(KING == (board.board[6][0])->getType());
   assertUnit(SPACE == move.getCapturedPieceType());
   assertUnit(Move::CASTLE_KING == move.getMoveType());

   // TEARDOWN
   delete board.board[4][0];
   delete board.board[6][0];
   board.board[4][0] = board.board[6][0] = nullptr;
}



/********************************************************
 *    e1c1C
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1   r . . .(k)        1       1   . . k r .         1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingLongCastle()
{  // SETUP
   Move move;
   move.source.set(4, 0);
   move.dest.set(2, 0);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::CASTLE_QUEEN;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][0] = new King(4, 0, true  /*isWhite*/);
   board.board[2][0] = new Rook(2, 0, true  /*isWhite*/);
   board.board[4][0]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(ROOK == (board.board[4][0])->getType());
   assertUnit(KING == (board.board[2][0])->getType());
   assertUnit(SPACE == move.getCapturedPieceType());
   assertUnit(Move::CASTLE_QUEEN == move.getMoveType());

   // TEARDOWN
   delete board.board[4][0];
   delete board.board[2][0];
   board.board[4][0] = board.board[2][0] = nullptr;
}




/********************************************************
 *        +---a-b-c-d-e-f-g-h---+
 *        |                     |
 *        8   R N B Q K B N R   8
 *        7   P P P P P P P P   7
 *        6                     6
 *        5                     5
 *   -->  4                     4
 *        3                     3
 *        2   p p p p p p p p   2
 *        1   r n b q k b n r   1
 *        |                     |
 *        +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::construct_default()
{
   // SETUP
   // EXERCISE
   Board board;
   
   // verify
   assertUnit(board.pgout == nullptr);
   assertUnit(board.numMoves == 0);
   
} // TEARDOWN
