#include "sudoku.h"
#include <time.h>

int main()
{
    // Seed random number generator
    srand(time(NULL));

    int** puzzle;
    puzzle = createPuzzle(3);
    printPuzzle(puzzle);
    freePuzzle(puzzle);
    return 0;
}