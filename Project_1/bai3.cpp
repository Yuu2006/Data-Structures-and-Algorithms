#include <iostream>

using namespace std;

int swapCount = 0;

void Nhap(int *a,int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void SapXep(int *a, int left, int right)
{
    if(left >= right)
        return;
    int i = left, j = right;
    int mid = a[(left + right) / 2];
    while(i <= j)
    {
        while(a[i] > mid) i++;
        while(a[j] < mid) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            swapCount++;
            i++;
            j--;
        }
    }
    SapXep(a, left, j);
    SapXep(a, i, right);
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    Nhap(a, n);
    SapXep(a, 0, n - 1);
    
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << "Number of times to swap 2 numbers: " << swapCount << endl;

    return 0;
}