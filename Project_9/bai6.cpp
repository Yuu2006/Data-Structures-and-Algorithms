/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
LNR
###End banned keyword*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct node
{
    int info;
    node *left, *right;
};
typedef node* Tree;
node* getNode(int x)
{
    node* p =new node;
    p->info=x;
    p->left=p->right=NULL;
    return p;
}
void insertTree(Tree &T, int x)
{
    if(!T) T=getNode(x);
    else
    {
        if(T->info==x) return;
        if(x<T->info) insertTree(T->left,x);
        else insertTree(T->right, x);
    }

}
void inputTree(Tree &T)
{
    int n,x; cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insertTree(T, x);
    }
}
void LNR(Tree T)
{

//###INSERT CODE HERE -
    if (T == NULL) return;
    
    stack<Tree> s;
    Tree current = T;
    
    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->info << " ";
        current = current->right;
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nLNR: "; LNR(T);
	return 0;
}
