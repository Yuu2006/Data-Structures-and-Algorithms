/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -
typedef struct Product
{
    int id;
    string name;
    string type;
    int year;
    int warranty;
} PRO;

struct Node
{
    PRO info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;

Node* createNode(PRO p) 
{   Node* tmp = new Node;
    tmp->info = p;
    tmp->pLeft = tmp->pRight = NULL;
    return tmp;
}

void insertTree(Tree &T, PRO p) {
    if (T == NULL) 
    {   
        T = createNode(p);
        return;
    }
    if (p.id < T->info.id) insertTree(T->pLeft, p);
    else insertTree(T->pRight, p);
}

void inputTree(Tree &T) 
{   int n;
    cin>>n;
    for (int i = 0; i < n; i++) 
    {   
        PRO p;
        cin >> p.id;
        cin.ignore();
        getline(cin,p.name);
        getline(cin, p.type);
        cin >> p.year >> p.warranty;
        insertTree(T, p);
    }
}

void listProduct(Tree T, string type) 
{   if (T == NULL) return;
    listProduct(T->pLeft, type);
    if (T->info.type == type) 
    {   
        cout << T->info.id<<"\t"<<T->info.name<<"\t"<<T->info.type<<"\t"<< T->info.year<<"\t"<<T->info.warranty<<endl;
    }
    listProduct(T->pRight, type);
}

int countProduct(Tree T,int x) 
{   if (T == NULL) return 0;
    int count = 0;
    if (T->info.warranty > x) count = 1;
    return count + countProduct(T->pLeft, x) + countProduct(T->pRight, x);
}

int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin,type);
    cout<<"List of products whose type is  "<<type<<": ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T,type);

    int year;cin>>year;
    cout<<"Number of products with more than "<<year<<" years of warranty: "<<countProduct(T,year)<<endl;


	return 0;
}

