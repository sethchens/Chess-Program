#pragma once
#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(int col, int row, bool isWhite);
    PieceType getType() const override { return BISHOP; }
    void getMoves(set<Move>& moves, const Board& board) const;
    void display(ogstream* pgout) const override;
};

