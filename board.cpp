/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *    Chris Mijangos and Seth Chen
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "pieceSpace.h"
#include <cassert>
using namespace std;


/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
   free();
   for (int r = 0; r < 8; r++)
   {
       for (int c = 0; c < 8; c++)
       {
           board[c][r] = new Space(c, r);
       }
   }
   
   // White pieces
   board[0][0] = new Rook(0, 0, false);  // Black Rook
   board[7][0] = new Rook(7, 0, false);  // Black Rook
   board[1][0] = new Knight(1, 0, false);  // Black Knight
   board[6][0] = new Knight(6, 0, false);  // Black Knight
   board[2][0] = new Bishop(2, 0, false);  // Black Rook
   board[5][0] = new Bishop(5, 0, false);  // Black Rook
   board[3][0] = new Queen(3, 0, false);  // Black Queen
   board[4][0] = new King(4, 0, false);  // Black King
   board[0][1] = new Pawn(0, 1, false);  // Black Pawn
   board[1][1] = new Pawn(1, 1, false);  // Black Pawn
   board[2][1] = new Pawn(2, 1, false);  // Black Pawn
   board[3][1] = new Pawn(3, 1, false);  // Black Pawn
   board[4][1] = new Pawn(4, 1, false);  // Black Pawn
   board[5][1] = new Pawn(5, 1, false);  // Black Pawn
   board[6][1] = new Pawn(6, 1, false);  // Black Pawn
   board[7][1] = new Pawn(7, 1, false);  // Black Pawn
   
   // Black pieces
   board[0][7] = new Rook(0, 7, true);    // White Rook
   board[7][7] = new Rook(7, 7, true);    // White Rook
   board[1][7] = new Knight(1, 7, true);  // White Knight
   board[6][7] = new Knight(6, 7, true);  // White Knight
   board[2][7] = new Bishop(2, 7, true);  // White Rook
   board[5][7] = new Bishop(5, 7, true);  // White Rook
   board[3][7] = new Queen(3, 7, true);   // White Queen
   board[4][7] = new King(4, 7, true);    // White King
   board[0][6] = new Pawn(0, 6, true);    // White Pawn
   board[1][6] = new Pawn(1, 6, true);    // White Pawn
   board[2][6] = new Pawn(2, 6, true);    // White Pawn
   board[3][6] = new Pawn(3, 6, true);    // White Pawn
   board[4][6] = new Pawn(4, 6, true);    // White Pawn
   board[5][6] = new Pawn(5, 6, true);    // White Pawn
   board[6][6] = new Pawn(6, 6, true);    // White Pawn
   board[7][6] = new Pawn(7, 6, true);    // White Pawn
}

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
// This operator overload is called as a getter
const Piece& Board::operator [] (const Position& pos) const
{
   assert(pos.isValid());
   return *(board[pos.getCol()][pos.getRow()]);
}
Piece& Board::operator [] (const Position& pos)
{
   return *(board[pos.getCol()][pos.getRow()]);
}

 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position & posSelect) const
{
   pgout->drawHover(posHover);
   pgout->drawSelected(posSelect);
   pgout->drawBoard();
   for (int r = 0; r < 8; r++)
   {
       for (int c = 0; c < 8; c++)
       {
          board[c][r]->display(pgout);
       }
   }
}


/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
   if (!noreset)
      reset();
}


/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         board[c][r] = nullptr;
}


/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}




/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(Move & move)
{
   // If the piece currently at dest is not a space, that means it's a capture.
   if (board[move.getTo().getCol()][move.getTo().getRow()]->getType() != SPACE)
   {
      // The only exception is that if the source is a king, the move is actually a castling
      if (board[move.getFrom().getCol()][move.getFrom().getRow()]->getType() != KING)
      {
            board[move.getTo().getCol()][move.getTo().getRow()] = new Space(move.getFrom().getCol(), move.getFrom().getRow());
      }
      else
      {
         if (board[move.getFrom().getCol()][move.getFrom().getRow()]->isWhite() != board[move.getTo().getCol()][move.getTo().getRow()]->isWhite())
            board[move.getTo().getCol()][move.getTo().getRow()] = new Space(move.getFrom().getCol(), move.getFrom().getRow());
      }
   }
   
   // Swapping two pointers
   Piece * pToSwap = board[move.getTo().getCol()][move.getTo().getRow()];
   board[move.getTo().getCol()][move.getTo().getRow()] = board[move.getFrom().getCol()][move.getFrom().getRow()];
   
   // If the dest is the last row and the piece is a pawn (promotion), dest will then point to a queen
   if (move.getTo().getRow() == 7 && board[move.getTo().getCol()][move.getTo().getRow()]->isWhite() == true)
   {
      delete board[move.getTo().getCol()][move.getTo().getRow()];
      board[move.getTo().getCol()][move.getTo().getRow()] = new Queen(move.getFrom().getCol(), move.getFrom().getRow(), true);
   }
   else if (move.getTo().getRow() == 0 && board[move.getTo().getCol()][move.getTo().getRow()]->isWhite() == false)
   {
      delete board[move.getTo().getCol()][move.getTo().getRow()];
      board[move.getTo().getCol()][move.getTo().getRow()] = new Queen(move.getFrom().getCol(), move.getFrom().getRow(), false);
   }
   
   
   // The source is now pointing to the piece from dest
   board[move.getFrom().getCol()][move.getFrom().getRow()] = pToSwap;
   
   // Update their current position
   board[move.getFrom().getCol()][move.getFrom().getRow()]->setPosition(move.getTo());
   board[move.getTo().getCol()][move.getTo().getRow()]->setPosition(move.getFrom());
   
   // update nMove and all that
   board[move.getTo().getCol()][move.getTo().getRow()]->setLastMove(1);
   board[move.getFrom().getCol()][move.getFrom().getRow()] -> setLastMove(1);
   
   // Record numMove
   numMoves ++;
}



/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy()
{
   pSpace = new Space(0, 0);
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            board[c][r] = nullptr;
}
BoardEmpty::~BoardEmpty()
{
   delete pSpace;
}
