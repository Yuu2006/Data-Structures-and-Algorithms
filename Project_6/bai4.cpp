/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

//###INSERT CODE HERE -

struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead;
};

void Init(Stack &S)
{
    S.pHead = NULL;
}

bool isEmpty(Stack S)
{
    return S.pHead == NULL;
}

void Push(Stack &S, int x)
{
    node *p = new node;
    p->info = x;
    p->next = S.pHead;
    S.pHead = p;
}

int Pop(Stack &S)
{
    if(isEmpty(S)) return -1;
    node *p = S.pHead;
    int x = p->info;
    S.pHead = p->next;// luu phan tu dau tien thanh phan tu thu 2
    delete p; // xoa
    return x;
}

void printStack(Stack S)
{
    if(isEmpty(S)) 
    {
        cout << "Stack is Empty";
        return;
    }
    node *p = S.pHead;
    while(p != NULL)
    {
        cout << p->info;
        p = p->next;
    } 
    cout << endl;
}

void DecimaltoBinary1(int n, Stack &S) {
    if (n == 0) 
    {
        Push(S, 0);
        return;
    }
    while (n > 0) 
    {
        Push(S, n % 2); 
        n /= 2;        
    }
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

