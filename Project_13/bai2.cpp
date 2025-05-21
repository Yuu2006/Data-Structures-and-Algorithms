#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph 
{
public:
    int v, e;
    vector<vector<int>> matrix;
    vector<string> names;
    map<string, int> index;
    void nhap(int v, int e) 
    {
        this->v = v;
        this->e = e;
        matrix = vector<vector<int>>(v, vector<int>(v, 0));
        names = vector<string>(v, "");
        string x, y;
        for (int i = 0; i < v; i++) 
        {
            cin >> x;
            names[i] = x;
            index[x] = i;
        }
        for (int i = 0; i < e; i++) 
        {
            cin >> x >> y;
            int indexX = index[x];
            int indexY = index[y];
            matrix[indexX][indexY] = 1;
            matrix[indexY][indexX] = 1;
        }
    }
    void xuatBacCacDinh() 
    {
        for (int i = 0; i < v; i++) 
        {
            int bac = 0;
            for (int j = 0; j < v; j++) 
            {
                if (matrix[i][j] == 1)
                    bac++;
            }
            cout << bac << " ";
        }
    }
};
int main() 
{
    Graph G;
    int v, e;
    cin >> v >> e;
    G.nhap(v, e);
    G.xuatBacCacDinh();
    return 0;
}