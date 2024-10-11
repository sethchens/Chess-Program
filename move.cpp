/***********************************************************************
 * Source File:
 *    MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move()
{
   source.setInvalid();
   dest.setInvalid();
   capture = SPACE;
   moveType = MOVE_ERROR;
   isWhite = true;
   promote = PieceType::INVALID;
}

/***************************************************
 * MOVE : CONSTRUCTOR
 ***************************************************/
Move::Move(const string move)
{
   text = move;
   source.setFromText(move.substr(0, 2));
   dest.setFromText(move.substr(2, 2));
}

/***************************************************
 * LETTER FROM PIECE TYPE: Convert piece type in to its textual representation.
 * Input: string
 * Output: char
 ***************************************************/
char Move::letterFromPieceType(PieceType pt) const
{
   if (pt == PAWN)
      return  'p';
   else if (pt == ROOK)
      return  'r';
   else if (pt == KNIGHT)
      return 'n';
   else if (pt == BISHOP)
      return 'b';
   else if (pt == QUEEN)
      return 'q';
   else if (pt == KING)
      return 'k';
   else
      return ' ';
}

/***************************************************
 * PIECE TYPE FROM LETTER: Construct letter to piece type
 * Input: letterType: char
 * Output: void
 ***************************************************/
PieceType Move::pieceTypeFromLetter(char letter) const
{
   if (letter == 'p')
      return  PAWN;
   else if (letter == 'r')
      return  ROOK;
   else if (letter == 'n')
      return  KNIGHT;
   else if (letter == 'b')
      return  BISHOP;
   else if (letter == 'q')
      return  QUEEN;
   else if (letter == 'k')
      return  KING;
   else
      return  SPACE;
}

/***************************************************
 * READ: Read textual move from a file
 * Input: string
 * Output: void
 ***************************************************/
int Move::readAndAssign()
{
   ifstream file("/Users/seth/Library/CloudStorage/OneDrive-BYU-Idaho/MacBook/Fall 2024/Inheritance Design/Chess-program-Lab4");
   
   // Handle file opening error
   if (!file.is_open())
   {
      cerr << "Error when reading file." << endl;
      return -1;
   }
   
   string line;
   string lastMove;
   while (getline(file, line))
   {
      lastMove = line;
   }
   
   file.close();
   
   // Assign source and destination from Smith Notation
   this->source = lastMove.substr(0, 2);
   this->dest = lastMove.substr(2, 2);
   
   setMoveType(lastMove);
   if (isEnPassant(lastMove))
      this->capture = PAWN;
   else
      setCapturedPieceType(lastMove);
   
   return 0;
}

/***************************************************
 * GET MOVE TYPE: Determine the move type
 * Input: move: string
 * Output: type: MoveType
 ***************************************************/
void Move::setMoveType(string move)
{
   if (isCastleKing(move))
      moveType = CASTLE_KING;
   else if (isCastleQueen(move))
       moveType =  CASTLE_QUEEN;
   else if (isEnPassant(move))
      moveType = ENPASSANT;
   else if ((move[0] - 'a') * 8 + move[1] - '1' > 64 || (move[0] - 97) * 8 + move[1] - '1' < 1 ||
            (move[2] - 'a') * 8 + move[3] - '1' > 64 || (move[2] - 97) * 8 + move[3] - '1' < 1)
      moveType = MOVE_ERROR;
   else
      moveType = MOVE;
}

/***************************************************
 * GET CAPTURED PIECE: Determine the piece type
 * Input: move: string
 * Output: type: PieceType
 ***************************************************/
void Move::setCapturedPieceType(string move)
{
   
   if (move.length() < 5)
   {
      if (move.length() < 4)
         capture = INVALID;
      else
         capture = SPACE;
   }
   else
      switch (tolower(move[4]))
      {
          case 'p':
            capture = PAWN;
            break;
          case 'k':
            capture = KING;
            break;
          case 'q':
            capture = QUEEN;
            break;
          case 'r':
            capture = ROOK;
            break;
          case 'b':
            capture = BISHOP;
            break;
          case 'n':
            capture = KNIGHT;
            break;
         case 'e':        // if En-Passant
            capture = PAWN;
            break;
         case 'c':        // if King side castle, no capture
            capture = SPACE;
            break;
         default:
            capture = INVALID;
            break;
      }
   
}

/***************************************************
 * IS EN PASSANT: Determine if an En-Passant happens
 * Input: move: string
 * Output: type: bool
 ***************************************************/
