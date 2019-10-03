#include "../include/BinSearchTree.h"


/// Constructor
BinSearchTree::BinSearchTree( std::vector <int> v ):
	SIZE{ v.size() },
	root{ new Node() }
{
	//std::cout << "test :: BST Constructor0---------\n\n\n\n\n";
	this->root->prev = nullptr;
	this->root->left = nullptr;
	this->root->right = nullptr;
	this->root->data = v[0];
	
	//std::cout << "test :: BST Constructor0---------\n\n\n\n\n";

	for( int i = 1; i < v.size(); i++){
		insert( v[i] );
	}
	std::cout << "test :: BST Constructor1---------\n\n\n\n\n";

	
	// TODO
}
BinSearchTree::BinSearchTree( ){

	//std::cout << "test :: BST Constructor\n";	
	// TODO
}

/// Destructor
BinSearchTree::~BinSearchTree( ) {
	//apply the method remove 
	//std::cout << "test :: BST Destructor\n";
	// TODO
}

/// Search an element
bool BinSearchTree::search( int element ) {  //TO TEST bool ?
	// TODO
	while(true){
	
		if(this->root == nullptr){
			return false;//nullptr
		}
		else if(this->root->data == element){
			return true;//root
		}
		else if(this->root->data < element){
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
			Node * val = new Node();

			root = val;
			this->root->data = element;
			return true;
		}
		else if(this->root->data == element){
			return false;//cound hapen
		}
		else if(this->root->data < element){

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

	// if(element < root->data){
	// 	root->left = remove()
	// }
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

// void BinSearchTree::view(root){

// 	// while(true){
// 	// 	if(root->prev == nullptr){
// 	// 		std::cout << root->data << std::endl;
// 	// 		if(root->left =! nullptr){
// 	// 			root = root->left;
// 	// 		}
// 	// 		else if(root->right != nullptr){
// 	// 			root = root->right;
// 	// 		}
// 	// 		else{
// 	// 			break;
// 	// 		}
// 	// 	}
		
// 	// 	else{

// 	// 		std::cout << root->data << '  -  ';
// 	// 		root = root->prev->right;
// 	// 		std::cout << root->data << '\n';
// 	// 		root = root->prev->left;
				
// 	// 		if(root->left =! nullptr){
// 	// 			root = root->left;
// 	// 		}
// 	// 		else if(root->right != nullptr){
// 	// 			root = root->right;

// 	// 		}
// 	// 		//std::cout << root->data << '  -  ';
// 	// 		//if()
// 	// 	}
// 	// 	//std::cout << root->data << std::endl;
// 	// }
// 	if(root != nullptr){
// 		std::cout << (root)->data << std::cout<< " ";
// 		view(&(root->left));
// 		view(&(root->right));
// 	}

// }

/// to_string
std::string BinSearchTree::to_string( ) {
	// TODO
	// std::cout << "test :: to_string method" << std::endl;
	return "abcde";
}