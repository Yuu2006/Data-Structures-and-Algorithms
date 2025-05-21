#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int e;
    cin >> e;
    set<string> Dinh;
    set<pair<string, string>> Canh;
    for (int i = 0; i < e; i++) {
        string u, v;
        cin >> u >> v;
        if (u == v) continue;
        Dinh.insert(u);
        Dinh.insert(v);
        Canh.insert({u, v});
    }
    int n = Dinh.size();
    int CanhToiThieu = n * (n - 1);
    if ((int)Canh.size() == CanhToiThieu)
        cout << "TRUE";
    else
        cout << "FALSE";

    return 0;
}