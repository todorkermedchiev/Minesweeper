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
* File with functions which modify the board
*
*/
#ifndef __BOARD_FUNCTIONS
#define __BOARD_FUNCTIONS
#include "constants.h"

using namespace std;

void fillBoard(char board[BOARD_SIZE][BOARD_SIZE], char character = ' ')
{
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            board[row][column] = character;
        }
    }

    // Filling the first row, the last row, the first column and the last column with the numbers from 1 to 9
    for (int i = 1; i < BOARD_SIZE - 1; ++i) {
        board[0][i] = i + '0';
        board[i][0] = i + '0';
        board[10][i] = i + '0';
        board[i][10] = i + '0';
    }
}

void fillPrintedBoard(char board[PRINTED_BOARD_ROWS][PRINTED_BOARD_COLS], char character = ' ')
{
    for (int row = 0; row < PRINTED_BOARD_ROWS; ++row) {
        for (int column = 0; column < PRINTED_BOARD_COLS; ++column) {
            board[row][column] = character;
        }
    }
}

void makeBorders(char printedBoard[PRINTED_BOARD_ROWS][PRINTED_BOARD_COLS])
{
    fillPrintedBoard(printedBoard);

    for (int row = 0; row < PRINTED_BOARD_ROWS; ++row) {
        for (int column = 0; column < PRINTED_BOARD_COLS; ++column) {
            // Adding horizontal lines
            if (row % 2 == 0) {
                printedBoard[row][column] = (char) -51; // '═'
            }

            // Adding vertical lines
            if (column % 4 == 0) {
                printedBoard[row][column] = (char) -70; // '║'
            }

            if (row % 2 == 0 && column % 4 == 0) {
                // Adding corner characters between the cells
                printedBoard[row][column] = (char) -50; // '╬'

                switch (row) {
                case 0:
                    // Adding corner characters on the first row between the cells
                    printedBoard[row][column] = (char) -53; // '╦'
                    break;
                case PRINTED_BOARD_ROWS - 1:
                    // Adding corner characters on the last row between the cells
                    printedBoard[row][column] = (char) -54; // '╩'
                    break;
                }

                switch (column) {
                case 0:
                    // Adding corner characters on the first column between the cells
                    printedBoard[row][column] = (char) -52; // '╠'
                    break;
                case PRINTED_BOARD_COLS - 1:
                    // Adding corner characters on the last column between the cells
                    printedBoard[row][column] = (char) -71; // '╣'
                    break;
                }
            }
        }
    }

    // Adding corner characters
    printedBoard[0][0] = (char) -55; // '╔'
    printedBoard[0][PRINTED_BOARD_COLS - 1] = (char) -69; // '╗'
    printedBoard[PRINTED_BOARD_ROWS - 1][0] = (char) -56; // '╚'
    printedBoard[PRINTED_BOARD_ROWS - 1][PRINTED_BOARD_COLS - 1] = (char) -68; // '╝'

    // Used character set:
    // -69 = '╗'; -68 = '╝'; -56 = '╚'; -55 = '╔'; -51 = '═'; -70 = '║';
    // -50 = '╬'; -53 = '╦'; -54 = '╩'; -52 = '╠'; -71 = '╣';
}

#endif // __BOARD_FUNCTIONS
