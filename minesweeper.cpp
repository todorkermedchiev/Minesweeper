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
* File with main() function
*
*/
#include <iostream>
#include "headers/constants.h"
#include "headers/boardFunctions.h"
#include "headers/generalFunctions.h"
#include "headers/inputOutputFunctions.h"

int main()
{
    int row = 0, column = 0;
    char command;

    // Matrix with the characters
    char board[BOARD_SIZE][BOARD_SIZE] = {};
    fillBoard(board);

    // Matrix and array with the mines
    bool minesBoard[BOARD_SIZE][BOARD_SIZE] = {};
    int minesCoordinates[MINES_COUNT] = {};
    generateMines(minesBoard, minesCoordinates);

    // Matrix, which will be printed (with borders)
    char printedBoard[PRINTED_BOARD_ROWS][PRINTED_BOARD_COLS];
    makeBorders(printedBoard);

    int markedMines = 0;
    int markedCells = 0;

    while (true) {
        print(board, printedBoard);

        // Input
        input(row, column, command, board);

        if (command == 's') { // show
            if (show(row, column, board, minesBoard, minesCoordinates)) {
                // The function returned true, so the player hit a mine
                print(board, printedBoard);
                cout << "_ _ _ Game Over! _ _ _" << endl;
                break;
            }
        }
        else if (command == 'm') { // mark
            mark(row, column, board, minesCoordinates, markedMines, markedCells);

            if (markedMines == MINES_COUNT && markedCells == MINES_COUNT) {
                // All mines are marked and no other cells are marked
                print(board, printedBoard);
                cout << "_ _ _ You Win! _ _ _" << endl;
                break;
            }
        }
    }

    return 0;
}
