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

void LNR(Tree T)
{
    if(T != NULL)
    {
        LNR(T->left);
        cout << T->val << " ";
        LNR(T->right);
    }
}

Node *Search(Tree T, int x)
{
    if(T != NULL)
    {
        if(x == T->val) return T;
        else if(x < T->val) return Search(T->left, x);
        else return Search(T->right, x);
    }
    else return T;
}

int minValue(Tree T)
{
    if(T != NULL && T->left == NULL) return T->val;
    else return minValue(T->left);
}

int maxValue(Tree T)
{
    if(T != NULL && T->right == NULL) return T->val;
    else return maxValue(T->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}
