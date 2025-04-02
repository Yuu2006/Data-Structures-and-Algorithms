/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
set
map
multi_set
unordered_map
merge
[
]
###End banned keyword*/
#include <iostream>
#include <vector>
using namespace std;

//###INSERT CODE HERE -

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a.at(i);
        if(a.at(i) > max) 
        {
            max = a.at(i);
        }
    }
    vector<int> b(max + 1, 0);
    
    for(int i = 0; i < n; i++)
    {
        b.at(a.at(i)) = 1;
    }

    for(int i = 0; i < max; i++)
    {
        if(b.at(i) == 0)
        {
            cout << i;
            return 0;
        }
    }
    cout << max + 1;
    return 0;
}
