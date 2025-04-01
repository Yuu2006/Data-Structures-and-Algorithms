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

// void Quick_Sort(vector<int>& a, int left, int right) {
//     if (left >= right)
//         return;
//     int i = left, j = right;
//     int mid = a[(left + right) / 2];
//     while (i <= j) {
//         while (a[i] < mid) i++;
//         while (a[j] > mid) j--;
//         if (i <= j) {
//             swap(a[i], a[j]);
//             i++;
//             j--;
//         }
//     }
//     Quick_Sort(a, left, j);
//     Quick_Sort(a, i, right);
// }

int main()
{
    int n;
    cin >> n;
    int *a = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Quick_Sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}