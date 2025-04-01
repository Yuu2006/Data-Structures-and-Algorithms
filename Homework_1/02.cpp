/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
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

int BinarySearch(int *a, int n, int x)
{
    int l = 0, r = n - 1, mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(a[mid] == x) return mid;
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Quick_Sort(a, 0, n - 1);

    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
        if(BinarySearch(a, n, b[i]) != -1)
        {
            cout << "YES" << endl;
        }
        else cout << "NO\n";
    }
}