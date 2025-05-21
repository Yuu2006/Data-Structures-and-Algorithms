/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
###End banned keyword*/

//###INSERT CODE HERE -

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    map<int, int> b;
    int mex = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]] = 1;
    }
    
    for(int i = 0; ; i++)
    {
        if(b[i] != 1)
        {
            mex = i;
            break;
        }
    }
    cout << mex;
    
    return 0;
}