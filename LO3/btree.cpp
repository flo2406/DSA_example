#include "btree.h"
#include <iostream>
using namespace std;

/*************** PRIVATNE METODE ****************/

node* btree::create_new_node(int element)
{
	node* new_node = new node;
	new_node->element = element;
	new_node->left_child = nullptr;
	new_node->right_child = nullptr;

	return new_node;
}

void btree::destroy(node* current)
{
	if (current == nullptr)
	{
		return;
	}
	destroy(current->left_child);
	destroy(current->right_child);
	delete current;
}
void btree::bfs(queue<node*>& q)
{
	if (q.empty())
	{
		return;
	}
	node* current = q.front();
	q.pop();

	cout << current->element << endl;
	if (current->left_child != nullptr)
	{
		q.push(current->left_child);
	}
	if (current->right_child != nullptr)
	{
		q.push(current->right_child);
	}

	bfs(q);
}



/*************** JAVNE METODE ****************/

btree::btree(int element)
{
	root_node = create_new_node(element);
}

btree::~btree()
{
	destroy(root_node);
}

void btree::insert_left(node* parent, int element)
{
	parent->left_child = create_new_node(element);
}

void btree::insert_right(node* parent, int element)
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

void btree::inorder(node* current)
{
	if (current == nullptr)
	{
		return;
	}
	inorder(current->left_child);
	cout << current->element << endl;
	inorder(current->right_child);
}

void btree::preorder(node* current)
{
	if (current == nullptr)
	{
		return;
	}
	cout << current->element << endl;
	preorder(current->left_child);
	preorder(current->right_child);
}

void btree::postorder(node* current)
{
	if (current == nullptr)
	{
		return;
	}
	postorder(current->left_child);
	postorder(current->right_child);
	cout << current->element << endl;
}

void btree::bfs(node* current)
{
	queue<node*> q;
	q.push(current);
	bfs(q);
}

void btree::print(node* current, int level)
{
	if (current == nullptr)
	{
		return;
	}
	if (level > 0)
	{
		for (unsigned i = 0; i < (level - 1) * 4; i++)
		{
			cout << " ";
		}
		cout << "|---";
	}
	cout << current->element << endl;
	print(current->left_child, level + 1);
	print(current->right_child, level + 1);
}