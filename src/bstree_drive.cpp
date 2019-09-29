#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "BinSearchTree.h"

int main(int argc, char *argv[]) {
	std::vector<int> arr;	// save in-file arr

	// Error: missing operand
	if ( !(argc == 3) ) {
		std::cout << "Error: missing operand\n";
		std::cout << "Try \"./bstree <array_file> <commands_file>\"\n";
		return EXIT_FAILURE;
	}

	// saving operands
	std::string arr_file_nm = argv[1];
	std::string com_file_nm = argv[2];

	// reading array file.
	std::cout << "Openning array file... ";
	std::ifstream arr_file;
	arr_file.open(arr_file_nm);
	if( !arr_file.is_open() ) {
		std::cout << "fail\n";
		return EXIT_FAILURE;
	}
	std::cout << "done\n";

	std::cout << "Array: [ ";
	int tmp;
	while( arr_file >> tmp ) {
		arr.push_back(tmp);
		std::cout << tmp << " ";
	}
	std::cout << "]\n";
	arr_file.close();

	// openning commands file
	std::cout << "Openning commands file... ";
	std::ifstream com_file;
	com_file.open(com_file_nm);
	if( !com_file.is_open() ) {
		std::cout << "fail\n";
		return EXIT_FAILURE;
	}
	std::cout << "done\n";

	// Executing commands
	std::cout << "Starting commands\n";
	std::string cmd_tmp;
	while( com_file >> cmd_tmp ) {
		// TODO: do some ifs, one for each command.
	}

	BinSearchTree bst;

	return EXIT_SUCCESS;
}