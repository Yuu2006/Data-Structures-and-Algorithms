/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;




int main()
{
//###INSERT CODE HERE -
    string s;
    getline(cin, s);

    if(s.empty())
    {
        cout << "Chuoi rong";
        return 0;
    }

    map<char, int> Dem;
    for(char i : s)
    {
        Dem[i]++;
    }

    for(char i : s)
    {
        if(Dem[i] > 0)
        {
            cout << i << ": " << Dem[i] << endl;
            Dem[i] = 0;
        }
    }

    return 0;
}

