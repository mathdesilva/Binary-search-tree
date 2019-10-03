#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <iostream>
#include <string>
#include <vector>



class BinSearchTree {

	private:
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

        std::size_t SIZE = 0;           //!< Total size of the list
        Node *root = nullptr;                 //!< Head node of the list
		

	public:
		/// Constructor
		BinSearchTree( std::vector <int> v );

		/// Constructor
		BinSearchTree( );

		/// Destructor
		~BinSearchTree( );

		/// Search an element
		bool search( int element );

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

		//void view(root);

		/// to_string
		std::string to_string( );

};

#endif