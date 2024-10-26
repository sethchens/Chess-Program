/**********************************************************************
* Source File:
*    Lab 04: Chess
* Author:
*    Chris Mijangos and Seth Chen 
* Summary:
*    Play the game of chess
************************************************************************/


#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for OGSTREAM
#include "position.h"     // for POSITION
#include "piece.h"        // for PIECE and company
#include "board.h"        // for BOARD
#include "test.h"
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include <iostream>
#include <cstdlib>
using namespace std;


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void * p)
{
    Board* pBoard = (Board*)p;
    Position posSelect = pUI->getSelectPosition();
    Position posPrevious = pUI->getPreviousPosition();

    // If we have a valid selection
    if (posSelect.isValid())
    {
        // If this is our first click (no previous position)
        if (!posPrevious.isValid())
        {
            // Check if we're selecting our own piece
            const Piece& piece = (*pBoard)[posSelect];

            // If we select an empty space or opponent's piece, clear selection
            if (piece.getType() == SPACE || piece.isWhite() != pBoard->whiteTurn())
            {
                pUI->clearSelectPosition();
            }
            // Otherwise selection is valid and we keep it for the next click
        }
        // If this is our second click (we have a previous position)
        else
        {
            // Create the move
            Move move(posPrevious, posSelect);
            const Piece& sourcePiece = (*pBoard)[posPrevious];

            // Get valid moves for the selected piece
            set<Move> moves;
            sourcePiece.getMoves(moves, *pBoard);

            // Check if destination has an opponent's piece
            const Piece& destPiece = (*pBoard)[posSelect];
            if (destPiece.getType() != SPACE &&
                destPiece.isWhite() != sourcePiece.isWhite())
            {
                move.setCapture(destPiece.getType());
            }

            // Try to execute the move if it's valid
           if (moves.find(move) != moves.end())
           {
              pBoard->move(move);
              
              // To handle extra move for rook during castling
              if (((move.getFrom().getCol() ==  4 && move.getFrom().getRow() == 0) ||
                  (move.getFrom().getCol() ==  4 && move.getFrom().getRow() == 7)) &&
                  abs(move.getFrom().getCol() - move.getTo().getCol()) == 2)
              {
                 Move tempMove;
                 for (Move move : moves)
                 {
                    if ((move.getFrom().getCol() == 0 && move.getFrom().getRow() == 0 && move.getTo().getCol() == 3 && move.getTo().getRow() == 0) ||
                        (move.getFrom().getCol() == 7 && move.getFrom().getRow() == 0 && move.getTo().getCol() == 5 && move.getTo().getRow() == 0) ||
                        (move.getFrom().getCol() == 0 && move.getFrom().getRow() == 7 && move.getTo().getCol() == 3 && move.getTo().getRow() == 7) ||
                        (move.getFrom().getCol() == 7 && move.getFrom().getRow() == 7 && move.getTo().getCol() == 5 && move.getTo().getRow() == 0)
                        )
                       tempMove = move;
                 }
                 pBoard->move(tempMove);
              }
              
              // The board counts move even before that move is finished, so the reversed is the right turn
              if (pBoard->isChecked(moves, !pBoard->whiteTurn()))
              {
                 pBoard->undo(move);

              }
           }

            // Clear selection after move attempt
            pUI->clearSelectPosition();
        }
    }

    // Draw the board
    pBoard->display(pUI->getHoverPosition(), pUI->getSelectPosition());
}


/*********************************
 * MAIN - Where it all begins...
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   // run all the unit tests
   testRunner();
   
   // Instantiate the graphics window
   Interface ui("Chess");    

   // Initialize the game class
   ogstream* pgout = new ogstream;
   Board board(pgout);

   // set everything into action
   ui.run(callBack, (void *)(&board));
   
   // All done.
   delete pgout;
   return 0;
}
