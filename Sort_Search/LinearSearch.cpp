#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> a, int n, int k)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a.at(i) == k)
        {
            return i;
        }
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
    if (linear_search(a, n, k) != -1)
    {
        cout << "Vi tri chua phan tu " << k << " la " << linear_search(a, n, k);
    }
    else
    {
        cout << "Khong ton tai phan tu " << k << " trong mang.";
    }
}