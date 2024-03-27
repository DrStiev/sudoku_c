#include "sudoku.h"
#include <time.h>

int main()
{
    // Seed random number generator
    srand(time(NULL));

    int** puzzle;
    puzzle = createPuzzle(3);
    printf("Starting sudoku\n");
    printPuzzle(puzzle);
    printf("Solved sudoku\n");
    solveSudoku(puzzle);
    printPuzzle(puzzle);
    printf("Free memory\n");
    freePuzzle(puzzle);
    return 0;
}