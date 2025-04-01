#include <iostream>

using namespace std;


void Quick_Sort(int a[], int left, int right)
{
    if (left >= right)
    return;
int i = left, j = right;
    int mid = a[(left + right) / 2];
    while (i <= j)
    {
        while (a[i] > mid) i++;
        while (a[j] < mid) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    Quick_Sort(a, left, j);
    Quick_Sort(a, i, right);
}


void deleteArray(int *&a, int &n)
{
    if (n <= 0) return;
    Quick_Sort(a, 0, n - 1);
    int max = a[0];
    int *b = new int[n];
    int nb = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != max)
        {
            b[nb] = a[i];
            nb++;
        }
    }
    
    for(int i = 0; i < nb; i++)
    {
        a[i] = b[i];
    }
    n = nb;
    
    delete[] b;
}

void Output(int *a, int n)
{
    cout << n << "\n";
    Quick_Sort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << "\n";
    }
    cout << endl;
}

int main()
{
    int n;
    int size = 0;
    int *a = new int[100000];
    while(true)
    {
        cin >> n;
        if (n == -1)
        {
            deleteArray(a, size);
        }
        else if (n == -2)
        {
            Output(a, size);
            break;
        }
        else
        {
            a[size++] = n;
        }
    }

    delete[] a;
    return 0;
}