/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *left, *right;
};
typedef struct Node* Tree;

Node *getNode(int x)
{
	Node *p = new Node;
	if (p)
	{
		p->info = x;
		p->left = p->right = NULL;
	}
	return p;
}

//###INSERT CODE HERE -

void insertTree(Tree &T, int x)
{
	if(T==NULL)
	{
		T = getNode(x);
		return;
	}
	if(T->info < x) insertTree(T->right, x);
	else insertTree(T->left, x);
}

void inputTree(Tree &T)
{
	while(true)
	{
		int x; cin >> x;
		if(x == -1) break;
		insertTree(T, x);
	}
}

int getHeight(Tree T)
{
	if(T == NULL) return 0;
	
	int l = getHeight(T->left);
	int r = getHeight(T->right);
	return 1 + max(l, r);
}

void leftHeavyNodes(Tree T)
{
	if(T == NULL) return;
	
	int l = getHeight(T->left);
	int r = getHeight(T->right);
	
	// cout << l << " " << r << endl;
	
	if(l > r)
	{
		cout << T->info << " ";
	}
	leftHeavyNodes(T->left);
	leftHeavyNodes(T->right);
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	leftHeavyNodes(T);
	return 0;
}
