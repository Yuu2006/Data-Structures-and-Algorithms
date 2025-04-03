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

Node *getNode(int x)
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
        T = getNode(x);
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

Tree Search(Tree T, int x)
{
    if(T != NULL)
    {
        if(x == T->val) return T;
        else if(x < T->val) return Search(T->left, x);
        else return Search(T->right, x);
    }
    else return T;
}

void SetLeft(Tree T, int c)
{
    if (T == NULL) return; 
    if (T->left == NULL) T->left = getNode(c);
    else T->left->val = c;
}

void SetRight(Tree T, int c)
{
    if (T == NULL) return; 
    if (T->right == NULL) T->right = getNode(c);
    else T->right->val = c;
}

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;
    //if(isBST(T)) cout<<"\nCay vua tao la cay BST";
    //else cout<<"\nCay vua tao khong phai la cay BST";

	return 0;
}


/*
    TESTCASE
IN
9
L 9 1
R 9 5
L 1 7
R 5 4
R 3 7
X

OUT
Node khong ton tai

LNR: 7 1 9 5 4
Cay vua tao khong phai la cay BST

----------
IN
1
L 1 10 L 2 2 R 6 8 R 7 6 R 1 10
R 3 10 R 7 4 L 10 1 L 1 6 L 6 4
L 3 3 L 5 9 R 10 4 L 7 6 L 1 1
L 7 6 L 4 6 R 1 4 L 4 7 L 6 7
R 6 9 R 2 1 R 10 4 L 9 7 R 4 10
L 4 6
X

OUT
Node khong ton tai
Node khong ton tai
Node khong ton tai
Node khong ton tai
Node khong ton tai
Da co node con ben trai
Node khong ton tai
Node khong ton tai
Node khong ton tai
Node khong ton tai
Da co node con ben trai
Node khong ton tai
Da co node con ben phai
Da co node con ben trai
Node khong ton tai
Da co node con ben phai
Da co node con ben trai

LNR: 1 10 7 6 7 9 4 10 1 10
Cay vua tao khong phai la cay BST


-----
IN
25
L 25 10
L 10 4
L 4 1
R 1 3
R 4 7
R 10 17
R 25 30
L 17 13
R 30 33
L 32 31
X
OUT
Node khong ton tai

LNR: 1 3 4 7 10 13 17 25 30 33
Cay vua tao la cay BST
*/