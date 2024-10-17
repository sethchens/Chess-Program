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

    //if (canEnPassant(captureLeft, board))
    //    std::cout << "En Passant available on e3\n";
    //if (canEnPassant(captureRight, board))
    //    std::cout << "En Passant available on g3\n";

    //std::cout << "Capture Left Position: " << captureLeft.getRow() << ", " << captureLeft.getCol() << std::endl;
    //std::cout << "Capture Right Position: " << captureRight.getRow() << ", " << captureRight.getCol() << std::endl;

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
    if (position.getRow() != enPassantRow) return false;

    const Piece& adjacentPiece = board[Position(capturePos.getCol(), position.getRow())];
    return adjacentPiece.getType() == PAWN &&
        adjacentPiece.isWhite() != isWhite() &&
        adjacentPiece.justMoved(board.getCurrentMove());
}

void Pawn::display(ogstream* pgout) const
{
    pgout->drawPawn(position, isWhite());
}