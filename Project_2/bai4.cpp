/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

void inputArray(int *&a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void Merge(int *a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = a[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            ++i;
        }
        else
        {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        a[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        a[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void MergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

void outputArray(int *a, int n)
{
    for(int i = 0; i < n ; i++)
    {
        cout << a[i] << " ";
    }
}

int binarySearch(int *a, int n, int l, int r, int x)
{
    int mid = (l + r) / 2;
    if(l > r) return -1;
    if(a[mid] == x) return mid;
    else if(a[mid] < x) return binarySearch(a, n, mid + 1, r, x);
    else if(a[mid] > x) return binarySearch(a, n, l, mid - 1, x);
    return -1;
}


int main()
{
    int n; cin>>n;
    int *a = new int[n];
    inputArray(a,n);
    MergeSort(a,0,n-1);
    cout<<"Sorted Array: ";
    outputArray(a,n);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = binarySearch(a,n,0,n-1,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

