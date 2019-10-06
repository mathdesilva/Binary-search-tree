#include <iostream>
#include <vector>
#include <fstream>
#include <string>

//./bstree ../tests/test1.txt ../tests/test2.txt

#include "../include/BinSearchTree.h"

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

	BinSearchTree bst(arr);
	
	std::string cmd_tmp;
	int n_tmp;
	while( com_file >> cmd_tmp ) {
		if( cmd_tmp == "ENESIMO" ) {
			com_file >> n_tmp;
			std::cout << " >> nth_element | n = " << n_tmp << std::endl;
			std::cout << "    > Return: " << bst.nth_element( n_tmp ) << std::endl;
		}
		else if( cmd_tmp == "POSICAO" ) {
			com_file >> n_tmp;
			std::cout << " >> position | n = " << n_tmp << std::endl;
			std::cout << "    > Return: " << bst.position( n_tmp ) << std::endl;
		}
		else if( cmd_tmp == "MEDIANA" ) {
			std::cout << " >> median" << std::endl;
			std::cout << "    > Return: " << bst.median( ) << std::endl;
		}
		else if( cmd_tmp == "CHEIA" ) {
			std::cout << " >> is_full" << std::endl;
			std::cout << "    > Return: " << bst.is_full( ) << std::endl;
		}
		else if( cmd_tmp == "COMPLETA" ) {
			std::cout << " >> is_complete" << std::endl;
			std::cout << "    > Return: " << bst.is_complete( ) << std::endl;
		}
		else if( cmd_tmp == "IMPRIMA" ) {
			std::cout << " >> to_string" << std::endl;
			std::cout << "    > Return: " << bst.to_string( ) << std::endl;
		}
		else if( cmd_tmp == "REMOVA" ) {
			com_file >> n_tmp;
			std::cout << " >> remove | n = " << n_tmp << std::endl;
			std::cout << "    > Return: " << bst.remove( n_tmp ) << std::endl;
		}
		else if( cmd_tmp == "INSIRA" ) {
			com_file >> n_tmp;
			std::cout << " >> insert | n = " << n_tmp << std::endl;
			std::cout << "    > Return: " << bst.insert( n_tmp ) << std::endl;
		}
		else {
			std::cout << "Error: invalid command: " << cmd_tmp << std::endl;
			return EXIT_FAILURE;
		}
	}
	com_file.close();


	return EXIT_SUCCESS;
}