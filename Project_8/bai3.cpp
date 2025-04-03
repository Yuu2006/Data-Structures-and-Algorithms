/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node
{
    int val;
    Node *left;
    Node *right;
};
typedef Node* Tree; 

Node *createNode(int x)
{
    Node *p = new Node;
    if(p == NULL) cout << "Memory is full";
    p->val = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(Tree &T, int x)
{
    if(!T) // T == NULL
    {
        T = createNode(x);
        return;
    }
    if(x == T->val) return;
    else if(x > T->val) 
        insertNode(T->right, x);
    else 
        insertNode(T->left, x);
}

void inputTree(Tree &T)
{
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        insertNode(T, x);
    }
}

void NLR(Tree T)
{
    if(T != NULL)
    {
        cout << T->val << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

void LRN(Tree T)
{
    if(T != NULL)
    {
        LRN(T->left);
        LRN(T->right);
        cout << T->val << " ";
    }
}


int countNodes(Tree T)
{
	if(T == NULL) return 0;
	return countNodes(T->left) + countNodes(T->right) + 1;	
}

int countLeafs(Tree T)
{
	if(T == NULL) return 0;
    if(T->left || T->right) return countLeafs(T->left) + countLeafs(T->right);
	return countLeafs(T->left) + countLeafs(T->right) + 1;
}

int x = 0;

int countInternalNodes(Tree T)
{
	if(T == NULL) return 0;
	if(!T->left && !T->right) return countInternalNodes(T->left) + countInternalNodes(T->right);
	if(x == 0) 
	{
		x++;
		return countInternalNodes(T->left) + countInternalNodes(T->right);
	}
	return countInternalNodes(T->left) + countInternalNodes(T->right) + 1;
}

int countOneChild(Tree T)
{
	if(T == NULL) return 0;
	if((T->left && T->right) || (!T->left && !T->right)) return countOneChild(T->left) + countOneChild(T->right);
	return countOneChild(T->left) + countOneChild(T->right) + 1;
}

int countTwoChildren(Tree T)
{
	if(T == NULL) return 0;
	if(!T->left || !T->right) return countTwoChildren(T->left) + countTwoChildren(T->right);
	return countTwoChildren(T->left) + countTwoChildren(T->right) + 1;
}

int countLess(Tree T, int x)
{
	if(T == NULL) return 0;
	if(T->val >= x) return countLess(T->left, x) + countLess(T->right, x);
	return countLess(T->left, x) + countLess(T->right, x) + 1;
}

int countBetweenValues(Tree T, int x, int y)
{
	if(T == NULL) return 0;
	if(T->val <= x || T->val >= y) return countBetweenValues(T->left, x, y) + countBetweenValues(T->right, x, y);
	return countBetweenValues(T->left, x, y) + countBetweenValues(T->right, x, y) + 1;
}

int main()
{
	Tree T = NULL;
	inputTree(T);

    cout<<"Number of nodes: " << countNodes(T)<<endl;
	cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	int x;cout<<"Enter x: ";cin>>x;
	cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	int y; cout<<"Enter x,y: ";cin>>x>>y;
	cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

	return 0;
}
