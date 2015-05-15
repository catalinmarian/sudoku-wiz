#include "sudoku.h"
#include <iostream>
#include <fstream>

bool solution_found(int board[][B_SIZE])
{
	for (int row = 0; row != B_SIZE; ++row) {
		for (int col = 0; col != B_SIZE; ++col) {
			if (board[row][col] == 0)
				return false;
		}
	}
	return true;
}

bool good_col(int board[][B_SIZE], int col, const int& val)
{
	for (int row = 0; row != B_SIZE; ++row) {
		if (board[row][col] == val)
			return false;
	}
	return true;
}

bool good_row(int board[][B_SIZE], int row, const int& val)
{
	for (int col = 0; col != B_SIZE; ++col) {
		if (board[row][col] == val)
			return false;
	}
	return true;
}

bool solve_sudoku(int board[][B_SIZE], int row, int col)
{
    //Base case
	if (solution_found(board))
		return true;
    //We are modifying data only on empty cells
	else if (board[row][col] == 0) {
		for (int val = 1; val <= B_SIZE; ++val) {
			if (good_col(board, col, val) && good_row(board, row, val)) {
                //Insert value in cell only if valid
				board[row][col] = val;
        
                //Make a recursive step and return true if board is solvable from here on
				if ((col == B_SIZE - 1) && solve_sudoku(board, row + 1, 0))
					return true;
				//Make a recursive step and return true if board is solvable from here on
				if (col < B_SIZE && solve_sudoku(board, row, col + 1))
					return true;
			}
		}
	}
	//Skip completed cells
	else {
		if ((col == B_SIZE - 1) && solve_sudoku(board, row + 1, 0))
			return true;
		if (col < B_SIZE && solve_sudoku(board, row, col + 1))
			return true;
	}
    //Delete data from cell
	board[row][col] = 0;
	//Backtrack on a previous stack-frame
	return false;
}

void print_board(int board[][B_SIZE])
{
	std::cout << "\n+";
	for (int i = 0; i != B_SIZE; ++i) {
		std::cout << "----";
		if ((i + 1) % 3 == 0)
			std::cout << "+";
	}
	std::cout << "\n";

	for (int row = 0; row != B_SIZE; ++row) {
		std::cout << "| ";
		for (int col = 0; col != B_SIZE; ++col) 
			std::cout << board[row][col] << " | ";
		std::cout << " \n+";
		for (int i = 0; i != B_SIZE; ++i) {
			std::cout << "----";
			if ((i + 1) % 3 == 0)
				std::cout << "+";
		}
		std::cout << "\n";
	}
}

bool read_board(int board[][B_SIZE])
{
	std::fstream board_file("board.txt", std::ios_base::in);
	if (!board_file.is_open())
		return false;
	for (int row = 0; row != B_SIZE; ++row) {
		for (int col = 0; col != B_SIZE; ++col)
			board_file >> board[row][col];
	}
	board_file.close();
	return true;
}
