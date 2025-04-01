/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <stack>

using namespace std;

void DecimaltoBinary(int n)
{
    stack<int> S;

//###INSERT CODE HERE -
    if(n == 0) 
    {
        cout << 0;
        return;
    }
    while(n > 0)
    {
        S.push(n % 2);
        n /= 2;
    }
    while(!S.empty())
    {
        cout << S.top();  
        S.pop();          
    }
}
int main()
{

    int n;
    cin>>n;
    DecimaltoBinary(n);
    return 0;
}



