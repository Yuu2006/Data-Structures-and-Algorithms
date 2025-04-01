#include <iostream>

using namespace std;

void Merge(int arr[], int left, int mid, int right, int size)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;

    for (int index = 0; index < left; ++index) {
        cout << arr[index] << " ";
    }
    cout << "[ ";
    for (int index = left; index <= right; ++index) {
        cout << arr[index] << " ";
    }
    cout << "] ";
    for (int index = right + 1; index < size; ++index) {
        cout << arr[index] << " ";
    }
    cout << endl;
}

void Merge_Sort(int arr[], int left, int right, int size)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    Merge_Sort(arr, left, mid, size);
    Merge_Sort(arr, mid + 1, right, size);
    Merge(arr, left, mid, right, size);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Merge_Sort(arr, 0, n - 1, n);

    delete[] arr;
    return 0;
}