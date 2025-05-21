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
    if (x == T->val)
    {
        cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
        return;
    }
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

void LNR(Tree T)
{
	if(T != NULL)
    {
        LNR(T->left);
        cout << T->val << " ";
        LNR(T->right);
    }
}

int countNodes(Tree T)
{
    if(T == NULL) return 0;
    return 1 + countNodes(T->left) + countNodes(T->right);
}

int depthOfTree(Tree T)
{
    if(T == NULL) return -1;
    int leftDepth = depthOfTree(T->left);
    int rightDepth = depthOfTree(T->right);
    return 1 + max(leftDepth, rightDepth);
}

void countEven(Tree T, int &count_even)
{
    if(T == NULL) return;
    if(T->val % 2 == 0)
    {
        count_even++;
    }
    countEven(T->left,count_even);
    countEven(T->right,count_even);
}

void countOdd(Tree T, int &count_odd)
{
    if(T == NULL) return;
    if(T->val % 2 != 0)
    {
        count_odd++;
    }
    countOdd(T->left, count_odd);
    countOdd(T->right, count_odd);
}

int countPositive(Tree T)
{
    if(T == NULL) return 0;
    int dem = 0;
    if(T->val > 0)
        dem++;
    return dem + countPositive(T->left) + countPositive(T->right);
}

int countNegative(Tree T)
{
    if(T == NULL) return 0;
    int dem = 0;
    if(T->val < 0)
        dem++;
    return dem + countNegative(T->left) + countNegative(T->right);
}

bool isPrime(int x)
{
    if(x < 2) return false;
    if(x == 2) return true;
    for(int i = 3; i < x; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int countPrime(Tree T)
{
    if(T == NULL) return 0;
    int dem = 0;
    if(isPrime(T->val))
        dem++;
    return dem + countPrime(T->left) + countPrime(T->right);
}
void listPrime(Tree T)
{
    if (T == NULL) return;
    if (isPrime(T->val))
        cout << T->val << " ";
    listPrime(T->left);
    listPrime(T->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}
