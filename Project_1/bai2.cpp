#include <iostream>

using namespace std;

void Nhap(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int TimKiem(int *a, int n, int k)
{
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] == k)
        {
            return i;
        }
    }
    return -1;
}

// This is the template: //

int main()
{
    int n;
    cin >> n;
    int *a = new int [n];
    Nhap(a, n);
    int k = 0;
    do
    {
        cin >> k;
        if(k != -1)
        {
            cout << TimKiem(a, n, k) << " ";
        }
    }while(k != -1);
    return 0;
}