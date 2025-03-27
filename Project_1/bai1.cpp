#include <iostream>

using namespace std;

void Input(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int BinarySearch(int *a, int n, int k)
{
    int l = 0, r = n - 1, mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(a[mid] == k)
        {
            return mid;
        }
        else if(a[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

void Result(int *a,int *b, int n, int m)
{
    for(int i = 0; i < m; i++)
    {
        cout << BinarySearch(a, n, b[i]) << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    Input(a, n);
    int m;
    cin >> m;
    int *b = new int [m];
    Input(b, m);
    Result(a, b, n, m);
    return 0;
}