#include <iostream>
#include "headers/generalFunctions.h"
#include "headers/boardFunctions.h"
#include "headers/constants.h"
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

    // Printing the coordinates (for debugging)
    for (int i = 0; i < MINES_COUNT; ++i) {
        cout << minesCoordinates[i] << endl;
    }

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
            mark(row, column, board, minesCoordinates, markedMines);

            if (markedMines == MINES_COUNT) {
                // All mines are marked
                print(board, printedBoard);
                cout << "_ _ _ You Win! _ _ _" << endl;
                break;
            }
        }
    }

    return 0;
}
