/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
//###INSERT CODE HERE -
#include <iostream>
using namespace std;

int main() 
{
    int m, n;
    cin >> m >> n;
    bool **G = new bool*[m];
    for (int i = 0; i < m; i++) 
        G[i] = new bool[m]{0};
    int u, v;
    for (int i = 0; i < n; i++) 
    {
        cin >> u >> v;
        G[u][v] = 1;
    }
    int dem = 0;
    for (int i = 0; i < m; i++) 
    {
        bool coLap = true;
        for (int j = 0; j < m; j++) 
        {
            if (G[i][j] || G[j][i]) 
            {
                coLap = false;
                break;
            }
        }
        if (coLap) dem++;
    }
    cout << dem << endl;
    return 0;
}