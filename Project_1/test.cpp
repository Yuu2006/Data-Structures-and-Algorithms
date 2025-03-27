#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void Output(int *a, int n)
{
    cout << "Mang sau khi sap xep: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
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
        }
    }
}

void QuickSort(int a[], int left, int right)
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
    QuickSort(a, left, j);
    QuickSort(a, i, right);
}

void InsertionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
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
    return l;
}

void BinaryInsertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int pos = BinarySearch(a, i, x);
        for (int j = i - 1; j >= pos; j--)
        {
            a[j + 1] = a[j];
        }

        a[pos] = x;
    }
}

void InterchangeSort(int a[], int n)
{	
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
	        if(a[i] > a[j]) 
		        swap(a[i], a[j]);
}

void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void mainfunction(int *&a, int n)
{
    
    clock_t begin = clock();
    do
    {
        cout << "Please enter a number in range 1 .. 100,000,000\n";
        cin >> n;
        if(n > 1 && n < 100000000)
        {
            break;
        }
    } while(n > 1 || n < 100000000);
    a = new int [n];
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 4001 - 2000;
    }

    cout << "Chon thuat toan :\n";
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Quick Sort\n";
    cout << "4. Binary Insertion Sort\n";
    cout << "5. Interchange Sort\n";
    cout << "6. Bubble Sort\n";

    int option;
    cin >> option;
    switch(option)
    {
        case 1:
            SelectionSort(a, n);
            Output(a,n);
            break;
        case 2:
            InsertionSort(a, n);
            Output(a,n);
            break;
        case 3:
            QuickSort(a, 0, n - 1);
            Output(a,n);
            break;
        case 4:
            BinaryInsertionSort(a, n);
            Output(a,n);
            break;
        case 5:
            InterchangeSort(a, n);
            Output(a, n);
            break;
        case 6:
            BubbleSort(a, n);
            Output(a, n);
            break;
    }

    clock_t end = clock();
    cout<< "Time run: " <<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    cout << "Do you want to continue(y/n):";
    char opt;
    cin >> opt;
    switch(opt)
    {
        case 'y':
            mainfunction(a, n);
            break;
        case 'n':
            cout << "Chuong trinh ket thuc.";
            break;
    }
}

int main()
{
    int n;
    int *a = NULL;
    mainfunction(a, n);
    delete[] a;
    return 0;
}
