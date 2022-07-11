#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <queue>
using namespace std;

struct node 
{
	int element;
	node* left_child;
	node* right_child;
};

class btree 
{
private:
	node* root_node;
	node* create_new_node(int element);
	void destroy(node* current);
	void bfs(queue<node*>& q);

public:
	btree(int element);
	~btree();
	void insert_left(node* parent, int element);
	void insert_right(node* parent, int element);
	node* root();
	node* get_left_child(node* parent);
	node* get_right_child(node* parent);
	void inorder(node* current);
	void preorder(node* current);
	void postorder(node* current);
	void bfs(node* current);
	void print(node* current, int level);
};

#endif