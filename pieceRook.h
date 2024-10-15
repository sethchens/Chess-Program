#pragma once
#include "piece.h"

class Rook : public Piece
{
public:
    Rook(int col, int row, bool isWhite);
    PieceType getType() const override { return ROOK; }
    void getMoves(set<Move>& moves, const Board& board) const;
    void display(ogstream* pgout) const override;
};

