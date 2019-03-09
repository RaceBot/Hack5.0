#include <stdlib.h>
#include <stdio.h>

#include "gameUtils.h"

void freeBoard(Move **board) {

  for(int i=0; i<3; i++) {
    free(board[i]);
  }
  free(board);
  return;
}

Move ** copyBoard(Move **board) {

  Move **copy = newBoard();

  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      copy[i][j] = board[i][j];
    }
  }
  return board;
}

Move ** newBoard() {
  Move **board = (Move **) malloc(3 * sizeof(Move*));
  int i, j;
  for(i=0; i<3; i++) {
    board[i] = (Move *) malloc(3 * sizeof(Move));
    for(j=0; j<3; j++) {
      board[i][j] = NONE;
    }
  }
  return board;
}

void printBoard(Move **board) {

  printf("\n");
  int i, j;
  for(i=0; i<3; i++) {
    printf("  ");
    for(j=0; j<3; j++) {
      if(board[i][j] == X) {
        printf("  X  ");
      } else if(board[i][j] == O) {
        printf("  O  ");
      } else {
        printf(" (%d) ", (i*3+j+1) );
      }
      if(j < 2) {
        printf(" | ");
      }
    }
    printf("\n");
    if(i<2) {
      /**
       * Fixed 6.
       * Changed the loop to 2 from 3
       */
      printf("  ------+-------+------\n");
    }
  }
  printf("\n");

  return;
}

GameMode mainMenu() {

  int choice = 0;
  while(choice < 1 || choice > 3) {
    printf("Welcome to Tic-Tac-Toe!!\n");
    printf("========================\n");
    printf("Menu\n");
    printf("(1) 2-player game\n");
    printf("(2) 1-player game vs random computer\n");
    printf("(3) 1-player game vs smart computer\n");
    scanf("%d", &choice);
  }
  return choice;
}


Status getStatus(Move **board) {

  Status s = TIE;

  if( //rows
    /**
     * Fixed 4.
     * The board matrix number were not correct
     * and I fixed to 0,1 AND 0,2.
     */
      (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == X) ||
      (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == X) ||
      (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == X) ||
      //cols
      (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == X) ||
      (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == X) ||
      (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == X) ||
      //across
      (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == X) ||
      (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == X)  ) {
    s = X_WINS;
  } else if(
      //rows
      (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == O) ||
      (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == O) ||
      (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == O) ||
      //cols
      (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == O) ||
      (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == O) ||
      (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == O) ||
      //across
      (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == O) ||
      (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == O)  ) {
    s = O_WINS;
  } else {

    //if there are any unplayed squares, keep playing
    int i, j;
    for(i=0; i<3; i++) {
      for(j=0; j<3; j++) {
        /**
         * Fixed 1.
         * Originally, the condition for the board was set
         * equal to O and X, but in the beginning of the code
         * there is no O and X. Changed it to NONE
         */
        if(board[i][j] == NONE) {
          s = PLAYING;
        }
      }
    }
  }
  return s;
}
