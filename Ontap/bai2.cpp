/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
define
###End banned keyword*/


#include<map>
#include<set>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int main()
{

//###INSERT CODE HERE -
    int n, k;
    cin >> k >> n;

    map<string, int> dem;
    list<string> recent;

    for(int i = 0; i < n; i++)
    {
        string sdt;
        cin >> sdt;

        recent.remove(sdt);
        recent.push_front(sdt);

        dem[sdt]++;
    }

    int in = 0; 
    for(auto it = recent.begin(); it != recent.end() && in < k; it++, in++)
    {
        cout << *it ;
        if(dem[*it] > 1)
        {
            cout << "(" << dem[*it] << ") ";
        }
        else cout << " ";
    }

    return 0;

}

