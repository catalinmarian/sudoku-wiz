#include "stdafx.h"
#include "sudoku.h"
#include <iostream>


int main()
{
	int board[B_SIZE][B_SIZE];
	bool sol_found = false;
	bool file_read = false;

	file_read = read_board(board);
	if (!file_read)
		return -1;

	sol_found = solve_sudoku(board, 0, 0);
	if (solution_found)
		print_board(board);
	else std::cout << "\nNo solution found\n";

	return 0;
}