bool Move::isEnPassant(string move)
{
   if (move.length() > 4)
   {
      enPassant = true;
      return move[4] == 'E';
   }
   enPassant = false;
   return false;
}

/***************************************************
 * IS CASTLE KING: Determine if a castle  happens
 * Input: move: string
 * Output: type: bool
 ***************************************************/
bool Move::isCastleKing(string move)
{
   
//   if (pKing->pos.getText() == "e1" && pKing->fWhite == true &&
//      (pKing + sizeof(pKing) * 3)->pos.getText() == "h1" && (pKing + sizeof(pKing) * 3)->fWhite == true)
//      if ((pKing + sizeof(pKing))->pos.getText() == " " || (pKing + sizeof(pKing) * 2)->pos.getText() == " ")
//         return false;
//   return true;
   if (move.substr(0, 2) == "e1" && move.substr(2, 2) == "g1" && move[4] == 'c')
   {
      castleKing = true;
      return true;
   }
   castleKing = false;
   return false;
}

/***************************************************
 * IS CASTLE QUEEN: Determine if a castle  happens
 * Input: move: string
 * Output: type: bool
 ***************************************************/
bool Move::isCastleQueen(string move)
{
   
//   if (pKing->pos.getText() == "e1" && pKing->fWhite == true &&
//      (pKing + sizeof(pKing) * 3)->pos.getText() == "h1" && (pKing + sizeof(pKing) * 3)->fWhite == true)
//      if ((pKing + sizeof(pKing))->pos.getText() == " " || (pKing + sizeof(pKing) * 2)->pos.getText() == " ")
//         return false;
//   return true;
   if (move.substr(0, 2) == "e1" && move.substr(2, 2) == "c1" && move[4] == 'C')
   {
      castleQueen = true;
      return true;
   }
   castleQueen = false;
   return false;
}

/***************************************************
 * : LESS THAN: Operate less then on move
 * Input: rhs: Move
 * Output: type: bool
 ***************************************************/
bool Move::operator < (const Move &rhs) const
{
    // First compare source locations
    if (this->source.getLocation() < rhs.source.getLocation()) {
        return true;
    }
    if (this->source.getLocation() > rhs.source.getLocation()) {
        return false;
    }
    // If source locations are equal, compare destination locations
    return this->dest.getLocation() < rhs.dest.getLocation();
}


/***************************************************
 * COMPARE: Operate equal to on move
 * Input: rhs: Move
 * Output: type: bool
 ***************************************************/
bool Move::operator == (const Move &rhs) const
{
   return (this->source.getLocation() == rhs.getFrom().getLocation()) &&
          (this->dest.getLocation() == rhs.getTo().getLocation()) &&
          (this->text == rhs.text) &&
          (this->capture == rhs.capture) &&
          (this->moveType == rhs.moveType);
}

/***************************************************
 * GET TEXT: get Smith Notation from necessary member variables in Move
 * Input: source, dest, moveType, capture
 * Output: type: string
 ***************************************************/
const string Move::getText()
{
   if (this->source.isValid() && this->dest.isValid())
   {
      char fifth = '_';
      string sCR = source.getText();
      string dCR = dest.getText();
      
      switch (capture)
      {
         case PAWN:
            if (enPassant)
               fifth = 'E';
            fifth = 'p';
            break;
         case ROOK:
            fifth = 'r';
            break;
         case KNIGHT:
            fifth = 'n';
            break;
         case BISHOP:
            fifth = 'b';
            break;
         case QUEEN:
            fifth = 'q';
            break;
         case KING:
            fifth = 'k';
            break;
         case SPACE:
            if (castleKing)
               fifth = 'c';
            if (castleQueen)
               fifth = 'C';
            break;
         default:
               break;
      }
      return fifth == '_' ? (sCR + dCR) :( sCR + dCR + fifth);
   }
   
   return "";
}





/***************************************************
 * STUB MOVE CONSTRUCT
 **************************************************/

/***************************************************
 * STUB MOVE CONSTRUCT LETTER FROM PIECE TYPE: Construct  piece type to letter
 * Input: pieceType: string
 * Output: void
 ***************************************************/
char StubMoveConstruct::letterFromPieceType(PieceType pt) const
{
   if (pt == PAWN)
      return  'p';
   else if (pt == ROOK)
      return  'r';
   else if (pt == KNIGHT)
      return 'n';
   else if (pt == BISHOP)
      return 'b';
   else if (pt == QUEEN)
      return 'q';
   else if (pt == KING)
      return 'k';
   else
      return ' ';
}

