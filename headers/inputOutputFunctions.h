#ifndef __INPUT_OUTPUT_FUNCTIONS
#define __INPUT_OUTPUT_FUNCTIONS
#include <iostream>
#include "boardFunctions.h"
#include "constants.h"

using namespace std;

bool validateInput(int value, int minValue, int maxValue)
{
    return (value >= minValue && value <= maxValue);
}

void input(int &row, int &column, char &command, char board[][BOARD_SIZE])
{
    int rowIn = 0, columnIn = 0;
    char commandIn;
    cout << "Enter the coordinates and the command:\n";
    cout << "[row] [column] [command] (\"s\" to show and \"m\" to mark)\n";

    cin >> rowIn >> columnIn >> commandIn;

    // Input check
    if (!validateInput(rowIn, 1, 9) ||
        !validateInput(columnIn, 1, 9) ||
        !(commandIn == 's' || commandIn == 'm')) {
        cout << "\n!!! Invalid coordinates or command !!!\n\n";
        input(rowIn, columnIn, commandIn, board);
    }

    if(board[rowIn][columnIn] >= '0' && board[rowIn][columnIn] <= '9') {
        // There is a number between 0 and 9 on the current position, so this position is already showed
        cout << "\n!!! You have already showed this. Please try another one !!!\n\n";
        input(rowIn, columnIn, commandIn, board);
    }

    row = rowIn;
    column = columnIn;
    command = commandIn;
}

void print(char board[][BOARD_SIZE], char printedBoard[][PRINTED_BOARD_COLS])
{
    // Adding elements from the board to the printed board
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printedBoard[row * 2 + 1][column * 4 + 2] = board[row][column];
        }
    }

    // Printing "printedBoard"
    cout << endl;
    for (int i = 0; i < PRINTED_BOARD_ROWS; ++i) {
        for (int j = 0; j < PRINTED_BOARD_COLS; ++j) {
            cout << printedBoard[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

#endif // __INPUT_OUTPUT_FUNCTIONS
