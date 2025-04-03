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

int lengthList(List L)
{
    int length = 0;
    if(L.head == NULL) return 0;
    node *p = L.head;
    while(p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

void concate(List &L1, List L2)
{
    if(L1.head == NULL)
    {
        L1.head = L2.head;
        L1.tail = L2.tail;
        return;
    }
    if(L2.head == NULL) return;

    L1.tail->next = L2.head;
}


int main()
{
    List L1, L2;
    Init(L1);Init(L2);

    int n; cin>>n;
    inputList(L1,n);
    cout<<"Created 1st List: "<<endl;
    outputList(L1);
    cout<<endl;

    cin>>n;
    inputList(L2,n);
    cout<<"Created 2nd List: "<<endl;
    outputList(L2);
    cout<<endl;

    concate(L1,L2); // Noi L2 vao L1
    cout<<"Updated L1: "<<endl;
    outputList(L1);

    return 0;
}
