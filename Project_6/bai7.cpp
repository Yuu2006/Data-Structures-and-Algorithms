/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -
struct Stack
{
    char arr[MAX];
    int n;
};

void Init(Stack &S)
{
    S.n = 0;
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

char Top(Stack S) 
{
    if(isEmpty(S))
        return NULLDATA;
    return S.arr[S.n - 1];
}

char Pop(Stack &S)
{
    if(isEmpty(S))
        return NULLDATA;
	S.n--;
    return S.arr[S.n];
}

int isValid(string expr)
{
    Stack S;
    Init(S);
	int length = expr.length();
    for(int i = 0; i < length; i++)
    {
        if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
            Push(S, expr[i]);
        else
        {
            if(isEmpty(S))
                return 0;
            char top = Top(S);

            if((expr[i] == ')' && top == '(') || (expr[i] == ']' && top == '[') || (expr[i] == '}' && top == '{') )
            {
                Pop(S);
            }
            else return 0;
        }
    }

    if(isEmpty(S)) return 1;
    else return 0; 

}


int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}



