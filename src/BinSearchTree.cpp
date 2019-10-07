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
	rec_node_print(root);
}

/// Recursive node dealloc
void rec_node_dealloc( Node * ptr ) {
	if(ptr == nullptr)
		return;

	if(ptr->left != nullptr)
		rec_node_dealloc(ptr->left);
	
	if(ptr->right != nullptr)
		rec_node_dealloc(ptr->right);
	
	delete ptr;
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
	
	return is_full_util(this->root);
}
bool BinSearchTree::is_full_util(Node* ptr ) {
	if( ptr == nullptr ){
		return (true);
	}
	if( ptr->left == nullptr && ptr->right ==  nullptr ){
		return (true);
	}//222
	if((ptr->left) && (ptr->right)){
		return (is_full_util(ptr->left) && is_full_util(ptr->right));
	}
}

/// is_complete
bool BinSearchTree::is_complete( ) {

	return BinSearchTree::is_complete_util(this->root, 0, SIZE );
}
bool BinSearchTree::is_complete_util(Node* ptr, int index, int size ){

	if(ptr == nullptr){
		return (true);
	}
	if (index >= size){
		return (false);
	}
	return (is_complete_util(ptr->left, 2*index + 1, size) && is_complete_util(ptr->right, 2*index + 2, size));
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