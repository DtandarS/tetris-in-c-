/* Header of the shit that I have no idea what they do */

#ifndef _BOARD_
#define _BOARD_


/*we include self written shit that i still have no idea what the fuck they do but they look fucking cool*/

#include <pieces.h>


/* Defines */

#define BOARD_LINE_WIDTH 6 
#define BLOCK_SIZE 14
#define BOARD_POSITION 
#define BOARD_WIDTH 40
#define BOARD_HEIGHT 20
#define MIN_HORIZONTAL_MARGIN 10
#define MIN_VERTICAL_MARGIN 10
#define PIECE_BLOCK 5


/* A class that configures the functionalitites for blocks position and check collisions */

class Board {

  public: 
    Board (pieces *PieceToDraw, int ScreenHeight);


    int GetPositionInPixelX (int Position);
    int GetPositionInPixelY (int Position);
    bool isFreeBlock (int positionX, int positionY);
    bool isPossibleMovement (int positionX, int positionY, int PieceToDraw, int PossibleRotations);
    void storePiece (int positionX, int positionY, int PieceToDraw, int PossibleRotations);
    void deletePossibleLines ();
    bool gameOver ();

  private: 
    enum {POS_FREE, POS_FILLED} // POS_FREE frees out the position on the board, POS_FILLED fills out the position on the board
    int mBoard {BOARD_WIDTH, BOARD_HEIGHT}
    int mScreenHeight;

    void InitBoard();
    void deleteLine(positonY);

};

#endif


void BOARD::InitBoard () {

  for( int i = 0; i < BOARD_WIDTH; i++)
  for( int j = 0; j < BOARD_HEIGHT; j++)

    mBoard[i][j] = POS_FREE

};


void BOARD::storePiece (int positionX, int positionY, int PieceToDraw, int PossibleRotations){

  // Store each block of the piece into the board
  for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCK; i1++, i2++)
  {
    for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCK; j1++, j2++)
    {
      // Store only the blocks of the piece that are not holes
      if (mPieces->GetBlockType (PieceToDraw, PossibleRotations, j2, i2) != 0)
        mBoard[i1][j1] = POS_FILLED;
    }
  }
}







