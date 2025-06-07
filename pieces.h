
/* Definitions and other boring stuff */

#ifndef _PIECES_
#define _PIECES_

// ---------------
// PIECES
// ---------------

class Pieces {

  public: 
    int GetBlockType(int PieceToDraw, int PossibleRotations, int positioX, int positioY);
    int InitialPosX(int PieceToDraw, int PossibleRotations);
    int InitialPosY(int PieceToDraw, int PossibleRotations);

};

#endif // _PIECES_

/*
======================================
Return the type of a block (0 = no-block, 1 = normal block, 2 = pivot block)

Parameters:

>> PieceToDraw: Piece to draw
>> PossibleRotations: 1 of the 4 possible rotations
>> positionX: Horizontal position in blocks
>> positionY: Vertical position in blocks
======================================
*/

int Pieces::GetBlockType(int PieceToDraw, int PossibleRotations, int positioX, int positionY){

  return mPieces[PieceToDraw][PossibleRotations][positionX][positionY]; 

}

/*
======================================
Returns the horizontal displacement of the piece that has to be applied in order to create it in the
correct position.

Parameters:

>> PieceToDraw: Piece to draw
>> PossibleRotations: 1 of the 4 possible rotations
======================================
*/

int Pieces::HorizontalInitalPositon (int PieceToDraw, int PossibleRotations){

return PiecesInitialPosition [PieceToDraw][PossibleRotations][0];

}

/*
======================================
Returns the vertical displacement of the piece that has to be applied in order to create it in the
correct position.

Parameters:

>> PieceToDraw: Piece to draw
>> PossibleRotations: 1 of the 4 possible rotations
======================================
*/

int Pieces::VerticalInitalPosition ( int PieceToDraw, int PossibleRotations){ 

  return PiecesInitialPosition [PieceToDraw][PossibleRotations][1];

}






