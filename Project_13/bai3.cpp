#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0;j < n; j++)
        {
            if(flag == 0 && a[i][j]==1)
            {
                cout << i + 1 <<"->";
                flag++;
            }
            if(a[i][j] == 1)
            {
                cout << j+1 <<" ";
            }
        }
        if (flag != 0)
            cout << endl;
        flag = 0;
    }
    return 0;

}