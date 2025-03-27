#include <iostream>
#include <algorithm>

using namespace std;

int BinarySearch(int *a, int n, int k)
{
    int l = 0, r = n - 1, mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(a[mid] == k) return mid + 1;
        else if(a[mid] < k) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

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

int main(){
    int *a = new int[10000000];

    int input;
    int index = 0;
    do
    {
        cin >> input;
        if(input == 1)
        {
            cin >> a[index];
            index++;
            Quick_Sort(a, 0, index - 1);
        }  
        else if(input == 2)
        {
            int idCheck;
            cin >> idCheck;
            cout << BinarySearch(a, index, idCheck) << endl;
        }
    }while(input != 0);
    delete[] a;
    return 0;
}