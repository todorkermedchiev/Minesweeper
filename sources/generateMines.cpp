#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void generateMinesBoard(bool minesBoard[][BOARD_SIZE])
{
    bool isValidPosition = true;
    int positions[MINES_COUNT] = {};
    unsigned int position = 0;
    unsigned int index = 0;
    int row = 0;
    int column = 0;
    srand(time(NULL));

    while (index < MINES_COUNT) {
        position = rand() % 100; // Generating random number between 0 and 99;
        // This number indicates the coordinates of the mine
        // The first digit is the row and the second is the column, so the number must be between 11 and 99
        isValidPosition = position >= 11 && position <= 99 && position % 10 != 0;

        for (int j = 0; j < MINES_COUNT && isValidPosition; ++j) {
            if (position == positions[j]) {
                // There is a repeating number
                isValidPosition = false;
            }
        }

        if (isValidPosition) {
            positions[index] = position;
            ++index;
        }
    }

    for (int i = 0; i < MINES_COUNT; ++i) {
        row = positions[i] / 10;
        column = positions[i] % 10;
        cout << row << ' ' << column << endl;
        minesBoard[row][column] = true;
    }
}
