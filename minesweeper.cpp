#include <iostream>
#include "headers/generateMines.h"
#include "headers/boardFunctions.h"
#include "headers/constants.h"

using namespace std;

int main()
{
    int row = 0, column = 0;
    char command;

    bool minesBoard[BOARD_SIZE][BOARD_SIZE] = {};
    generateMinesBoard(minesBoard);

    char board[BOARD_SIZE][BOARD_SIZE] = {};

    fillBoard(board, '-');

    print(board);

    return 0;
}
