#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> a, int n, int x)
{
    int l = 0, r = n - 1, mid, count = 0;
    while(l <= r)
    {
        count++;
        mid = (l + r) / 2;
        if(a[mid] == x)
        {
            cout << mid << endl;
            return count;
        }
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1; 
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i <n; i++)
    {
        cin >> a[i];
    }

    int x;
    cin >> x;
    cout << BinarySearch(a, n, x);
}