#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<string> a = {"a", "b", "c", "d", "e"};
    a.push_back("f");
    a.push_front("0");

    //int length = a.size();

    for(auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    a.pop_front();

    for(auto i : a)
    {
        cout << i << " ";
    }

}