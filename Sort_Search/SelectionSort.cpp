#include <iostream>
using namespace std;

void Output(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if(a[min] != a[i])
        {
            swap(a[min], a[i]);
            Output(a, n);   
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SelectionSort(a, n);
    delete[] a;
    return 0;
}