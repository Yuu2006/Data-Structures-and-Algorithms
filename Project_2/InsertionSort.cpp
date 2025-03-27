#include <iostream>

using namespace std;

void Input(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void Output(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        int key = a[i];
        int j;
        for(j = i - 1; j >= 0 && a[j] > key; j--)//tim vi tri phu hop de chen
        {
            a[j + 1] = a[j];
            Output(a, n);
        }
        a[j + 1] = key;
        Output(a, n);

        // while(j >= 0 && a[j] > key)
        // {
        //     a[j + 1] = a[j];
        //     j--;
        //     Output(a, n);
        // }
        // a[j + 1] = key;
        // if(i != 0)
        // {
        //     Output(a, n);
        // }
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    Input(a, n);
    InsertionSort(a, n);

    delete[] a;
    return 0;
}