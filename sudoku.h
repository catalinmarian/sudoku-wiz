#pragma once

/**Change this macro if you need a different board size*/
#define B_SIZE 9

/**Check if we got a solution*/
bool solution_found(int board[][B_SIZE]);

/**Check validity of column*/
bool good_col(int board[][B_SIZE], int col, const int& val);

/**Check validity of row*/
bool good_row(int board[][B_SIZE], int row, const int& val);

/**Find a solution for our board*/
bool solve_sudoku(int board[][B_SIZE], int row, int col);

/**Parse board data and print it on screen*/
void print_board(int board[][B_SIZE]);

/**Read board data from a file*/
bool read_board(int board[][B_SIZE]);
