/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -
struct node
{
    int info;
    node *next;
};

struct List 
{
    node *head;
    node *tail;
};

node *createNode(int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void Init(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

void inputTail(List &L, int x)
{
    node *p = createNode(x);
    if(L.head == NULL)
    {
        L.head = p;
        L.tail = L.head;
        return;
    } 
    else 
    {
        L.tail->next = p;
        L.tail = p;
    }
}

void inputList(List &L, int n)
{
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        inputTail(L, x);
    }
}

void outputList(List L)
{
    node *p = L.head;
    if(p == NULL)
    {
        cout << "List is empty";
        return;
    }

    while(p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

node *findElement(List L, int i)
{
    if(L.head == NULL)
    {
        cout << "List is empty";
        return NULL;
    }
    i--;
    node *p = L.head;
    while(i != 0)
    {
        p = p->next;
        i--;
        if(p == NULL)
        {
            cout << "The index is invalid";
            return NULL;
        }
    }
    return p;
}

int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<": ";
    node *p = findElement(L,i);
    if(p) cout<<p->info;


    return 0;
}
