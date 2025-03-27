/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void inputMatrix(vector<vector<int>> &a, int &n)
{
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
    {
        a[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void max(vector<vector<int>> a, int n)
{
    for(int i = 0; i < n; i++)
    {
        int indexR = i;
        int indexC = 0;
        int maxV = a[i][0];
        for(int j = 0; j < n; j++)
        {
            if(maxV < a[i][j])
            {
                maxV = a[i][j];
                indexR = i;
                indexC = j;
            }
        }
        cout << "a[" << indexR << "][" << indexC << "]=" << maxV << endl;
    }
}


void output(vector<vector<int>> a, int n)
{
    cout << "Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nMaximum element of each row in the matrix:\n";
    max(a, n);
}

int main()
{
    int n;
    vector<vector<int>> a;
    inputMatrix(a, n);
    output(a, n);
}


//###INSERT CODE HERE -




