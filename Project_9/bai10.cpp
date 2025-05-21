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
    node *pNext;
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
    p->pNext = NULL;
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
        L.pTail->pNext = p;
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
        p = p->pNext;
    }
}

void moveLastToFront(List &L)
{
    if(L.pHead == NULL || L.pHead == L.pTail) return;
    node *secondLast = L.pHead;
    while(secondLast->pNext != L.pTail)
    {
        secondLast = secondLast->pNext;
    }
    L.pTail->pNext = L.pHead;   // gan head vao sau phan tu cuoi
    L.pHead = L.pTail;          // gan head = phann tu cuoi
    secondLast->pNext = NULL;   // xoa phan tu cuoi
    L.pTail = secondLast;       // phan tu cuoi = so ke cuoi 
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"Updated List after moving the last element to front of L: "<<endl;
    outputList(L);
    return 0;
}
