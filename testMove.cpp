/***********************************************************************
 * Header File:
 *    TEST MOVE
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>

 /*************************************
  * Constructor : default
  * Input:
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default()
{
   // setup
   // exercise
   MoveDummy move;
   
   // verify
   assertEquals(move.source.isValid(), false);
   assertEquals(move.dest.isValid(), false);
   assertEquals(move.capture, SPACE);
   assertEquals(move.moveType, Move::MOVE_ERROR);
   assertEquals(move.isWhite, true);
   assertEquals(move.promote, PieceType::INVALID);
} // teardown

 /*************************************
  * CONSTRUCTOR : standard string move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::constructString_simple()
{
   // setup
   StubMoveSimpleMove move;
   
   // exercise
   move.readAndAssign("e5e6");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 4);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::MOVE);
} // teardown

 /*************************************
  * READ simple move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::read_simple()
{
   // setup
   StubMoveSimpleMove move;
   
   // exercise
   move.readAndAssign("e5e6");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 4);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::MOVE);
} // teardown

 /*************************************
  * READ capture move
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::read_capture()
{
   // setup
   StubMoveAdvancedMove move;
   
   // exercise
   move.readAndAssign("e5d6r");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 3);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::MOVE);
   assertEquals(move.capture, ROOK);
} // teardown

 /*************************************
  * READ enpassant move
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  *         capture =PAWN
  **************************************/
void TestMove::read_enpassant()
{
   // setup
   StubMoveAdvancedMove move;
   
   // exercise
   move.readAndAssign("e5f6E");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 5);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::ENPASSANT);
   assertEquals(move.capture, PAWN);
} // teardown

 /*************************************
  * READ king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::read_castleKing()
{
   // setup
   StubMoveAdvancedMove move;
   
   // exercise
   move.readAndAssign("e1g1c");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 0);
   assertEquals(move.dest.getCol(), 6);
   assertEquals(move.dest.getRow(), 0);
   assertEquals(move.moveType, Move::CASTLE_KING);
   assertEquals(move.capture, SPACE);
} // teardown

 /*************************************
  * READ queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::read_castleQueen()
{
   // setup
   StubMoveAdvancedMove move;
   
   // exercise
   move.readAndAssign("e1c1C");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 0);
   assertEquals(move.dest.getCol(), 2);
   assertEquals(move.dest.getRow(), 0);
   assertEquals(move.moveType, Move::CASTLE_QUEEN);
   assertEquals(move.capture, SPACE);
} // teardown

 /*************************************
  * ASSIGN simple move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::assign_simple()
{
   // setup
   StubMoveSimpleMove move;
   
   // exercise
   move.readAndAssign("e5e6");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 4);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::MOVE);
} // teardown

 /*************************************
  * ASSIGN capture move
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::assign_capture()
{
   // setup
   StubMoveAdvancedMove move;
   
   // exercise
   move.readAndAssign("e5d6r");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 3);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::MOVE);
   assertEquals(move.capture, ROOK);
} // teardown

 /*************************************
  * ASSIGN enpassant move
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::assign_enpassant()
{
   // setup
   StubMoveAdvancedMove move;
   
   // exercise
   move.readAndAssign("e5f6E");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 5);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::ENPASSANT);
   assertEquals(move.capture, PAWN);
} // teardown

 /*************************************
  * ASSIGN king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::assign_castleKing()
{
   // setup
   StubMoveAdvancedMove move;
   
   // exercise
   move.readAndAssign("e1g1c");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 0);
   assertEquals(move.dest.getCol(), 6);
   assertEquals(move.dest.getRow(), 0);
   assertEquals(move.moveType, Move::CASTLE_KING);
   assertEquals(move.capture, SPACE);
} // teardown

 /*************************************
  * ASSIGN queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::assign_castleQueen()
{
   // setup
   StubMoveAdvancedMove move;
   
   // exercise
   move.readAndAssign("e1c1C");
   
   //verify
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 0);
   assertEquals(move.dest.getCol(), 2);
   assertEquals(move.dest.getRow(), 0);
   assertEquals(move.moveType, Move::CASTLE_QUEEN);
   assertEquals(move.capture, SPACE);
} // teardown

 /*************************************
  * GET TEXT simple move
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  * Output:  e5e6
  **************************************/
