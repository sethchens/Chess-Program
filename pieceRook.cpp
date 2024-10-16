#include "pieceRook.h"
#include "board.h"
#include "uiDraw.h"

Rook::Rook(int col, int row, bool isWhite) : Piece(col, row, isWhite) {}

void Rook::getMoves(set<Move>& moves, const Board& board) const
{
    const int directions[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    for (const auto& dir : directions)
    {
        for (int i = 1; i < 8; ++i)
        {
            int newCol = position.getCol() + i * dir[0];
            int newRow = position.getRow() + i * dir[1];
            Position newPos(newCol, newRow);

            if (!newPos.isValid())
                break;

            const Piece& pieceAtNewPos = board[newPos];
            Move newMove(position, newPos);

            if (pieceAtNewPos.getType() == SPACE)
            {
                newMove.setCapture(SPACE);
                moves.insert(newMove);
            }
            else
            {
                if (pieceAtNewPos.isWhite() != isWhite())
                {
                    newMove.setCapture(pieceAtNewPos.getType());
                    moves.insert(newMove);
                }
                break;  // Stop in this direction after encountering any piece
            }
        }
    }
}

void Rook::display(ogstream* pgout) const
{
    pgout->drawRook(position, isWhite());
}
