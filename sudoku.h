#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int **createPuzzle(int diffculty);
void printPuzzle(int **puzzle);
bool isValid(int **puzzle, int row, int col, int num);
bool solveSudoku(int **puzzle);
bool generateSudoku(int **puzzle, int difficulty);
void freePuzzle(int **puzzle);