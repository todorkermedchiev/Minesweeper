/**
*
* Solution to course project # 13
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Todor Kermedchiev
* @idnumber 0MI0600063
* @compiler GCC
*
* File with the main logic
*
*/
#ifndef __GENERAL_FUNCTIONS
#define __GENERAL_FUNCTIONS
#include "constants.h"
#include "boardFunctions.h"
#include <cstdlib> // Needed for srand() ans rand() functions
#include <time.h> // Needed for time() function

using namespace std;

void generateMines(bool minesBoard[][BOARD_SIZE], int minesCoordinates[MINES_COUNT] = {})
{
    bool isValidPosition = true;
    unsigned int position = 0;
    unsigned int index = 0;
    int row = 0;
    int column = 0;
    srand(time(NULL)); // The random numbers are different each time the program is started (at different time)

    while (index < MINES_COUNT) {
        position = rand() % 100; // Generating random number between 0 and 99;
        // This number indicates the coordinates of the mine
        // The first digit is the row and the second is the column, so the number must be between 11 and 99
        isValidPosition = position >= 11 && position <= 99 && position % 10 != 0;

        for (int j = 0; j < MINES_COUNT && isValidPosition; ++j) {
            if (position == minesCoordinates[j]) {
                // There is a repeating number
                isValidPosition = false;
            }
        }

        if (isValidPosition) {
            minesCoordinates[index] = position;
            ++index;
        }
    }

    for (int i = 0; i < MINES_COUNT; ++i) {
        row = minesCoordinates[i] / 10;
        column = minesCoordinates[i] % 10;
        minesBoard[row][column] = true;
    }
}

// The function returns true when the player hit a mine
bool show(int row,
          int column,
          char board[][BOARD_SIZE],
          bool minesBoard[][BOARD_SIZE],
          int minesCoordinates[MINES_COUNT]) {
    int nearbyMinesCount = 0;
    if (minesBoard[row][column]) { // This is a mine
        // Finding the other mines
        for (int i = 0; i < MINES_COUNT; ++i) {
            row = minesCoordinates[i] / 10;
            column = minesCoordinates[i] % 10;
            board[row][column] = 'X';
        }
        return true;
    }

    // Finding the number of the surrounding mines
    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = column - 1; j <= column + 1; ++j) {
            if (minesBoard[i][j]) {
                ++nearbyMinesCount;
            }
        }
    }

    board[row][column] = nearbyMinesCount + '0';
    return false; // The function return false, when this is not a mine
}

void mark(int row,
          int column,
          char board[][BOARD_SIZE],
          int minesCoordinates[MINES_COUNT],
          int &markedMines) {
    bool isMine = false;
    // Check if this position is marked, so it can be unmarked
    if (board[row][column] == '!') {
        board[row][column] = ' ';
        return;
    }

    // Marking
    board[row][column] = '!';

    // Checking if the marked position is mine
    for (int i = 0; i < MINES_COUNT; ++i) {
        if ((row * 10 + column) == minesCoordinates[i]) {
            isMine = true;
        }
    }

    if (isMine) {
        ++markedMines;
    }
}

#endif // __GENERAL_FUNCTIONS
