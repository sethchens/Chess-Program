#pragma once
#include "piece.h"

class Queen : public Piece
{
public:
    Queen(int col, int row, bool isWhite);
    PieceType getType() const override { return QUEEN; }
    void getMoves(set<Move>& moves, const Board& board) const;
    void display(ogstream* pgout) const override;
};

