/***********************************************************************
 * Header File:
 *    MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include <cassert>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
public:
   enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

   friend TestMove;
   friend TestBoard;

   // constructor
   Move();
   Move(const Position &from, const Position &to): source(from), dest(to) {}
   Move(const string move);
   
   // getters
   const Position & getFrom() const                  { return source;   }
   const Position & getTo() const                    { return dest;     }
   const PieceType getCapturedPieceType()            { return capture;  }
   const PieceType & getPromotionPieceType()         { return promote;  }
   const MoveType getMoveType()                      { return moveType; }
   const bool getCapturedPieceColor();
   const PieceType & getPrevPiece();
   const bool getPrevPieceColor();
   const string getText();
   
   // setters
   void setMoveType(string move);
   void setCapturedPieceType(string move);
   void setPromotionPiece(PieceType pt) { promote = pt; } //Added for promotion 10/16/2024
   void setCapture(PieceType capturedPiece) { capture = capturedPiece; }
   
   const bool isPromotion();
   bool isEnPassant(string move);
   bool isCastleKing(string move);
   bool isCastleQueen(string move);
   bool operator<(const Move & rhs) const;
   bool operator==(const Move& rhs) const;
   void constructPos(string move);
   int readAndAssign();


protected:
   char letterFromPieceType(PieceType pt)     const;
   PieceType pieceTypeFromLetter(char letter) const;



   Position  source;    // where the move originated from
   Position  dest;      // where the move finished
   PieceType promote;   // piece to be promoted to
   PieceType capture;   // did a capture happen this move?
   MoveType  moveType;  // what type of move is this?
   bool      isWhite;   // whose turn is it anyway?
   bool      castleKing;
   bool      castleQueen;
   bool      enPassant;
   string    text;      // what is the textual version of the move?
};

class MoveDummy: public Move
{
public:
   friend TestMove;

   // constructor
   MoveDummy() : Move() {};
   
   // setters
   void setMoveType(string move)             { assert(false);              }
   void setCapturedType(string move)         { assert(false);              }
   
   // getters
   const Position  &getFrom()                {assert(false); throw true;   }
   const Position  &getTo()                  {assert(false); throw true;   }
   const PieceType &getPrevPiece()           {assert(false); throw true;   }
   const PieceType &getPromotionPiece()      {assert(false); throw true;   }
   const PieceType  getCapturedPieceType()   {assert(false); throw true;   }
   const MoveType   getMoveType(string move) {assert(false); throw true;   }
   const string     getText()                {assert(false); throw true;   }
   const bool       getPrevPieceColor()      {assert(false); return false; }
   const bool       getCapturedPieceColor()  {assert(false); return false; }
   
   int readAndAssign() {assert(false); return 0; }
   void assign() {assert(false); }
   void constructPos(string move){assert(false); }
   
   const bool isPromotion() {assert(false); return false; }
   bool isEnPassant(string move) {assert(false); return false; }
   bool isCastleKing(string move) {assert(false); return false; }
   bool isCastleQueen(string move) {assert(false); return false; }
   bool operator == (Move &rhs) {assert(false); return false; }
   bool operator <  (Move &rhs) {assert(false); return false; }
   


private:
   char letterFromPieceType(PieceType pt)     const {assert(false); throw true; }
   PieceType pieceTypeFromLetter(char letter) const {assert(false); throw true; }

};

/***************************************************
 * MOVE STUB CONSTRUCT
 * A move double that only converts pieceType to letter or viseversa.  This is for the unit test.
 **************************************************/
class StubMoveConstruct: public MoveDummy // need to put definition in c++
{
public:
   friend TestMove;

   // constructor
   StubMoveConstruct() : MoveDummy() {};
   char letterFromPieceType(PieceType pt) const;
   PieceType PieceTypeFromLetter(char letter) const;
};

/***************************************************
 * MOVE STUB SIMPLE MOVE
 * A move double that only does sumple move. This is for the unit test.
 **************************************************/
class StubMoveSimpleMove: public MoveDummy // need to put definition in c++
{
public:
   friend TestMove;

   // constructor
   StubMoveSimpleMove() : MoveDummy() {};
   const string getText();
   int readAndAssign(string move);
   void setMoveType(string move);
};

/***************************************************
 * MOVE STUB COMPARE
 * A move double that only does comparision.  This is for the unit test.
 **************************************************/
class StubMoveCompare : public MoveDummy
{
public:
   const Position & getFrom() { return source; }
   const Position & getTo() { return dest; }
   bool operator == (StubMoveCompare &rhs);
   bool operator <  (StubMoveCompare &rhs);
};

/***************************************************
 * MOVE STUB ADVANCED MOVE
 * A move double that only does advanced move. This is for the unit test.
 **************************************************/
class StubMoveAdvancedMove: public MoveDummy
{
public:
   friend TestMove;

   // constructor
   StubMoveAdvancedMove() : MoveDummy() {};
   const string getText();
   int readAndAssign(string move);
   void setMoveType(string move);
   void setCapturedPieceType(string move);
   bool isEnPassant(string move);
   bool isCastleKing(string move);
   bool isCastleQueen(string move);
};

