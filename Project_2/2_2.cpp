/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

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

void Quick_Sort_Rev(int a[], int left, int right)
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
    Quick_Sort_Rev(a, left, j);
    Quick_Sort_Rev(a, i, right);
}

void Sort(int *a, int n)
{
    int *b = new int[n];
    int *c = new int[n];
    int nb = 0;
    int nc = 0;

    int *d = new int[n];
    int *e = new int[n];
    int nd = 0;
    int ne = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            b[nb] = a[i];
            nb++;
            c[nc] = i;
            nc++;
        }
        else
        {
            d[nd] = a[i];
            nd++;
            e[ne] = i;
            ne++;
        }
    }
    Quick_Sort(b, 0, nb - 1);
    Quick_Sort_Rev(d, 0, nd - 1);
    for(int i = 0; i < nb; i++)
    {
        a[c[i]] = b[i];
    }
    for(int i = 0; i < nd; i++)
    {
        a[e[i]] = d[i];
    }
}

int main()
{
    int *a, n; cin >> n;
    a = new int [n];

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    Sort(a, n);
    
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }

    delete[] a;
}


