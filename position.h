/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <string>
#include <cstdint>
using std::string;
using std::ostream;
using std::istream;

const int SIZE_SQUARE  = 32;   // number of pixels in a square by default
const int OFFSET_BOARD = 50;   // boarder between the board and the edge of screen

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0};
const Delta ADD_C = { 0,  1};
const Delta SUB_R = {-1,  0};
const Delta SUB_C = { 0, -1};


class PositionTest;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
   Position(const Position& rhs) : colRow(rhs.colRow) {}
   Position() : colRow(0xff) {}
   bool isInvalid() const         { return (colRow & 0x88) != 0; }
   bool isValid()   const         { return !isInvalid(); }
   void setValid()                { colRow &= 0x77; }
   void setInvalid()              { colRow = 0xff; }
   bool operator <  (const Position & rhs) const { return colRow < rhs.colRow; }
   bool operator == (const Position & rhs) const { return colRow == rhs.colRow;}
   bool operator != (const Position & rhs) const { return colRow != rhs.colRow; }
   const Position& operator = (const Position& rhs) { colRow = rhs.colRow; return *this; }
   
   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
   Position(int location);
   int getLocation() const;
   void setLocation(int location);

   
   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
   Position(int c, int r);
   virtual int getCol() const;
   virtual int getRow() const;
   void setRow(int r);
   void setCol(int c);
   void set(int c, int r);

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"
   
   Position(const char* s);
   Position(const string& s);
   const Position& operator = (const char* rhs);
   const Position& operator = (const string& rhs);
   string getText() const;
   
   // Helper method to set position from text
   void setFromText(const string& s);

   
   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()   const { return isValid() ? getCol() * (int)squareWidth + OFFSET_BOARD : -1; }
   int getY()   const { return isValid() ? getRow() * (int)squareHeight + OFFSET_BOARD : -1; }
   void setXY(double x, double y);
   double getSquareWidth()  const { return squareWidth; }
   double getSquareHeight() const { return squareHeight; }
   void setSquareWidth (double width )  { squareWidth = width; }
   void setSquareHeight(double height)  { squareHeight = height; }

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position& rhs, const Delta& delta);
   void adjustRow(int dRow);
   void adjustCol(int dCol);
   const Position& operator += (const Delta& rhs);
   Position operator + (const Delta& rhs) const;

private:
   void set(uint8_t colRowNew) { colRow = colRowNew; }
   
   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;


};


ostream & operator << (ostream & out, const Position & pos);
istream & operator >> (istream & in,  Position & pos);
      
