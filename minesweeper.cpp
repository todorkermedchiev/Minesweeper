#include <iostream>
#include "headers/generateMines.h"

using namespace std;

int main()
{
    const int SIZE = 11;
    const int MINES_COUNT = 10;

    int row = 0, column = 0;
    char command;

    int minesPositions[MINES_COUNT] = {};
    char board[9][9] = {};

    generateMinesPositions(minesPositions);
    for (int i = 0; i < 10; ++i) {
        cout << minesPositions[i] << ' ';
    }

    return 0;
}
