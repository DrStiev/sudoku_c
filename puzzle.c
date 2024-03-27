#include "sudoku.h"

int ** createPuzzle(int difficulty){
    int **puzzle;
    int i, j;

    // Initialize puzzle with zeros
    puzzle = (int **)malloc(sizeof(int *) * 9);
    for (i = 0; i < 9; i++) {
        puzzle[i] = (int *)malloc(sizeof(int) * 9);
        for (j = 0; j < 9; j++) {
            puzzle[i][j] = 0;
        }
    }
    // generate sudoku puzzle with desired difficulty level
    generateSudoku(puzzle, difficulty);
    return puzzle;
}

bool isValid(int** puzzle, int row, int col, int num) {
    // check row and column
    for (int i = 0; i < 9; i++){
        if (puzzle[row][i] == num || puzzle[i][col] == num) {
            return false;
        }
    }

    // check 3x3 subgrid
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j<3;j++){
            if(puzzle[i+startRow][j+startCol]==num){
                return false;
            }
        }
    }
    return true;
}

// Function to solve Sudoku using backtracking
bool solveSudoku(int **puzzle) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (puzzle[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(puzzle, row, col, num)) {
                        puzzle[row][col] = num;
                        if (solveSudoku(puzzle)) {
                            return true;
                        }
                        puzzle[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Function to generate Sudoku puzzle of given difficulty level
bool generateSudoku(int **puzzle, int difficulty) {
    // Generate a complete Sudoku grid
    solveSudoku(puzzle);

    // Remove numbers based on difficulty level
    int cellsToRemove = 0;
    switch (difficulty) {
        case 1:
            cellsToRemove = 40; // Easy: 40 cells removed
            break;
        case 2:
            cellsToRemove = 50; // Medium: 50 cells removed
            break;
        case 3:
            cellsToRemove = 60; // Hard: 60 cells removed
            break;
        default:
            cellsToRemove = 40; // Default to easy
    }

    // Randomly remove numbers
    while (cellsToRemove > 0) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (puzzle[row][col] != 0) {
            puzzle[row][col] = 0;
            cellsToRemove--;
        }
    }

    return true;
}

void freePuzzle(int** puzzle) {
    // Free allocated memory
    for (int i = 0; i < 9; i++) {
        free(puzzle[i]);
    }
    free(puzzle);
}

printPuzzle(int** puzzle) {
    printf("------------------------------\n");
        for (int i = 0; i < 9; i++)
        {
            printf("|");
            for (int j = 0; j < 9; j++)
            {
                printf(" %d ",puzzle[i][j]);
                if (((j + 1) % 3) == 0)
                {
                    printf("|");
                }
            }
            printf("\n");
            if (((i + 1) % 3) == 0)
            {
                printf("------------------------------\n");
            }
        }
}