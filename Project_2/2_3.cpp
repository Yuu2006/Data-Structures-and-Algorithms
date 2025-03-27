/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>


//###INSERT CODE HERE -
using namespace std;

void Merge2Arrays(int *a, int *b, int n, int m)
{
    cin >> n >> m;
    a = new int[n];
    b = new int[m];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int r = n + m;
    int *c = new int[r];
    int na = 0, nb = 0, nc = 0;
    while(na < n && nb < m)
    {
        if(a[na] <= b[nb])
        {
            c[nc] = a[na];
            na++;
        }
        else
        {
            c[nc] = b[nb];
            nb++;
        }
        nc++;
    }
    while (na < n)
    {
        c[nc] = a[na];
        na++;
        nc++;
    }
    
    while (nb < m)
    {
        c[nc] = b[nb];
        nb++;
        nc++;
    }
    for(int i = 0; i < n + m; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 0, m = 0, T;
    int *a = NULL, *b = NULL;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        Merge2Arrays(a, b, n, m);
    }
}
