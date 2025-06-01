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
	Node *left, *right;
};

typedef Node* Tree;

Node* createNode(int x)
{
	Node *p = new Node;
	p->val = x;
	p->left = p->right = NULL;
	return p;
}

void insertTree(Tree &T, int x)
{
	if(T == NULL)
	{
		T = createNode(x);
		return;
	}
	if(T->val < x) insertTree(T->right, x);
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

void LNR(Tree T)
{
	if(T != NULL)
	{
		LNR(T->left);
		cout << T->val << " ";
		LNR(T->right);
	}
}

Node* removeRange(Tree &T, int minVal, int maxVal)
{
	
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);

	int minValue, maxValue;
	cin>>minValue>>maxValue; // minValue <= maxValue
	T = removeRange(T,minValue,maxValue); // xoa nhung node < minValue va nhung node > maxValue

	cout<<"\nUpdated Tree: \n";
	cout<<"LNR: "; LNR(T);
	return 0;
}



