#include "piecePawn.h"
#include "board.h"
#include "uiDraw.h"
#include "iostream"

Pawn::Pawn(int col, int row, bool isWhite) : Piece(col, row, isWhite) {}

void Pawn::getMoves(set<Move>& moves, const Board& board) const
{
    int direction = isWhite() ? 1 : -1;
    Position forward(position, Delta{ direction, 0 });
    Position forwardTwo(position, Delta{ 2 * direction, 0 });
    Position captureLeft(position, Delta{ direction, -1 });
    Position captureRight(position, Delta{ direction, 1 });

    // Forward move
    if (forward.isValid() && board[forward].getType() == SPACE)
    {
        addMove(moves, forward, SPACE, board);
        // Initial double move
        int startingRank = isWhite() ? 1 : 6;
        if (position.getRow() == startingRank && forwardTwo.isValid() && board[forwardTwo].getType() == SPACE)
        {
            addMove(moves, forwardTwo, SPACE, board);
        }
    }

    // Capture moves
    addCaptureMove(moves, captureLeft, board);
    addCaptureMove(moves, captureRight, board);
}

void Pawn::addCaptureMove(set<Move>& moves, const Position& capturePos, const Board& board) const
{
    if (capturePos.isValid())
    {
        const Piece& pieceAtCapture = board[capturePos];
        if (pieceAtCapture.getType() != SPACE && pieceAtCapture.isWhite() != isWhite())
        {
            addMove(moves, capturePos, pieceAtCapture.getType(), board);
        }
        else if (canEnPassant(capturePos, board))
        {
            Move enPassant(position, capturePos);
            enPassant.setCapture(PAWN);
            enPassant.setMoveType("ENPASSANT");
            moves.insert(enPassant);
        }
    }
}

void Pawn::addMove(set<Move>& moves, const Position& newPos, PieceType capture, const Board& board) const
{
    if ((isWhite() && newPos.getRow() == 7) || (!isWhite() && newPos.getRow() == 0))
    {
        addPromotionMoves(moves, newPos, capture);
    }
    else
    {
        Move move(position, newPos);
        move.setCapture(capture);
        moves.insert(move);
    }
}

void Pawn::addPromotionMoves(set<Move>& moves, const Position& newPos, PieceType capture) const
{
    const PieceType promotions[] = { QUEEN, ROOK, BISHOP, KNIGHT };
    for (PieceType promotion : promotions)
    {
        Move move(position, newPos);
        move.setCapture(capture);
        move.setPromotionPiece(promotion);
        moves.insert(move);
    }
}

bool Pawn::canEnPassant(const Position& capturePos, const Board& board) const
{
    int enPassantRow = isWhite() ? 4 : 3;

    // Check if the pawn is on the en passant row
    if (position.getRow() != enPassantRow) {
        return false;
    }

    // Get the adjacent piece's position (adjacent pawn should be on the previous row)
    int adjacentCol = position.getCol() + (capturePos.getCol() > position.getCol() ? 1 : -1);
    Position adjacentPos(adjacentCol, position.getRow());  // Correct the adjacent position

    const Piece& adjacentPiece = board[adjacentPos];

    // Check if the adjacent piece is a pawn of the opposite color and just moved
    if (adjacentPiece.getType() == PAWN &&
        adjacentPiece.isWhite() != isWhite() &&
        adjacentPiece.justMoved(board.getCurrentMove()) &&
        abs(position.getCol() - capturePos.getCol()) == 1) 
    
    {
        return true;
    }


    return false;
}

void Pawn::display(ogstream* pgout) const
{
    pgout->drawPawn(position, isWhite());
}