void TestMove::getText_simple()
{
   // setup
   StubMoveSimpleMove move;
   move.source.set(4, 4);
   move.dest.set(4, 5);
   move.moveType = Move::MOVE;
   string text;
   
   // exercise
   text = move.getText();
   
   // verify
   assertUnit(text == "e5e6");
} // teardown

 /*************************************
  * GET TEXT capture
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  *         capture=ROOK
  * Output:  e5e6r
  **************************************/
void TestMove::getText_capture()
{
   // setup
   StubMoveAdvancedMove move;
   move.source.set(4, 4);
   move.dest.set(4, 5);
   move.moveType = Move::MOVE;
   move.capture = ROOK;
   string text;
   
   // exercise
   text = move.getText();
   
   // verify
   assertUnit(text == "e5e6r");
} // teardown

 /*************************************
  * GET TEXT en passant
  * Input : source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  *         capture=PAWN
  * Output:  e5f6E
  **************************************/
void TestMove::getText_enpassant()
{
   // setup
   StubMoveAdvancedMove move;
   move.source.set(4, 4);
   move.dest.set(5, 5);
   move.moveType = Move::ENPASSANT;
   move.capture = PAWN;
   string text;
   
   // exercise
   text = move.getText();
   
   // verify
   assertUnit(text == "e5f6E");
} // teardown

 /*************************************
  * GET TEXT king side castle
  * Input : source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  * Output:  e1g1c
  **************************************/
void TestMove::getText_castleKing()
{
   // setup
   StubMoveAdvancedMove move;
   move.source.set(4, 0);
   move.dest.set(6, 0);
   move.moveType = Move::CASTLE_KING;
   string text;
   
   // exercise
   text = move.getText();
   
   // verify
   assertUnit(text == "e1g1c");
} // teardown

 /*************************************
  * GET TEXT queen side castle
  * Input : source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  * Output:  e1c1C
  **************************************/
void TestMove::getText_castleQueen()
{
   // setup
   StubMoveAdvancedMove move;
   move.source.set(4, 0);
   move.dest.set(2, 0);
   move.moveType = Move::CASTLE_QUEEN;
   string text;
   
   // exercise
   text = move.getText();
   
   // verify
   assertUnit(text == "e1c1C");
} // teardown

 /*************************************
  * LETTER FROM PIECE TYPE space
  * Input :  SPACE
  * Output:  ' '
  **************************************/
void TestMove::letterFromPieceType_space()
{
   // setup
   StubMoveConstruct move;
   char letter = '_';
   PieceType pt = INVALID;
   
   // exercise
   letter = move.letterFromPieceType(pt);
   
   // verify
   assertEquals(letter, ' ');
   assertEquals(pt, INVALID);
} // teardown

 /*************************************
  * LETTER FROM PIECE TYPE pawn
  * Input : PAWN
  * Output:  'p'
  **************************************/
void TestMove::letterFromPieceType_pawn()
{
   // setup
   StubMoveConstruct move;
   char letter = '_';
   PieceType pt = PAWN;
   
   // exercise
   letter = move.letterFromPieceType(pt);
   
   // verify
   assertEquals(letter, 'p');
   assertEquals(pt, PAWN);
} // teardown

 /*************************************
  * LETTER FROM PIECE TYPE bishop
  * Input : BISHOP
  * Output:  'b'
  **************************************/
void TestMove::letterFromPieceType_bishop()
{
   // setup
   StubMoveConstruct move;
   char letter = '_';
   PieceType pt = BISHOP;
   
   // exercise
   letter = move.letterFromPieceType(pt);
   
   // verify
   assertEquals(letter, 'b');
   assertEquals(pt, BISHOP);
} // teardown

 /*************************************
  * LETTER FROM PIECE TYPE knight
  * Input : KNIGHT
  * Output:  'n'
  **************************************/
void TestMove::letterFromPieceType_knight()
{
   // setup
   StubMoveConstruct move;
   char letter = '_';
   PieceType pt = KNIGHT;
   
   // exercise
   letter = move.letterFromPieceType(pt);
   
   // verify
   assertEquals(letter, 'n');
   assertEquals(pt, KNIGHT);
} // teardown

 /*************************************
  * LETTER FROM PIECE TYPE rook
  * Input : ROOK
  * Output:  'r'
  **************************************/
void TestMove::letterFromPieceType_rook()
{
   // setup
   StubMoveConstruct move;
   char letter = '_';
   PieceType pt = ROOK;
   
   // exercise
   letter = move.letterFromPieceType(pt);
   
   // verify
   assertEquals(letter, 'r');
   assertEquals(pt, ROOK);
} // teardown

 /*************************************
  * LETTER FROM PIECE TYPE queen
  * Input : QUEEN
  * Output:  'q'
  **************************************/
