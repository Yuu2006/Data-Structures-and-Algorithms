/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
map
set
###End banned keyword*/


#include<vector>
#include<iostream>
using namespace std;

int main()
{

//###INSERT CODE HERE -
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int max = 0;
    for(int i = 0; i < n; i++) 
    {
        if(a[i] >= 0 && a[i] > max)
            max = a[i];
    }
    
    vector<bool> check(max + 2, false);
    for(int i = 0; i < n; i++) 
    {
        if(a[i] >= 0 && a[i] <= max + 1)
            check[a[i]] = true;
    }
    
    int mex = 0;
    while(mex < check.size() && check[mex]) 
    {
        mex++;
    }
    
    cout << mex;
    return 0;

}



