#include <iostream>
using namespace std;

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

void NLR(Tree T)
{
	if(T != NULL)
    {
        cout << T->val << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

void Rotate(Tree &T)
{
    if(T == NULL)
    {
        cout<< "\nKhong the xoay vi cay rong";
        return;
    }
    if(T->right == NULL)
    {
        cout << "\nKhong the xoay trai vi khong co nut con ben phai";
        return;
    }
    // Tree temp1 = T;
    // Tree temp2 = T->right->left;
    // T = T->right;
    // temp1->right = temp2;
    // T->left = temp1;

    Tree p = T->right;
    T->right = T->right->left;
    p->left = T;
    T = p;
}

int main()
{
	Tree T = NULL;
	inputTree(T); 
    cout<<"NLR: "; NLR(T);
    Rotate(T);
    cout<<"\nNLR: "; NLR(T);
	return 0;
}