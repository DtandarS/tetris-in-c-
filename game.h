/* Defining the game main game page */
#ifndef _GAME_
#define _GAME_


#include "board.h"
#include "pieces.h"
#include "IO.h"
#include <time.h>

#define WAIT_TIME 700;

/* classes */

class Game(){

  public:
    Game(Board * pBoard, Pieces * PieceToDraw, IO * pIO, int screenHeight);

    void drawScene();
    void CreatePieces();


    int mPosX, mPosY;
    int mPiece, mRotation;

  private:

    int mScreenHeight;
    int mNextPosX, mNextPosY;
    int mNextPiece, mNextRotation; 

  Board *mBoard;
  Pieces *mPieces;
  IO *mIO;

  int getRand(int pA, pB);
  void InitGame();
  int drawPieces(int positionX, int positionY, int PieceToDraw, int PossibleRotations);
  int DrawBoard();

};

#endif

int Game::getRand(int pA, pB){

  return rand () % (pB - pA + 1) + pA;

}


int Game::InitGame(){

  srand ((unsigned int) time(NULL));

  // First block
  mPiece = getRand(0,6);
  mRotation = getRand(0,3);
  mPosX = (BOARD_WIDTH / 2) + mPiece -> HorizontalInitalPositon (mPiece, mRotation);
  mPosY = mPiece -> VerticalInitalPositon (mPiece, mRotation);

  // Next block
  mPiece = getRand(0,6);
  mRotation = getRand(0,3);
  mNexPosX = BOARD_WIDTH + 5;
  mNexPosY = 5;

}


int Game::CreateNewPiece(){

  //The new piece
  mPiece = mNextPiece;
  mRotation = mNextRotation;
  mPosX = (BOARD_WIDTH / 2) + mPiece -> HorizontalInitalPositon (mPiece, mRotation);
  mPosY = mPiece -> VerticalInitalPositon (mPiece, mRotation);

  // random pieces
  mNextPiece = getRand(0,6);
  mNextRotation = getRand(0,3);

}


int Game::drawPiece(int positionX, int positionY, int PieceToDraw, int PossibleRotations){

  color mColor;

  int mPixelsX = mBoard -> GetPositionInPixelX (positionX); 
  int mPixelsY = mBoard -> GetPositionInPixelY (positionY); 

  for (int i = 0; i < PIECE_BLOCKS; i++){
    for (int j = 0; j < PIECE_BLOCKS; j++){
      switch (mPieces -> GetBlockType(PieceToDraw, PossibleRotation, j, i)){
        case 1: mColor = GREEN; break; // for each block of the piece except the picot
        case 2: mColor = BLUE; break; // for the pivot

      }
      if (mPieces -> GetBlockType(PieceToDraw, PossibleRotation, j, i) != 0 ) 
        mIO -> DrawRectangle( mPixelsX i * BLOCK_SIZE, mPixelsY + j BLOCK_SIZE, (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1, ( mPixelsY + j * BLOCK_SIZE ) + BLOCK_SIZE - 1, mColor ); 
    }
  }
}































