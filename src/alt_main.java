#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/BinSearchTree.h"

int main(){

    std::vector <int> arr {2, 3, 5, 12, 4, 13};
    std::vector <int> arr_f {37, 42, 74, 81, 16, 90, 8, 25, 28};

    for(int i = 0; i < 10; i++){

        //arr[i] = i ;
        std::cout<<arr[i]<<std::endl;
    }

//Constructor test
	BinSearchTree bst;
    BinSearchTree bst2(arr);
    BinSearchTree bst_f(arr_f);

    int p = 41;
    int l = 111;

//insert test
    std::cout << bst2.insert( 41 ) << std::endl;
    std::cout << bst2.insert( p ) << std::endl;
    std::cout << bst2.insert( l ) << std::endl;

//search test
    std::cout << bst2.search( p ) << std::endl;
    std::cout << bst2.search( 90 ) << std::endl;

    return 0;
}