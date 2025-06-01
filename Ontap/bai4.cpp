/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct Node{
    int val;
    Node *left, *right;
};
typedef Node* Tree;
Node* initNode(int x)
{
    Node* p = new Node;
    p->val = x;
    p->left = p->right = NULL;
    return p;
}

void insertTree(Tree &T, int x)
{
    if(T == NULL)
    {
        T = initNode(x);
        return;
    }
    if(T->val > x)
        insertTree(T->left, x);
    else insertTree(T->right, x);
}
void inputTree(Tree &T)
{
    int n; cin >> n; 
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        insertTree(T, x);
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

int TreeHeight(Tree T)
{
    if(T == NULL) return 0;
    int r = TreeHeight(T->right);
    int l = TreeHeight(T->left);
    
    return 1 + max(r, l);
}

int isBalancedTree(Tree T)
{
    if(T == NULL) return 1;
    
    // Kiểm tra nút hiện tại có cân bằng không
    if(TreeHeight(T->left) != TreeHeight(T->right))
        return 0;
    
    // Đệ quy kiểm tra tất cả các cây con
    return isBalancedTree(T->left) && isBalancedTree(T->right);
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	int i = isBalancedTree(T); //Kiem tra cay hoan toan can bang
	if(i==1)
		cout<<"\nTree is balanced";
	else
		cout<<"\nTree is not balanced";
	return 0;
}



