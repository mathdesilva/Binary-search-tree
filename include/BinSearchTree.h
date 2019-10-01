#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <iostream>
#include <string>



class BinSearchTree {

	private:
		//! Struct of a Node
        /*! Contains nodes previous/next adresses, and it's data. */
        struct Node {
            int data;
            Node *prev;
            Node *nextleft;
			Node *nextright;
            Node( const T & d = T(), Node *p = nullptr, Node *nl = nullptr, Node * nr = nullptr):
                data(d), prev(p), nextleft(nl), nextright(nr){}// test me
        };

        std::size_t SIZE;           //!< Total size of the list
        Node *root;                 //!< Head node of the list

	public:
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

		/// to_string
		std::string to_string( );

};

#endif