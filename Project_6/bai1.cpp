/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <stack>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

//###INSERT CODE HERE -

void Init(Stack &S)
{
    S.n = 0;
    // n = 0 
    // a = {-1 -1 -1 -1 -1 -1}
    for(int i = 0; i < MAX; i++)
        S.arr[i] = NULLDATA;
}

bool isEmpty(Stack S)
{
    return S.n == 0;   
}

bool isFull(Stack S)
{
    return S.n >= MAX;
}

void Push(Stack &S, int x)
{
    if(isFull(S)) 
        return;
    S.arr[S.n] = x;
    S.n++;
    return;
}

int Top(Stack S)
{
    if(isEmpty(S))
        return NULLDATA;
    return S.arr[S.n - 1];
}

void Pop(Stack &S)
{
    if(isEmpty(S))
        return;
    S.arr[S.n - 1] == NULLDATA;
    S.n--;
}

void printStack(Stack S)
{
    if(isEmpty(S))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for(int i = 0; i < S.n; i++)
        cout << S.arr[i] << " ";
    cout << endl;
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    return 0;
}




