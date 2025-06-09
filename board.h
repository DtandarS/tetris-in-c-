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


void Board::InitBoard () {

  for( int i = 0; i < BOARD_WIDTH; i++){
    for( int j = 0; j < BOARD_HEIGHT; j++){

      mBoard[i][j] = POS_FREE
    }
  }
};


void Board::storePiece (int positionX, int positionY, int PieceToDraw, int PossibleRotations){

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
};

/* check whether there is a code over the first line */

void Board::gameOver(){

  for ( int i = 0; i < BOARD_WIDTH; i++){

    if( mBoard[i][0] == POS_FILLED )
      return true;

  }

  return false;

};


/* Function for line deletion */

void Board::deleteLine( int positionY ){

  for ( int j = positionY; j > 0; j- ){

    for ( int i = 0; i < BOARD_WIDTH; i++ ){

      mBoard[i][j] = mBoard[i][j-1]

    }

  }

}


/* Method that deletes possible lines by checking the completed rows */

void Board::deletePossibleLines (){

  for ( int j = 0; j < BOARD_HEIGHT; j++ ){

    int i = 0;
    while ( i < BOARD_HEIGHT ){

      if ( mBoard[i][j] !=POS_FILLED ) break;
      i++;

    }

    if ( i == BOARD_WIDTH ) deleteLine(j);

  }
  
}


/* checks whether the block out of board filled or not */

bool Board::isFreeBlock(int positionX, int positionY){

  if ( mBoard[positionX][positionY]==POS_FREE ) 
    return true;
  else
    return false;

}


int Board::GetPositionInPixelX(int Position){

  return ( (BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (Position * BLOCK_SIZE) );
  
}


int Board::GetPositionInPixelY(int Position){

  return ( mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT) + ( Position * BLOCK_SIZE) );
  
}


bool Board::isPossibleMovement(int positionX, int positionY, int PieceToDraw, int PossibleRotations){

  for ( int i1 = positionX, i2 = 0; j1 < positionX + PIECE_BLOCK; i1++, i2++ ){

    for ( int j1 = positionY, j2 = 0; j1 < positionY + PIECE_BLOCK; j1++, j2++ ){
      if ( i1 < 0 || 
          i1 > BOARD_WIDTH - 1 || 
          j1 > BOARD_WIDTH - 1){
        if (mPieces -> GetBlockType(PieceToDraw, PossibleRotations, j2, i2) !=0) 
          return 0;
      }
      if ( j1 >= 0 ){
        if ((mPieces->GetBlockType (PieceToDraw, PossibleRotations, j2, i2) != 0) &&
            (!isFreeBlock (i1, j1)) )
          return false;
      }
    }
  }

  return true;

}










