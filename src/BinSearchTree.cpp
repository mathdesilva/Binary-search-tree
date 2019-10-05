#include "../include/BinSearchTree.h"


/// Constructor
BinSearchTree::BinSearchTree( std::vector <int> v )
{
	for( int i = 0; i < (int)v.size(); i++){
		insert( v[i] );
	}
	//std::cout << "test :: BST Constructor1";
	// TODO
}
BinSearchTree::BinSearchTree( )
{
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
Node* BinSearchTree::search( int element ) {
	Node * target = root;
	while(true){
	
		if(target == nullptr){
			return nullptr;	//nullptr
		}
		else if(target->data == element){
			return target;	//root
		}
		else if(target->data < element){
			target = target->right;
		}
		else{
			target = target->left;
		}
	}
}

/// Insert an element
bool BinSearchTree::insert( int element ) {
	// TODO
	while(true){

		if(this->root == nullptr){
			Node * val = new Node();

			root = val;
			this->root->data = element;
			SIZE = 1;
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
				SIZE = SIZE + 1;
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
				SIZE = SIZE + 1;
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

/// to_string
std::string BinSearchTree::to_string( ) {
	std::string str = "";
	Node * aux = root;
	str = rec_node_print(aux);

	return str;
}

/// Recursive node print
std::string rec_node_print( Node * ptr ) {
	std::string str = "";
	if( ptr == nullptr ) {
		str += "-)";
	}
	else {
		str += std::to_string(ptr->data) + "(";
		str += rec_node_print(ptr->left);	// left
		str += "(";
		str += rec_node_print(ptr->right); 	// right
		str += ")";
	}

	return str;
}