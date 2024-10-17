#pragma once
#pragma once
#include "piece.h"

class King : public Piece
{
public:
    King(int col, int row, bool isWhite);
    PieceType getType() const override { return KING; }
    void getMoves(set<Move>& moves, const Board& board) const;
    void display(ogstream* pgout) const override;

private:
    bool canCastle(const Board& board, bool kingSide) const;
    void addCastlingMoves(set<Move>& moves, const Board& board) const;
};