void TestMove::letterFromPieceType_queen()
{
   // setup
   StubMoveConstruct move;
   char letter = '_';
   PieceType pt = QUEEN;
   
   // exercise
   letter = move.letterFromPieceType(pt);
   
   // verify
   assertEquals(letter, 'q');
   assertEquals(pt, QUEEN);
} // teardown

 /*************************************
  * LETTER FROM PIECE TYPE king
  * Input : KING
  * Output:  'k'
  **************************************/
void TestMove::letterFromPieceType_king()
{
   // setup
   StubMoveConstruct move;
   char letter = '_';
   PieceType pt = KING;
   
   // exercise
   letter = move.letterFromPieceType(pt);
   
   // verify
   assertEquals(letter, 'k');
   assertEquals(pt, KING);
} // teardown

 /*************************************
  * PIECE TYPE FROM LETTER pawn
  * Input : 'p'
  * Output:  PAWN
  **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   // setup
   StubMoveConstruct move;
   char letter = 'p';
   PieceType pt = INVALID;
   
   // exercise
   pt = move.PieceTypeFromLetter(letter);
   
   // verify
   assertEquals(letter, 'p');
   assertEquals(pt, PAWN);
} // teardown

 /*************************************
  * PIECE TYPE FROM LETTER bishop
  * Input : 'b'
  * Output:  BISHOP
  **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   // setup
   StubMoveConstruct move;
   char letter = 'b';
   PieceType pt = INVALID;
   
   // exercise
   pt = move.PieceTypeFromLetter(letter);
   
   // verify
   assertEquals(letter, 'b');
   assertEquals(pt, BISHOP);
} // teardown

 /*************************************
  * PIECE TYPE FROM LETTER knight
  * Input : 'n'
  * Output:  KNIGHT
  **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   // setup
   StubMoveConstruct move;
   char letter = 'n';
   PieceType pt = INVALID;
   
   // exercise
   pt = move.PieceTypeFromLetter(letter);
   
   // verify
   assertEquals(letter, 'n');
   assertEquals(pt, KNIGHT);
} // teardown

 /*************************************
  * PIECE TYPE FROM LETTER rook
  * Input : 'r'
  * Output:  ROOK
  **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   // setup
   StubMoveConstruct move;
   char letter = 'r';
   PieceType pt = INVALID;
   
   // exercise
   pt = move.PieceTypeFromLetter(letter);
   
   // verify
   assertEquals(letter, 'r');
   assertEquals(pt, ROOK);
} // teardown

 /*************************************
  * PIECE TYPE FROM LETTER queen
  * Input : 'q'
  * Output:  QUEEN
  **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   // setup
   StubMoveConstruct move;
   char letter = 'q';
   PieceType pt = INVALID;
   
   // exercise
   pt = move.PieceTypeFromLetter(letter);
   
   // verify
   assertEquals(letter, 'q');
   assertEquals(pt, QUEEN);
} // teardown

 /*************************************
  * PIECE TYPE FROM LETTER king
  * Input : 'k'
  * Output:  KING
  **************************************/
void TestMove::pieceTypeFromLetter_king()
{
   // setup
   StubMoveConstruct move;
   char letter = 'k';
   PieceType pt = INVALID;
   
   // exercise
   pt = move.PieceTypeFromLetter(letter);
   
   // verify
   assertEquals(letter, 'k');
   assertEquals(pt, KING);
} // teardown


