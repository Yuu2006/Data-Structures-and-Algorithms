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

    queue<int> q;
    q.push(0);
    visited[0]=true;

    vector<int> CoTheDen;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        
        for (int v : Dinh[u]) {
            if (!visited[v]) {
                visited[v]=true;
                q.push(v);
                CoTheDen.push_back(v);
            }
        }
    }

    if (CoTheDen.empty()) {
        cout << "KHONG";
    } 
    else {
        sort(CoTheDen.begin(), CoTheDen.end());
        for (int v : CoTheDen) {
            cout <<v<< " ";
        }
    }
    return 0;
}