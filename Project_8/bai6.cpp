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
    if(!T)
    {
        T = createNode(x);
        return;
    }
    if (x == T->val) return;
    else if (x > T->val)
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

void nodesWithLevel(Tree T, int k)
{
    if(T == NULL) return;
    if(k == 0) 
    {
        cout << T->val << " ";
        return;
    }
    nodesWithLevel(T->right, k - 1);
    nodesWithLevel(T->left, k - 1);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    int k; cout<<"Enter k: "; cin >>k;
    cout<<"\nList of nodes with level "<<k<<" (R->L) : ";
    nodesWithLevel(T, k);

	return 0;
}
