#include <functional>
#include <iostream>
#include <set>
//sap xep mang da cho

using namespace std;

int main()
{
    set<int, greater<int>> a = {1, 2, 3,5, 9};
    //less<int> sap xep tang dan
    //greater<int> sap xep giam dan
    a.insert(6); // Them
    a.erase(1); // Xoa
    //a.clear(); // Xoa het
    //int length = a.size();

    for(auto i : a)
    {
        cout << i << " ";
    }
}