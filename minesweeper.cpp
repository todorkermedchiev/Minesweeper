#include <iostream>
#include "headers/generateMines.h"
#include "headers/boardFunctions.h"
#include "headers/constants.h"

using namespace std;

bool validateInput(int value, int minValue, int maxValue)
{
    return (value >= minValue && value <= maxValue);
}

int main()
{
    int row = 0, column = 0;
    char command;

    bool minesBoard[BOARD_SIZE][BOARD_SIZE] = {};
    char printedBoard[PRINTED_BOARD_ROWS][PRINTED_BOARD_COLS] = {};
    makeBorders(printedBoard);
    int minesCoordinates[MINES_COUNT] = {};
    generateMinesBoard(minesBoard, minesCoordinates);

    // bool allMinesAreMarked = true;
    bool isMine = false;
    int markedMines = 0;

    char board[BOARD_SIZE][BOARD_SIZE] = {};

    // Filling the whole board with spaces
    fillBoard(board);

    // Filling the first row, the last row, the first column and the last column with the numbers from 1 to 9
    for (int i = 1; i < BOARD_SIZE - 1; ++i) {
        board[0][i] = i + '0';
        board[i][0] = i + '0';
        board[10][i] = i + '0';
        board[i][10] = i + '0';
    }

    // Printing the coordinates (for debugging)
    for (int i = 0; i < MINES_COUNT; ++i) {
        cout << minesCoordinates[i] << endl;
    }

    int nearbyMinesCount = 0;
    while (true) {
        print(board, printedBoard);
        cout << "Enter the coordinates and the command:" << endl;
        cout << "[row] [column] [command] (\"s\" to show and \"m\" to mark)" << endl;

        cin >> row >> column >> command;
        cout << endl;

        // Input check
        if (!validateInput(row, 1, 9) ||
            !validateInput(column, 1, 9) ||
            !(command != 's' || command != 'm')) {
            cout << "Invalid coordinates or command" << endl;
            continue;
        }

        if (command == 's') { // show
            if (minesBoard[row][column]) {
                for (int i = 0; i < MINES_COUNT; ++i) {
                    row = minesCoordinates[i] / 10;
                    column = minesCoordinates[i] % 10;
                    board[row][column] = 'X';
                }
                print(board, printedBoard);
                cout << "Game Over!" << endl;
                return 0;
            }
            else {
                // Finding the number of the surrounding mines
                nearbyMinesCount = 0;
                for (int i = row - 1; i <= row + 1; ++i) {
                    for (int j = column - 1; j <= column + 1; ++j) {
                        if (minesBoard[i][j]) {
                            ++nearbyMinesCount;
                        }
                    }
                }

                board[row][column] = nearbyMinesCount + '0';
            }
        }
        else if (command == 'm') {
            // Unmarking
            if (board[row][column] == '!') {
                board[row][column] = ' ';
                continue;
            }

            // Marking
            board[row][column] = '!';

            // Checking if the marked position is mine
            isMine = false;
            for (int i = 0; i < MINES_COUNT; ++i) {
                if ((row * 10 + column) == minesCoordinates[i]) {
                    isMine = true;
                }
            }

            if (isMine) {
                ++markedMines;
            }

            if (markedMines == MINES_COUNT) {
                // All mines are marked
                print(board, printedBoard);
                break;
            }
        }
    }

    cout << "You Win!!!" << endl;

    return 0;
}
