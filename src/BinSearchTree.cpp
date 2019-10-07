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
	Node * ptr = search(element);
	if(ptr == nullptr)
		return false;
	
    if(ptr->left == nullptr) {
        if(ptr->data < ptr->prev->data) { // left
            ptr->prev->left = ptr->right;
            ptr->left->prev = ptr->prev;
        }
        else { // right
            ptr->prev->right = ptr->right;
            ptr->right->prev = ptr->prev;
        }
        delete ptr;
		SIZE--;
    }
    else if(ptr->left->right == nullptr) {
        Node * gt = ptr->left;
        gt->prev = ptr->prev;
        if(gt->data < ptr->prev->data)
            ptr->prev->left = gt;
        else
            ptr->prev->right = gt;
        
        if(ptr->right != nullptr){
            gt->right = ptr->right;
            ptr->right->prev = gt;
        }

        delete ptr;
		SIZE--;
    }
    else {
        Node * gt = largest_of_the_smallest(ptr);
        // removing gt and making connections
        gt->prev->right = gt->left;
        if(gt->left != nullptr)
            gt->left->prev = gt->prev;
        // inserting gt in ptr position
        gt->prev = ptr->prev;
        gt->left = ptr->left;
        gt->right = ptr->right;
        // connecting prev, left and right
        if(ptr->left != nullptr)
            ptr->left->prev = gt;
        if(ptr->right != nullptr)
            ptr->right->prev = gt;
        if(gt->data < ptr->prev->data)
            ptr->prev->left = gt;
        else
            ptr->prev->right = gt;
        // removing ptr
        delete ptr;
		SIZE--;
    }
	return true;
}

/// Largest of the smallest
Node * BinSearchTree::largest_of_the_smallest ( Node * ptr ) {
    ptr = ptr->left;
    if(ptr != nullptr)
        while( ptr->right != nullptr )
            ptr = ptr->right;

    return ptr;
}

/// nth_element
int BinSearchTree::nth_element( int n ) {
	Node * result = nullptr;
	Node * target = root;

	rec_nth_element(target, 0, n, &result);

	if(result != nullptr)
		return result->data;
	else
		return -1;
}

/// Recursive nth_element function
int BinSearchTree::rec_nth_element(Node * ptr, int size, const int n_res, Node **result) {
	if(size == -10000)
		return size;
	// left
	if(ptr->left != nullptr)
		size = rec_nth_element(ptr->left, size, n_res, result);
	
	size++; // value of this node
	// checking target value
	if( size == n_res ){
		*result = ptr;
		return -10000;
	}
	// right
	if(ptr->right != nullptr)
		size = rec_nth_element(ptr->right, size, n_res, result);

	return size;
}

/// position
int BinSearchTree::position( int element ) {
	int * result = nullptr;

	rec_position(root, 0, element, &result);

	if(result != nullptr)
		return *result;
	else
		return -1;
}

/// Recursive position function
int BinSearchTree::rec_position(Node * ptr, int size, const int n_res, int ** result) {
	if(size == -1)
		return size;
	// left
	if(ptr->left != nullptr)
		size = rec_position(ptr->left, size, n_res, result);
	
	size++; // value of this node
	// checking target value
	if( ptr->data == n_res ){
		int a = size;
		*result = &a;
		return -1;
	}
	// right
	if(ptr->right != nullptr)
		size = rec_position(ptr->right, size, n_res, result);

	return size;
}

/// median
int BinSearchTree::median( ) {
	// TODO
	// std::cout << "test :: median method" << std::endl;
	return -1;
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
	return true;
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