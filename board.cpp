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
#include <iostream>
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
   if (fFree) free();
   for (int r = 0; r < 8; r++)
   {
       for (int c = 0; c < 8; c++) {
           board[c][r] = new Space(c, r);
       }
   }
   
   // White pieces
   board[0][0] = new Rook(0, 0, true);  // White Rook
   board[7][0] = new Rook(7, 0, true);  // White Rook
   board[1][0] = new Knight(1, 0, true);  // White Knight
   board[6][0] = new Knight(6, 0, true);  // White Knight
   board[2][0] = new Bishop(2, 0, true);  // White Rook
   board[5][0] = new Bishop(5, 0, true);  // White Rook
   board[3][0] = new King(3, 0, true);  // White Queen
   board[4][0] = new Queen(4, 0, true);  // White King
   board[0][1] = new Pawn(0, 1, true);  // White Pawn
   board[1][1] = new Pawn(1, 1, true);  // White Pawn
   board[2][1] = new Pawn(2, 1, true);  // White Pawn
   board[3][1] = new Pawn(3, 1, true);  // White Pawn
   board[4][1] = new Pawn(4, 1, true);  // White Pawn
   board[5][1] = new Pawn(5, 1, true);  // White Pawn
   board[6][1] = new Pawn(6, 1, true);  // White Pawn
   board[7][1] = new Pawn(7, 1, true);  // White Pawn

   // Black pieces
   board[0][7] = new Rook(0, 7, false);    // Black Rook
   board[7][7] = new Rook(7, 7, false);    // Black Rook
   board[1][7] = new Knight(1, 7, false);  // Black Knight
   board[6][7] = new Knight(6, 7, false);  // Black Knight
   board[2][7] = new Bishop(2, 7, false);  // Black Rook
   board[5][7] = new Bishop(5, 7, false);  // Black Rook
   board[3][7] = new King(3, 7, false);   // Black Queen
   board[4][7] = new Queen(4, 7, false);    // Black King
   board[0][6] = new Pawn(0, 6, false);    // Black Pawn
   board[1][6] = new Pawn(1, 6, false);    // Black Pawn
   board[2][6] = new Pawn(2, 6, false);    // Black Pawn
   board[3][6] = new Pawn(3, 6, false);    // Black Pawn
   board[4][6] = new Pawn(4, 6, false);    // Black Pawn
   board[5][6] = new Pawn(5, 6, false);    // Black Pawn
   board[6][6] = new Pawn(6, 6, false);    // Black Pawn
   board[7][6] = new Pawn(7, 6, false);    // Black Pawn
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
      {
         // delete board[c][r];
         board[c][r] = nullptr;
      }
}


/**********************************************
 * BOARD : IS CHECKED
 *         Verify if a king is checked
 *********************************************/
bool Board::isChecked(set<Move>& moves, bool isWhiteTurn)
{
    // Get the position of the current player's king
    Position kingPosition;

    // Find the king's position on the board
    for (int c = 0; c < 8; c++) {
        for (int r = 0; r < 8; r++) {
            Piece* piece = board[c][r];
            if (piece && piece->getType() == KING && piece->isWhite() == isWhiteTurn) {
                kingPosition = Position(c, r);
                break;
            }
        }
    }

    // Check all pieces for potential moves
    for (int c = 0; c < 8; c++) {
        for (int r = 0; r < 8; r++) {
            Piece* piece = board[c][r];
            if (piece && piece->isWhite() != isWhiteTurn) { // Check only opponent's pieces
                set<Move> opponentMoves;
                piece->getMoves(opponentMoves, *this);
                
                // Check if any opponent's move can reach the King's position
                for (const Move& move : opponentMoves) {
                    if (move.getTo() == kingPosition) {
                        return true; // The king is in check
                    }
                }
            }
        }
    }

    return false; // The king is not in check
}

/**********************************************
 * BOARD : UNDO
 *         Reverse a previous move
 *********************************************/
