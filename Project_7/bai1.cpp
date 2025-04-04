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

void LNR(Tree T)
{
    if(T != NULL)
    {
        LNR(T->left);
        cout << T->val << " ";
        LNR(T->right);
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}
