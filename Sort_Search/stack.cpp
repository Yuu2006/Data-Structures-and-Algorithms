#include <iostream>
#include <stack>

using namespace std;

struct Stack{
    int a[1000];
    int t;
};

void createStack(Stack &s)
{
    
}

int main()
{
    stack<string> a;

    a.push("hello");
    a.push("hi");
    a.push("bonjour");
    cout << a.top();
    cout << endl;
    a.pop();
    cout << a.top();
}