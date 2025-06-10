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

}



































