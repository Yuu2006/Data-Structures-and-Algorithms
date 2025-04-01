#include <iostream>
using namespace std;

void Insertion_Sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Insertion_Sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}