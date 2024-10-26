#include "pieceKing.h"
#include "board.h"
#include "uiDraw.h"
#include "iostream"

King::King(int col, int row, bool isWhite) : Piece(col, row, isWhite) {}

void King::getMoves(set<Move>& moves, const Board& board) const
{
    const int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    for (const auto& dir : directions)
    {
        int newCol = getPosition().getCol() + dir[0];
        int newRow = getPosition().getRow() + dir[1];
        Position newPos(newCol, newRow);


        if (newPos.isValid())
        {
            const Piece& pieceAtNewPos = board[newPos];
            Move newMove(position, newPos);

            if (pieceAtNewPos.getType() == SPACE)
            {
                newMove.setCapture(SPACE);
                moves.insert(newMove);
            }
            else if (pieceAtNewPos.isWhite() != isWhite())
            {
                newMove.setCapture(pieceAtNewPos.getType());
                moves.insert(newMove);
            }
        }
    }

    // Add castling moves
    addCastlingMoves(moves, board);
}

bool King::canCastle(const Board& board, bool kingSide) const
{
    if (isMoved())
        return false;

    int row = isWhite() ? 0 : 7;
    int rookCol = kingSide ? 7 : 0;
    Position rookPos(rookCol, row);

    const Piece& rook = board[rookPos];
    if (rook.getType() != ROOK || rook.isMoved())
        return false;

    // Check if the path is clear
    int start = kingSide ? 5 : 1;
    int end = kingSide ? 6 : 3;
    for (int col = start; col <= end; ++col)
    {
        Position pos(col, row);
        if (board[pos].getType() != SPACE)
            return false;

        // We can't check if the king passes through a check here
        // because we can't call isCheck() on a const Board
    }

    return true;
}


void King::addCastlingMoves(set<Move>& moves, const Board& board) const
{
    if (canCastle(board, true))  // Kingside castling
    {
        Position kingFinal(6, position.getRow());
        Move castleMove(position, kingFinal);
        castleMove.setMoveType("CASTLE_KING");
        moves.insert(castleMove);
       
       Position rookOriginRight(7, position.getRow());
       Position rookFinalRight(5, position.getRow());
       Move moveRight(rookOriginRight, rookFinalRight);
       moves.insert(moveRight);
    }

    if (canCastle(board, false))  // Queenside castling
    {
        Position kingFinal(2, position.getRow());
        Move castleMove(position, kingFinal);
        castleMove.setMoveType("CASTLE_QUEEN");
        moves.insert(castleMove);
       
       Position rookOriginLeft(0, position.getRow());
       Position rookFinalLeft(3, position.getRow());
       Move moveLeft(rookOriginLeft, rookFinalLeft);
       moves.insert(moveLeft);
    }
}

void King::display(ogstream* pgout) const
{
    pgout->drawKing(getPosition(), isWhite());
}
