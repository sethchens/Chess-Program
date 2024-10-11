/***********************************************************************
 * Header File:
 *    SPACE
 * Author:
 *    Chris Mijangos and Seth Chen
 * Summary:
 *    The space
 ************************************************************************/

#pragma once

#include "piece.h"

class TestSpace;

 /***************************************************
  * SPACES
  * A space is a trivial piece
  ***************************************************/
class Space : public Piece
{
   friend TestSpace;
public:
   Space(int c, int r) : Piece(c, r, true) { pieceText = ' '; }
   ~Space()                            {               }
   PieceType getType()           const override { return SPACE; }
   void display(ogstream* pgout) const override {               }
};
