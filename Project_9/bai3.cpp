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
    else if (x > T->val) insertNode(T->right, x);
    else insertNode(T->left, x);
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

Node* replaceNode(Node* &p, Node* &q)
{
    if (q->left != NULL)
        return replaceNode(p, q->left);
    
    p->val = q->val; 
    Node* temp = q;
    q = q->right;
    return temp;
}

void deleteRoot(Tree &T, int m)
{
	if(T == NULL) return;
	while(m != 0 && T != NULL)
	{
		Node* p = T;
		if (T->left == NULL) T = T->right;
		else if(T->right == NULL) T = T->left;
		else p = replaceNode(T, T->right);
		delete p;
		m--;
	}
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	int m; cout<<"\nEnter m: ";cin>>m;
	deleteRoot(T,m);
	cout<<"\nNLR: "; NLR(T);

	return 0;
}
