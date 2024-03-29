// FILE: dnode.h
// PROVIDES: A class for a node in a doubly linked list, and list manipulation
// functions, all within the namespace main_savitch_5
//
// TYPEDEF for the dnode class: 
//     Each node of the list contains a piece of data and a pointers to the
//     previous and next nodes. The type of the data is defined as
//     dnode::value_type in a typedef statement. The value_type may be any 
//     of the built-in C++ classes (int, char, ...) or a class with a copy
//     constructor, an assignment operator, and a test for equality (x == y).
//
// CONSTRUCTOR for the dnode class:
//   dnode(
//     const value_type& init_data = 0,
//     node* init_fore = NULL,
//     node* init_back = NULL
//   )
//     Postcondition: The node contains the specified data and links.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the value_type. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. Both links have a default value of NULL.
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is dnode*) and a const version (where the return value
//   is const dnode*). 
// EXAMPLES:
//    const dnode *c;
//    c->fore( ) activates the const version of fore
//    dnode *p;
//    p->fore( ) activates the non-const version of fore
//
// MEMBER FUNCTIONS for the dnode class:
//   void set_data(const value_type& new_data)
//     Postcondition: The node now contains the specified new data.
//   
//   void set_fore(dnode* new_fore)
//   and
//   void set_back(dnode* new_back)
//     Postcondition: The node now contains the specified new link.
//
//   value_type data( ) const
//     Postcondition: The return value is the data from this dnode.
//
//   const dnode* fore( ) const <----- const version
//   dnode* fore( ) <----------------- non-const version
//   const dnode* back( ) const <----- const version
//   dnode* back( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is a link from this dnode.


 
#ifndef DNODE_H  
#define DNODE_H
#include <cstdlib> // Provides size_t and NULL

// TYPEDEF
typedef double value_type;

    class dnode
    {
	public:
    
		// CONSTRUCTOR
		dnode(const value_type& init_data = 0.0, dnode* init_fore = NULL, dnode* init_back = NULL)
	    	 {
				data_field = init_data;
				link_fore = init_fore;
				link_back = init_back;
	    	 }

		// Member functions to set the data and link fields:
    	void set_data(const value_type& new_data) { data_field = new_data; }
    	void set_fore(dnode* new_fore)             { link_fore = new_fore; }
    	void set_back(dnode* new_back)             { link_back = new_back; }

		// Const member function to retrieve the current data:
		value_type data( ) const { return data_field; }

		// Two slightly different member functions to retrieve each current link:
		const dnode* fore( ) const { return link_fore; }
    	dnode* fore( )             { return link_fore; }
		const dnode* back( ) const { return link_back; }
    	dnode* back( )             { return link_back; }
    	
    	private:
			value_type data_field;
			dnode *link_fore;
			dnode *link_back;
    };

    // FUNCTIONS for the linked list toolkit
	void traverse(dnode * head_ptr);
	void traverse(const dnode* head_ptr);
    size_t list_length(const dnode* head_ptr);
    void list_head_insert(dnode*& head_ptr, const value_type& entry);  
    void list_insert(dnode* previous_ptr, const value_type& entry);  
    dnode* list_search(dnode* head_ptr, const value_type& target);
    const dnode* list_search (const dnode* head_ptr, const value_type& target);
    dnode* list_locate(dnode* head_ptr, size_t position);
    const dnode* list_locate(const dnode* head_ptr, size_t position);
    void list_head_remove(dnode*& head_ptr);
    void list_remove(dnode* remove_ptr);
    void list_clear(dnode*& head_ptr);
    void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr);

#endif
