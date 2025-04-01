/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -

using namespace std;

void Quick_Sort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int i = left, j = right;
    int mid = a[(left + right) / 2];
    while (i <= j)
    {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
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

void EvenSort(int *a, int n)
{
    int *b = new int[n];
    int *c = new int[n];
    int nb = 0;
    int nc = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            b[nb] = a[i];
            nb++;
        }
        else
        {
            c[nc] = a[i];
            nc++;
        }
    }
    Quick_Sort(b, 0, nb - 1);
    for(int i = 0; i < nb; i++)
    {
        a[i] = b[i];
    }

    Quick_Sort(c, 0, nc - 1);
    for(int i = 0; i < nc; i++)
    {
        a[nb + i] = c[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    EvenSort(a, n);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << "\n";
    }
}
