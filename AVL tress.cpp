#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
	int height;
};


int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
				
	return node;
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *z = x->right;

	x->right = y;
	y->left = z;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *z = y->left;

	y->left = x;
	x->right = z;


	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node *rebalance(Node *node, int key){
	node->height = max(height(node->left), height(node->right)) + 1;

	int balance = getBalance(node);
	
	
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	
	if (balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}


	if (balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;	
}

Node* insert(Node* node, int key)
{

	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node = rebalance(node, key);

	return node;
}

void writeOutput(Node* root, int level){
	ofstream output("output.txt", ios::app);
	if (root == NULL)
		return;
	if (level == 1){
	output << root->key << "\t" << 
	getBalance(root) << "\t\t" 
	<< root->height << endl;
	}
	else if (level > 1){
		writeOutput(root->left, level-1);
		writeOutput(root->right, level-1);
	}
	output.close();
}


void write(Node* root)
{
	ofstream output1("output.txt", std::ofstream::out | std::ofstream::trunc);
	ofstream output("output.txt", ios::app);
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
	{
		writeOutput(root, i);
		output << endl;
	}
	output.close();
}

int main()
{
	Node *root = NULL;
	
	int data;
	
	ifstream MyReadFile("input.txt");
	while (MyReadFile >> data) {
	root = insert(root, data);
	}
	MyReadFile.close();
	
	write(root);
	
	return 0;
}
