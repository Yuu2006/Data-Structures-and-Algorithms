#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int m,n;
    cin >>m>>n;
    vector<vector<int>> Dinh(m);
    vector<bool> visited(m,false);

    for (int i=0;i<n;i++) {
        int u, v;
        cin >> u >> v;
        Dinh[u].push_back(v);
        Dinh[v].push_back(u);
    }

    queue<int> open;
    open.push(0);
    visited[0]=true;

    vector<int> close;
    while (!open.empty()) {
        int u=open.front();
        open.pop();
        
        for (int v : Dinh[u]) {
            if (!visited[v]) {
                visited[v]=true;
                open.push(v);
                close.push_back(v);
            }
        }
    }

    if (close.empty()) {
        cout << "KHONG";
    } 
    else {
        sort(close.begin(), close.end());
        for (int v : close) {
            cout <<v<< " ";
        }
    }
    return 0;
}