// /*************************************
//  * EQUAL - NOT
//  * Input : b2b4 == b2b5
//  * Output: false
//  **************************************/
//void TestMove::equal_not()
//{
//   // setup
//   StubMoveCompare move1;
//   StubMoveCompare move2;
//   
//   move1.source.setFromText("b2");
//   move1.dest.setFromText("b4");
//   move2.source.setFromText("b2");
//   move2.dest.setFromText("b5");
//   
//   // exercise
//   bool equal = move1 == move2;
//   
//   // verify
//   assertEquals(move1.source.getCol(), 1);
//   assertEquals(move1.source.getRow(), 1);
//   assertEquals(move1.dest.getCol(), 1);
//   assertEquals(move1.dest.getRow(), 3);
//   assertEquals(move2.source.getCol(), 1);
//   assertEquals(move2.source.getRow(), 1);
//   assertEquals(move2.dest.getCol(), 1);
//   assertEquals(move2.dest.getRow(), 4);
//   assertEquals(equal, false);
//} // teardown
//
// /*************************************
//  * EQUAL - EQUALS
//  * Input : b2b4 == b2b4
//  * Output: true
//  **************************************/
//void TestMove::equal_equals()
//{
//   // setup
//   StubMoveCompare move1;
//   StubMoveCompare move2;
//   
//   move1.source.setFromText("b2");
//   move1.dest.setFromText("b4");
//   move2.source.setFromText("b2");
//   move2.dest.setFromText("b4");
//   
//   // exercise
//   bool equal = move1 == move2;
//   
//   // verify
//   assertEquals(move1.source.getCol(), 1);
//   assertEquals(move1.source.getRow(), 1);
//   assertEquals(move1.dest.getCol(), 1);
//   assertEquals(move1.dest.getRow(), 3);
//   assertEquals(move2.source.getCol(), 1);
//   assertEquals(move2.source.getRow(), 1);
//   assertEquals(move2.dest.getCol(), 1);
//   assertEquals(move2.dest.getRow(), 3);
//   assertEquals(equal, true);
//} // teardown
//
// /*************************************
//  * LESS THAN - LESS THAN
//  * Input : b2b2 < b2b4
//  * Output: true
//  **************************************/
//void TestMove::lessthan_lessthan()
//{
//   // setup
//   StubMoveCompare move1;
//   StubMoveCompare move2;
//   
//   move1.source.setFromText("b2");
//   move1.dest.setFromText("b2");
//   move2.source.setFromText("b2");
//   move2.dest.setFromText("b4");
//   
//   // exercise
//   bool isLess = move1 < move2;
//   
//   // verify
//   assertEquals(move1.source.getCol(), 1);
//   assertEquals(move1.source.getRow(), 1);
//   assertEquals(move1.dest.getCol(), 1);
//   assertEquals(move1.dest.getRow(), 1);
//   assertEquals(move2.source.getCol(), 1);
//   assertEquals(move2.source.getRow(), 1);
//   assertEquals(move2.dest.getCol(), 1);
//   assertEquals(move2.dest.getRow(), 3);
//   assertEquals(isLess, true);
//} // teardown
//
// /*************************************
//  * LESS THAN - EQUALS
//  * Input : b2b4 < b2b4
//  * Output: false
//  **************************************/
//void TestMove::lessthan_equals()
//{
//   // setup
//   StubMoveCompare move1;
//   StubMoveCompare move2;
//   
//   move1.source.setFromText("b2");
//   move1.dest.setFromText("b4");
//   move2.source.setFromText("b2");
//   move2.dest.setFromText("b4");
//   
//   // exercise
//   bool isLess = move1 < move2;
//   
//   // verify
//   assertEquals(move1.source.getCol(), 1);
//   assertEquals(move1.source.getRow(), 1);
//   assertEquals(move1.dest.getCol(), 1);
//   assertEquals(move1.dest.getRow(), 3);
//   assertEquals(move2.source.getCol(), 1);
//   assertEquals(move2.source.getRow(), 1);
//   assertEquals(move2.dest.getCol(), 1);
//   assertEquals(move2.dest.getRow(), 3);
//   assertEquals(isLess, false);
//} // teardown
//
// /*************************************
//  * LESS THAN - GREATAER THAN
//  * Input : b2b4 < b2b2
//  * Output: false
//  **************************************/
//void TestMove::lessthan_greaterthan()
//{
//   // setup
//   StubMoveCompare move1;
//   StubMoveCompare move2;
//   
//   move1.source.setFromText("b2");
//   move1.dest.setFromText("b4");
//   move2.source.setFromText("b2");
//   move2.dest.setFromText("b4");
//   
//   // exercise
//   bool isLess = move1 < move2;
//   
//   // verify
//   assertEquals(move1.source.getCol(), 1);
//   assertEquals(move1.source.getRow(), 1);
//   assertEquals(move1.dest.getCol(), 1);
//   assertEquals(move1.dest.getRow(), 3);
//   assertEquals(move2.source.getCol(), 1);
//   assertEquals(move2.source.getRow(), 1);
//   assertEquals(move2.dest.getCol(), 1);
//   assertEquals(move2.dest.getRow(), 3);
//   assertEquals(isLess, false);
//} // teardown
