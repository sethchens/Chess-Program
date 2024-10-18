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
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
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

   board[1][0] = new Knight(1, 0, true);  // White Knight
   board[6][0] = new Knight(6, 0, true);  // White Knight
   board[1][7] = new Knight(1, 7, false); // Black Knight
   board[6][7] = new Knight(6, 7, false); // Black Knight
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
