#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

#define INF 1000000000

class Graph 
{
public:
    int v, q;
    vector<vector<int>> matrix;
    vector<string> names;
    map<string, int> toIndex;

    void inputGraph() 
    {
        cin >> v >> q;
        matrix = vector<vector<int>>(v, vector<int>(v));
        names = vector<string>(v);
        for (int i = 0; i < v; ++i) 
        {
            cin >> names[i];
            toIndex[names[i]] = i;
        }
        for (int i = 0; i < v; ++i)
            for (int j = 0; j < v; ++j)
                cin >> matrix[i][j];
    }

    void printGraph() 
    {
        for (int i = 0; i < v; ++i) 
        {
            for (int j = 0; j < v; ++j)
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    void Dijkstra(int s, int g)
    {
        priority_queue<pair<int, int>> open;
        vector<int> close(v,0);
        vector<int> d(v,INF);
        map<int,int> parent;
        open.push({0, s});
        d[s] = 0;
        int DinhPhatTrien = 0;

        while (!open.empty()) 
        {
            int u = open.top().second;
            open.pop();

            if (close[u]) 
                continue;

            close[u] = 1;
            if (d[u] == INF) 
                break; 

            DinhPhatTrien++;
            if (u == g) 
                break;
           
            for (int i = 0; i < v; ++i)
            {
                if (matrix[u][i] > 0 && d[i] > d[u] + matrix[u][i])
                {
                    d[i] = d[u] + matrix[u][i];
                    parent[i] = u;
                    open.push({-d[i], i});
                }
            }
        }

        if (d[g] == INF) 
        {
            cout << "-unreachable-" << endl;
            cout << DinhPhatTrien << " 0" << endl;
            return;
        }

        vector<int> QuaTrinh;
        for (int i = g;i != s;i = parent[i])
            QuaTrinh.push_back(i);

        QuaTrinh.push_back(s);
        reverse(QuaTrinh.begin(), QuaTrinh.end());

        for (int i = 0; i < QuaTrinh.size(); ++i) 
        {
            cout << names[QuaTrinh[i]];
            if (i != QuaTrinh.size() - 1) 
                cout << " ";
        }
        cout << endl;
        cout << DinhPhatTrien << " " << d[g] << endl;
    }

    //dd
    void printQuaTrinh() 
    {
        for (int i = 0; i < q; ++i) 
        {
            string start, end;
            cin >> start >> end;
            Dijkstra(toIndex[start], toIndex[end]);
        }
    }
};

int main() 
{
    Graph g;
    g.inputGraph();
    g.printQuaTrinh();
    return 0;
}