/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct node
{
    int info;
    node* pLeft;
    node* pRight;
};

typedef node* Tree;

node* createNode(int x)
{
    Tree newNode = new node;
    newNode->info = x;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}

bool insertNode(Tree &t, int x)
{
    if(t == NULL)
    {
        t = createNode(x);
        return true;
    }
    if(x < t->info) return insertNode(t->pLeft, x);
    else if(x > t->info) return insertNode(t->pRight, x);
    return false;
}

void inputTree(Tree &t)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp_input;
        cin >> temp_input;
        if(!insertNode(t, temp_input))
        {
            cout<<"Bi trung gia tri, ket thuc qua trinh tao cay"<<endl;
            break;
        }
    }
}

void NLR(Tree t)
{
    if(t == NULL) return;
    cout << t->info << " ";
    NLR(t->pLeft);
    NLR(t->pRight);
}

void LNR(Tree &t)
{
    if(t == NULL) return;
    LNR(t->pLeft);
    cout << t->info << " ";
    LNR(t->pRight);
}

int height(Tree t) 
{
    if (t == NULL) return 0;
    return max(height(t->pLeft), height(t->pRight)) + 1;
}

bool checkLeafHeight(Tree t, int level, int heightValue) 
{
    if (t == NULL) return true;
    if (t->pLeft == NULL && t->pRight == NULL) 
	{
        if (level != heightValue) return false; 
        return true;
    }
    return checkLeafHeight(t->pLeft, level + 1, heightValue) && checkLeafHeight(t->pRight, level + 1, heightValue);
}

bool isFullBinaryTree(Tree t) 
{
    if (t == NULL) return true;
    if (t->pLeft == NULL && t->pRight == NULL) return true;
    if (t->pLeft != NULL && t->pRight != NULL) return isFullBinaryTree(t->pLeft) && isFullBinaryTree(t->pRight);
    return false;
}

bool isSpecialBST(Tree t) 
{
    if (t == NULL) return true;
    int h = height(t);
    if (!isFullBinaryTree(t)) return false;
    if (!checkLeafHeight(t, 1, h)) return false;
    return true;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isSpecialBST (T);
	if(i==0) cout<<"\nThe tree is not a (My)Special-BST";
    else cout<<"\nThe tree is a (My)Special-BST";
	return 0;
}


