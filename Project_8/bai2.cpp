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

void listLeafs(Tree T)
{
	if(!T) return;
	if(!T->left && !T->right)
	{
		cout << T->val << " ";
	}
	listLeafs(T->left);
	listLeafs(T->right);
}

void listInternalNodes(Tree T, int x)
{
	if(!T) return;
	if((T->left || T->right) && x != 0)
	{
		cout << T->val << " ";
	}
	listInternalNodes(T->left, x+1);
	listInternalNodes(T->right, x+1);
}

void listNodesWithOneChild(Tree T)
{
	if(!T) return;
	if((T->left && !T->right) || (!T->left && T->right))
	{
		cout << T->val << " ";
	}
	listNodesWithOneChild(T->left);
	listNodesWithOneChild(T->right);
}

void listNodesWithTwoChildren(Tree T)
{
	if(!T) return;
	if(T->left && T->right)
	{
		cout << T->val << " ";
	}
	listNodesWithTwoChildren(T->left);
	listNodesWithTwoChildren(T->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	cout<<"\nLeaf nodes: "; listLeafs(T);
	cout<<"\nInternal nodes: "; listInternalNodes(T,0); //co de san tham so thu 2 cho ai co nhu cau dung, SV khong dung tham so thu 2 nay cung khong sao
	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