/***************************************************
 * STUB MOVE CONSTRUCT PIECE TYPE FROM LETTER: Construct letter to piece type
 * Input: letterType: char
 * Output: void
 ***************************************************/
PieceType StubMoveConstruct::PieceTypeFromLetter(char letter) const
{
   if (letter == 'p')
      return  PAWN;
   else if (letter == 'r')
      return  ROOK;
   else if (letter == 'n')
      return  KNIGHT;
   else if (letter == 'b')
      return  BISHOP;
   else if (letter == 'q')
      return  QUEEN;
   else if (letter == 'k')
      return  KING;
   else
      return  SPACE;
}





/***************************************************
 * STUB MOVE COMPARE
 **************************************************/

/***************************************************
 * STUB MOVE COMPARE: Operate less then on move
 * Input: rhs: Move
 * Output: type: bool
 ***************************************************/
bool StubMoveCompare::operator < (StubMoveCompare &rhs)
{
   return abs(this->source.getLocation() - this->dest.getLocation()) <
          abs(rhs.getFrom().getLocation() - rhs.getTo().getLocation());
}

/***************************************************
 * STUB MOVE COMPARE: Operate less then on move
 * Input: rhs: Move
 * Output: type: bool
 ***************************************************/
bool StubMoveCompare::operator == (StubMoveCompare &rhs)
{
   return (this->source.getLocation() == rhs.getFrom().getLocation()) &&
          (this->dest.getLocation() == rhs.getTo().getLocation());
}





/***************************************************
 * STUB MOVE SIMPLE MOVE
 ***************************************************/

/***************************************************
 * STUB MOVE SIMPLE MOVE READ AND ASSIGN: Read a single move as string
 * Input: source, dest, moveType, capture
 * Output: type: string
 ***************************************************/
int StubMoveSimpleMove::readAndAssign(string move)
{
   // Assign source and destination from Smith Notation
   source = move.substr(0, 2);
   dest = move.substr(2, 2);
   setMoveType(move);
   
   return 0;
}

/***************************************************
 * STUB MOVE SIMPLE MOVE SET MOVE TYPE
 * Input: move: string
 * Output: void
 ***************************************************/
void StubMoveSimpleMove::setMoveType(string move)
{
      moveType = Move::MOVE;
}

/***************************************************
 * STUB MOVE SIMPLE MOVE GET TEXT:
 *    get Smith Notation from necessary member variables in Move
 * Input: source, dest, moveType, capture
 * Output: type: string
 ***************************************************/
const string StubMoveSimpleMove::getText()
{
   if (this->source.isValid() && this->dest.isValid())
   {
      char fifth = '_';
      string sCR = source.getText();
      string dCR = dest.getText();
      
      switch (capture)
      {
         case PAWN:
            if (moveType == ENPASSANT)
            {
               fifth = 'E';
               break;
            }
            fifth = 'p';
            break;
         case ROOK:
            fifth = 'r';
            break;
         case KNIGHT:
            fifth = 'n';
            break;
         case BISHOP:
            fifth = 'b';
            break;
         case QUEEN:
            fifth = 'q';
            break;
         case KING:
            fifth = 'k';
            break;
         case SPACE:
            if (moveType == CASTLE_KING)
            {
               fifth = 'c';
               break;
            }
            if (moveType == CASTLE_QUEEN)
            {
               fifth = 'C';
               break;
            }
            break;
         default:
               break;
      }
      return fifth == '_' ? (sCR + dCR) : (sCR + dCR + fifth);
   }
   
   return "";
}




/***************************************************
 * STUB MOVE ADVANCED MOVE
 ***************************************************/

/***************************************************
 * STUB ADVANCED MOVE READ AND ASSIGN: Read a single move as string
 * Input: move: string
 * Output: type: int
 ***************************************************/
int StubMoveAdvancedMove::readAndAssign(string move)
{
   // Assign source and destination from Smith Notation
   this->source = move.substr(0, 2);
   this->dest = move.substr(2, 2);
   
   setMoveType(move);
   if (isEnPassant(move))
      this->capture = PAWN;
   else
      setCapturedPieceType(move);
   
   return 0;
}

/***************************************************
 * STUB ADVANCED MOVE GET MOVE TYPE: Determine the move type
 * Input: move: string
 * Output: type: void
 ***************************************************/
