/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;



//###INSERT CODE HERE -

void inputArray(int *&a, int &n)
{
    cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int binarySearch2(int *a, int n, int x)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid] == x)
        {
            int result = mid;
            for(int i = 0; i < n - mid; i++)
            {
                if(a[mid + i] == x)
                result = mid + i;
            }
            return result;
        }
        else if(a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// void inputArray(int*& a, int& n) {
//     cin >> n;
//     a = new int[n];
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
// }

// int binarySearch2(int* a, int n, int x) {
//     int l = 0, r = n - 1, i = -1;
//     while (l <= r) {
//         int mid = (l + r) / 2;
        
//         if (x == a[mid]) {
//             l = mid + 1;
//             i = mid;
//         }
//         else if (x < a[mid]) {
//             r = mid - 1;
//         }
//         else {
//             l = mid + 1;
//         }

//     }
//     return i;
// }

int main()
{
    int n, *a = NULL;
    inputArray(a,n); //Luu y van de tham chieu cho con tro a va n

    // nhap cac gia tri can tim, neu nhap -1 thi ket thuc viec tim kiem
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1)break;
        cout<<binarySearch2(a,n,x)<<endl;

    }

    return 0;
}

