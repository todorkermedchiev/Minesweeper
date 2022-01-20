#ifndef BOARDFUNCTIONS
#define BOARDFUNCTIONS
#include "constants.h"
#include "../sources/boardFunctions.cpp"

void fillBoard(char [][BOARD_SIZE], char);
void fillPrintedBoard(char [][PRINTED_BOARD_COLS], char);
void makeBorders(char [][PRINTED_BOARD_COLS]);
void print(char [][BOARD_SIZE], char [][PRINTED_BOARD_COLS]);

#endif
