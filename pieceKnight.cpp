/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{
   pgout->drawKnight(this->position, this->fWhite);
}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set<Move>& moves, const Board& board) const
{
    const int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (const auto& move : knightMoves)
    {
        int newRow = this->position.getRow() + move[1];
        int newCol = this->position.getCol() + move[0];

        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
        {
            Position pos(newCol, newRow);
            Move newMove(this->position, pos);

            if (board[pos].getType() == SPACE)
            {
                // Empty square, regular move
                newMove.setCapture(SPACE);
                moves.insert(newMove);
            }
            else if (board[pos].isWhite() != this->fWhite)
            {
                // Opposite color piece, capture move
                newMove.setCapture(board[pos].getType());
                moves.insert(newMove);
            }
        }
    }
}