void Board::undo(Move move)
{
   Position source = move.getFrom();
   Position dest = move.getTo();

   if (board[source.getCol()][source.getRow()] != nullptr)
   {
       delete board[source.getCol()][source.getRow()]; // Delete the piece at the source
   }
   
   // Move the piece back to its source position
   Piece* movingPiece = board[dest.getCol()][dest.getRow()];
   board[source.getCol()][source.getRow()] = movingPiece;

   // Restore any captured piece at the destination
   PieceType capturedType = move.getCapturedPieceType();
   bool isWhite = movingPiece->isWhite();

   // Recreate the captured piece in its original position
   switch (capturedType)
   {
      case KING:
         board[dest.getCol()][dest.getRow()] = new King(dest.getCol(), dest.getRow(), isWhite);
         break;
         
      case QUEEN:
         board[dest.getCol()][dest.getRow()] = new Queen(dest.getCol(), dest.getRow(), isWhite);
         break;
      
      case BISHOP:
         board[dest.getCol()][dest.getRow()] = new Bishop(dest.getCol(), dest.getRow(), isWhite);
         break;
         
      case KNIGHT:
         board[dest.getCol()][dest.getRow()] = new Knight(dest.getCol(), dest.getRow(), isWhite);
         break;
         
      case ROOK:
         board[dest.getCol()][dest.getRow()] = new Rook(dest.getCol(), dest.getRow(), isWhite);
         break;
         
      case PAWN:
         board[dest.getCol()][dest.getRow()] = new Pawn(dest.getCol(), dest.getRow(), isWhite);
         break;
         
      default:
         board[dest.getCol()][dest.getRow()] = new Space(dest.getCol(), dest.getRow());
         break;
   }
}




/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(Move & move)       // Take moves as a parameter so the boad can know if king is checked
{
    // Get source and destination positions for clarity
    Position source = move.getFrom();
    Position dest = move.getTo();

    // Handle captures
    if (board[dest.getCol()][dest.getRow()]->getType() != SPACE)
    {
        // If it's not a castling move, handle as capture
        if (board[source.getCol()][source.getRow()]->getType() != KING)
        {
            delete board[dest.getCol()][dest.getRow()];
            board[dest.getCol()][dest.getRow()] = new Space(dest.getCol(), dest.getRow());
        }
        else if (board[source.getCol()][source.getRow()]->isWhite() !=
            board[dest.getCol()][dest.getRow()]->isWhite())
        {
            delete board[dest.getCol()][dest.getRow()];
            board[dest.getCol()][dest.getRow()] = new Space(dest.getCol(), dest.getRow());
        }
    }

    // Move the piece
    Piece* movingPiece = board[source.getCol()][source.getRow()];
    Piece* destSpace = board[dest.getCol()][dest.getRow()];

    // Update the board
    board[dest.getCol()][dest.getRow()] = movingPiece;
    board[source.getCol()][source.getRow()] = destSpace;

    // Handle pawn promotion
    if (movingPiece->getType() == PAWN)
    {
       if (move.getMoveType() == Move::ENPASSANT)
       {
           // Determine the row of the captured pawn
           int capturedRow = movingPiece->isWhite() ? dest.getRow() - 1 : dest.getRow() + 1;

           // Remove the captured pawn from the board
           delete board[dest.getCol()][capturedRow];
           board[dest.getCol()][capturedRow] = new Space(dest.getCol(), capturedRow);
       }
       else
       {
          // White pawn promotion
          if (dest.getRow() == 7 && movingPiece->isWhite())
          {
             delete board[dest.getCol()][dest.getRow()];
             board[dest.getCol()][dest.getRow()] = new Queen(dest.getCol(), dest.getRow(), true);
          }
          // Black pawn promotion
          else if (dest.getRow() == 0 && !movingPiece->isWhite())
          {
             delete board[dest.getCol()][dest.getRow()];
             board[dest.getCol()][dest.getRow()] = new Queen(dest.getCol(), dest.getRow(), false);
          }
       }
    }

    // Update piece positions
    if (board[dest.getCol()][dest.getRow()]->getType() != SPACE)
        board[dest.getCol()][dest.getRow()]->setPosition(dest);
    if (board[source.getCol()][source.getRow()]->getType() != SPACE)
        board[source.getCol()][source.getRow()]->setPosition(source);

    // Update move counters
    board[dest.getCol()][dest.getRow()]->setLastMove(numMoves);
    board[source.getCol()][source.getRow()]->setLastMove(numMoves);

    // Increment the move counter
    numMoves++;
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

