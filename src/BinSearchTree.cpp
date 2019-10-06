#include "../include/BinSearchTree.h"


/// Constructor
BinSearchTree::BinSearchTree( std::vector <int> v )
{
	for( int i = 0; i < (int)v.size(); i++){
		insert( v[i] );
	}
	std::cout << root->data << std::endl;
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
	if( root == nullptr ) {
		root = new Node();
		root->data = element;
		SIZE = 1;
		return true;
	}

	Node * ptr = root;
	while( true ) {
		if( ptr->data == element ) {
			return false;
		}
		else if( element < ptr->data ) {
			if( ptr->left == nullptr ) {
				ptr->left = new Node();
				ptr->left->prev = ptr;
				ptr->left->data = element;
				SIZE++;
				return true;
			}
			else {
				ptr = ptr->left;
			}
		}
		else {
			if( ptr->right == nullptr ) {
				ptr->right = new Node();
				ptr->right->prev = ptr;
				ptr->right->data = element;
				SIZE++;
				return true;
			}
			else {
				ptr = ptr->right;
			}
		}
	}
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

	str = rec_node_print(this->root);

	return str;
}

/// Recursive node print
std::string BinSearchTree::rec_node_print( Node * ptr ) {
	std::string str = "";
	if( ptr != nullptr ) {
		str += std::to_string(ptr->data);
		if(ptr->left != nullptr or ptr->right != nullptr) {
			str += "(";
			str += rec_node_print(ptr->left);	// left
			str += ")(";
			str += rec_node_print(ptr->right); 	// right
			str += ")";
		}
	}
	else{
		str += "-";
	}

	return str;
}