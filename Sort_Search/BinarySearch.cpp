#include <iostream>
#include <vector>
using namespace std;

int Binary_Search(vector<int> a, int n, int k)
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a.at(mid) == k)
            return mid;
        else if (a.at(mid) < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    int n, k;
    cout << "Nhap so phan tu vector chua duoc: ";
    cin >> n;
    vector<int> a;
    cout << "Nhap vector: " << endl;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        a.push_back(val);
    }
    cout << "Nhap phan tu muon tim kiem: ";
    cin >> k;

    if (Binary_Search(a, n, k) != -1)
    {
        cout << "Vi tri chua phan tu " << k << " la " << Binary_Search(a, n, k);
    }
    else
    {
        cout << "Khong ton tai phan tu " << k << " trong mang.";
    }
}