#include "BinSearchTree.h"


/// Constructor
BinSearchTree::BinSearchTree( ) {
	// std::cout << "test :: BST Constructor\n";
	
	// TODO
}

/// Destructor
BinSearchTree::~BinSearchTree( ) {
	// std::cout << "test :: BST Destructor\n";
	// TODO
}

/// Search an element
*Node BinSearchTree::search( int element ) {  //TO TEST bool ?
	// TODO
	while(true){
	
		if(this->root == nullptr){
			return nullptr;
		}
		else if(this->root == element){
			return root;
		}
		else if(this->root < element){
			root = root->right;
		}
		else{
			root = root->left;
		}
	}
	//std::cout<< "Element not found."<< std::endl;
	// std::cout << "test :: seach method - " << element << std::endl;
}

/// Insert an element
bool BinSearchTree::insert( int element ) {
	// TODO
	while(true){

		if(this->root == nullptr){

		}
		else if(this->root == element){
			return false;//cound hapen
		}
		else if(this->root < element){

			if(this->root->right == nullptr){//incert the new node in bush
				Node * val = new Node();

				root->right = val;
				val->prev = root;
				val->data = element;
				return true;
				//return 0;
			}

			root = root->right;
		}
		else{

			if(this->root->left == nullptr){//incert the new node in bush
				Node * val = new Node();

				root->left = val;
				val->prev = root;
				val->data = element;
				return true;
				//return 0;
			}

			root = root->left;
		}
	}
	// std::cout << "test :: insert method - " << element << std::endl;
	return true;
}

/// Remove an element
bool BinSearchTree::remove( int element ) {
	// TODO
	// std::cout << "test :: remove method - " << element << std::endl;
	return true;
}

/// nth_element
int BinSearchTree::nth_element( int n ) {
	// TODO
	// std::cout << "test :: nth_element method - " << n << std::endl;
	return 10;
}

/// position
int BinSearchTree::position( int element ) {
	// TODO
	while(true){
	
		if(root == nullptr){
			break;
		}
		else if(this->root == element){
			return root->pos;
		}
		else if(this->root < element){
			root = root->right;
		}
		else{
			root = root->left;
		}
	}
	std::cout<< "Element not found."<< std::endl;
	// std::cout << "test :: position method - " << element << std::endl;
	return 10;
}

/// median
int BinSearchTree::median( ) {
	// TODO
	// std::cout << "test :: median method" << std::endl;
	return 10;
}

/// is_full
bool BinSearchTree::is_full( ) {
	// TODO
	// std::cout << "test :: is_full method" << std::endl;
	return true;
}

/// is_complete
bool BinSearchTree::is_complete( ) {
	// TODO
	// std::cout << "test :: is_complete method" << std::endl;
	return true;
}

/// to_string
std::string BinSearchTree::to_string( ) {
	// TODO
	// std::cout << "test :: to_string method" << std::endl;
	return "abcde";
}