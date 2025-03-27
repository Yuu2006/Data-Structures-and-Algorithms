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

void BubbleSort(int *a, int n)
{
    bool flag = true;
    for(int i = 0; i < n && flag == true; i++)
    {
        flag = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = true;
                Output(a, n);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    Input(a, n);
    BubbleSort(a, n);

    delete[] a;
    return 0;
}