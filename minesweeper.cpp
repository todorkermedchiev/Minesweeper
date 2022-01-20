#include <iostream>
#include "headers/generateMines.h"
#include "headers/boardFunctions.h"
#include "headers/constants.h"

using namespace std;

bool validateInput(int value, int minValue, int maxValue)
{
    return (value >= minValue && value <= maxValue);
}

void input(int &row, int &column, char &command, char board[][BOARD_SIZE])
{
    int rowIn = 0, columnIn = 0;
    char commandIn;
    cout << "Enter the coordinates and the command:" << endl;
    cout << "[row] [column] [command] (\"s\" to show and \"m\" to mark)" << endl;

    cin >> rowIn >> columnIn >> commandIn;

    // Input check
    if (!validateInput(rowIn, 1, 9) ||
        !validateInput(columnIn, 1, 9) ||
        !(commandIn == 's' || commandIn == 'm')) {
        cout << endl << "Invalid coordinates or command!" << endl << endl;
        input(rowIn, columnIn, commandIn, board);
    }

    if(board[rowIn][columnIn] >= '0' && board[rowIn][columnIn] <= '9') {
        // There is a number between 0 and 9 on the current position, so this position is already showed
        cout << endl << "You have already showed this. Please try another one!" << endl << endl;
        input(rowIn, columnIn, commandIn, board);
    }

    row = rowIn;
    column = columnIn;
    command = commandIn;
}

// The function returns true when the player hit a mine
bool show(int row,
          int column,
          char board[][BOARD_SIZE],
          bool minesBoard[][BOARD_SIZE],
          int minesCoordinates[MINES_COUNT])
{
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
          int &markedMines)
{
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
    generateMinesBoard(minesBoard, minesCoordinates);

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
