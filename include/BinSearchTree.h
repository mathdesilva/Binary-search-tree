#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <iostream>
#include <string>
#include <vector>

//! Struct of a Node
/*! Contains nodes previous/next adresses, and it's data. */
struct Node {
	//int pos;// take the position
	int data;
	Node *prev;
	Node *left;
	Node *right;
	Node( Node *p = nullptr, Node *nl = nullptr, Node * nr = nullptr):
		prev(p), left(nl), right(nr){}// test me
};

class BinSearchTree {

	private:
        std::size_t SIZE = 0;           //!< Total size of the list
        Node *root = nullptr;                 //!< Head node of the list
		

	public:
		/// Constructor
		BinSearchTree( std::vector <int> v );

		/// Constructor
		BinSearchTree( );

		/// Destructor
		~BinSearchTree( );

		/// Insert an element
		bool insert( int element );

		/// Remove an element
		bool remove( int element );

		/// nth_element
		int nth_element( int n );

		/// position
		int position( int element );

		/// median
		int median( );

		/// is_full
		bool is_full( );

		/// is_complete
		bool is_complete( );
		bool is_complete_util(Node* ptr, int index, int size );

		//void view(root);

		/// to_string
		std::string to_string( );
	
	private:
		/// Search an element
		Node* search( int element );

		///	Recursive node print function
		std::string rec_node_print( Node * ptr );

		/// Recursive node dealloc function
		void rec_node_dealloc( Node * ptr );

};

#endif