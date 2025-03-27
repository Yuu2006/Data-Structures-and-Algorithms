#include <iostream>

using namespace std;

void Nhap(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void Xuat(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void XuLy(int *a, int n, int left, int right)
{
    int i = left;
    int j = right;
    int mid = a[(left + right)/2];
    while(i <= j)
    {
        while(a[i] < mid) i++;
        while(a[j] > mid) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            j--;
            i++;
            Xuat(a, n);
            cout << endl; 
        }
    }
    XuLy(a, n, left, j);
    XuLy(a, n, i, right);
}


int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    Nhap(a, n);
    XuLy(a, n, 0, n - 1);
    return 0;
}