void StubMoveAdvancedMove::setMoveType(string move)
{
   if (isCastleKing(move))
      moveType = CASTLE_KING;
   else if (isCastleQueen(move))
       moveType =  CASTLE_QUEEN;
   else if (isEnPassant(move))
      moveType = ENPASSANT;
   else if ((move[0] - 'a') * 8 + move[1] - '1' > 64 || (move[0] - 97) * 8 + move[1] - '1' < 1 ||
            (move[2] - 'a') * 8 + move[3] - '1' > 64 || (move[2] - 97) * 8 + move[3] - '1' < 1)
      moveType = MOVE_ERROR;
   else
      moveType = MOVE;
}

/***************************************************
 * STUB ADVANCED MOVE GET CAPTURED PIECE TYPE: Determine the move type
 * Input: move: string
 * Output: type: int
 ***************************************************/
void StubMoveAdvancedMove::setCapturedPieceType(string move)
{
   
   if (move.length() < 5)
   {
      if (move.length() < 4)
         capture = INVALID;
      else
         capture = SPACE;
   }
   else
      switch (tolower(move[4]))
      {
          case 'p':
            capture = PAWN;
            break;
          case 'k':
            capture = KING;
            break;
          case 'q':
            capture = QUEEN;
            break;
          case 'r':
            capture = ROOK;
            break;
          case 'b':
            capture = BISHOP;
            break;
          case 'n':
            capture = KNIGHT;
            break;
         case 'e':        // if En-Passant
            capture = PAWN;
            break;
         case 'c':        // if King side castle, no capture
            capture = SPACE;
            break;
         default:
            capture = INVALID;
            break;
      }
   
}

/***************************************************
 * IS EN PASSANT: Determine if an En-Passant happens
 * Input: move: string
 * Output: type: bool
 ***************************************************/
bool StubMoveAdvancedMove::isEnPassant(string move)
{
   if (move.length() > 4)
      return move[4] == 'E';
   return false;
}

/***************************************************
 * IS CASTLING KING: Determine if a castle is performed
 * Input: move: string
 * Output: type: bool
 ***************************************************/
bool StubMoveAdvancedMove::isCastleKing(string move)
{
   
//   if (pKing->pos.getText() == "e1" && pKing->fWhite == true &&
//      (pKing + sizeof(pKing) * 3)->pos.getText() == "h1" && (pKing + sizeof(pKing) * 3)->fWhite == true)
//      if ((pKing + sizeof(pKing))->pos.getText() == " " || (pKing + sizeof(pKing) * 2)->pos.getText() == " ")
//         return false;
//   return true;
   if (move.substr(0, 2) == "e1" && move.substr(2, 2) == "g1" && move[4] == 'c')
      return true;
   return false;
}

/***************************************************
 * IS CASTLING Queen: Determine if a castle is performed
 * Input: move: string
 * Output: type: bool
 ***************************************************/
bool StubMoveAdvancedMove::isCastleQueen(string move)
{
   
//   if (pKing->pos.getText() == "e1" && pKing->fWhite == true &&
//      (pKing + sizeof(pKing) * 3)->pos.getText() == "h1" && (pKing + sizeof(pKing) * 3)->fWhite == true)
//      if ((pKing + sizeof(pKing))->pos.getText() == " " || (pKing + sizeof(pKing) * 2)->pos.getText() == " ")
//         return false;
//   return true;
   if (move.substr(0, 2) == "e1" && move.substr(2, 2) == "c1" && move[4] == 'C')
      return true;
   return false;
}

/***************************************************
 * STUB MOVE ADVANCED MOVE GET TEXT:
 *    get Smith Notation from necessary member variables in Move
 * Input: source, dest, moveType, capture
 * Output: type: string
 ***************************************************/
const string StubMoveAdvancedMove::getText()
{
   if (this->source.isValid() && this->dest.isValid())
   {
      char fifth = '_';
      string sCR = source.getText();
      string dCR = dest.getText();
      
      switch (capture)
      {
         case PAWN:
            if (moveType == ENPASSANT)
            {
               fifth = 'E';
               break;
            }
            fifth = 'p';
            break;
         case ROOK:
            fifth = 'r';
            break;
         case KNIGHT:
            fifth = 'n';
            break;
         case BISHOP:
            fifth = 'b';
            break;
         case QUEEN:
            fifth = 'q';
            break;
         case KING:
            fifth = 'k';
            break;
         case SPACE:
            if (moveType == CASTLE_KING)
            {
               fifth = 'c';
               break;
            }
            if (moveType == CASTLE_QUEEN)
            {
               fifth = 'C';
               break;
            }
            break;
         default:
               break;
      }
      return fifth == '_' ? (sCR + dCR) : (sCR + dCR + fifth);
   }
   
   return "";
}



