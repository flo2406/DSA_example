#include "btree.h"
#include <iostream>
using namespace std;

/*************** PRIVATNE METODE ****************/

node* btree::create_new_node(string element) 
{
	node* new_node = new node;
	new_node->element = element;
	new_node->left_child = nullptr;
	new_node->right_child = nullptr;
	
	return new_node;
}

/*************** JAVNE METODE ****************/

btree::btree(string element) 
{
	root_node = create_new_node(element);
}

void btree::insert_left(node* parent, string element) 
{
	parent->left_child = create_new_node(element);
}

void btree::insert_right(node* parent, string element) 
{
	parent->right_child = create_new_node(element);
}

node* btree::root() 
{
	return root_node;
}

node* btree::get_left_child(node* parent) 
{
	return parent->left_child;
}

node* btree::get_right_child(node* parent) 
{
	return parent->right_child;
}
