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

void Game::DrawBoard (){

  int mX1 = BOARD_POSITION - ( BLOCK_SIZE * ( BOARD_WIDTH / 2 ) ) - 1;
  int mX2 = BOARD_POSITION + ( BLOCK_SIZE * ( BOARD_WIDTH / 2 ) );
  int mY = mScreenHeight - ( BLOCK_SIZE * BOARD_HEIGHT );
  
  // assert ( mY > MIN_VERTICAL_MARGIN )

  mIO -> DrawRectangle ( mX1 - BOARD_LINE__WIDTH, mY, mX1, mScreenHeight - 1, BLUE ); 

  mIO -> DrawRectangle ( mX2 , mY, mX2 + BOARD_LINE__WIDTH, mScreenHeight - 1, BLUE ); 

  // assert ( mX1 > MIN_HORIZONTAL_MARGIN );
  
  mX1 += 1;

  for (int i = 0; i < BOARD_WIDTH; i++){
    for( int j = 0; j < BOARD_HEIGHT; j++ ){

      if (!mBoard -> IsFreeBlock(i, j))
        mIO -> DrawRectangle (mX1 + i * BLOCK_SIZE, mY + j * BLOCK_SIZE, (mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1, ( mY + j * BLOCK_SIZE ) + BLOCK_SIZE - 1, RED);

    }
  }
}






























