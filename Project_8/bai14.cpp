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
    node *pHead;
    node *pTail;
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
    L.pHead = NULL;
    L.pTail = NULL;
}

void inputTail(List &L, int x)
{
    node *p = createNode(x);
    if(L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
        return;
    } 
    else 
    {
        L.pTail->next = p;
        L.pTail = p;
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
    node *p = L.pHead;
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
    if(L.pHead == NULL) return 0;
    node *p = L.pHead;
    while(p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

node *swapData(List L, int x, int y)
{
    if(L.pHead == NULL)
    {
        return NULL;
    }
    node *p = L.pHead;
    node *nodeX = NULL;
    node *nodeY = NULL;
    while(p != NULL)
    {   
        if(p->info == x) nodeX = p;
        if(p->info == y) nodeY = p;
        p = p->next;
    }
    if(nodeX == NULL || nodeY == NULL) return NULL;
    int temp = nodeX->info;
    nodeX->info = nodeY->info;
    nodeY->info = temp;
    return nodeX;
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapData(L,x,y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if(p) // co hoan vi
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
