#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <iostream>
#include <string>

class BinSearchTree {

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