/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <stack>
#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -

struct Stack
{
	int arr[MAX];
	int n;
};

void Init(Stack &S)
{
    S.n = 0;
    for(int i = 0; i < MAX; i++)
    {
        S.arr[i] = NULLDATA;
    }
}

bool isEmpty(Stack S)
{
    return S.n == 0;   
}

bool isFull(Stack S)
{
    return S.n >= MAX;
}

void Push(Stack &S, char x)
{
    if(isFull(S)) 
        return;
    S.arr[S.n] = x;
    S.n++;
    return;
}

char Pop(Stack &S) 
{
    if (isEmpty(S))
        return NULLDATA;
    S.n--;
    return S.arr[S.n];
}

bool isValid(string expr)
{
	Stack S;
	Init(S);
	int length = expr.length();
	for(int i = 0; i < length; i++)
	{
		if(expr[i] == '(')
		{
			Push(S, expr[i]);
		}
		else if(expr[i] == ')')
		{
			if(isEmpty(S))
			{
				return false;
			}
			else Pop(S);
		}
	}
	return isEmpty(S);
}

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}



