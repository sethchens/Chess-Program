#pragma once
#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn(int col, int row, bool isWhite);
    PieceType getType() const override { return PAWN; }
    void getMoves(set<Move>& moves, const Board& board) const;
    void display(ogstream* pgout) const override;

private:
    void addMove(set<Move>& moves, const Position& newPos, PieceType capture, const Board& board) const;
    void addPromotionMoves(set<Move>& moves, const Position& newPos, PieceType capture) const;
    bool canEnPassant(const Position& newPos, const Board& board) const;
    void addCaptureMove(set<Move>& moves, const Position& capturePos, const Board& board) const;
};

