/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nhapMang(vector<int> &a, int &n)
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void xuatMang(vector<int> a, int n)
{
    cout << "Mang vua nhap:\n";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int schan1= a[0];
    int vt1 = -1;
    int schan2= a[n - 1];
    int vt2 = -1;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            schan1 = a[i];
            vt1 = i;
            cout << schan1 << " la so chan dau tien, co chi so " << vt1 << " trong mang\n";
            break;
        }
    }
    if(vt1 == -1)
    {
        cout << "Mang khong co so chan";
        return;
    }
    else
    {
        for(int i = n - 1; i >= 0; i--)
        {
            if(a[i] % 2 == 0)
            {
                schan2 = a[i];
                vt2 = i;
                cout << schan2 << " la so chan cuoi cung, co chi so " << vt2 << " trong mang\n";
                break;
            }
        }
        int max = schan1;  
        for(int i = 0; i < n; i++)
        {
            if(a[i] % 2 == 0 && a[i] > max)
            {
                max = a[i];
            }
        }
        cout << "So chan lon nhat: " << max; 
    }
}

int main()
{
    int n = 100000;
    vector<int> a(n);
    nhapMang(a, n);
    xuatMang(a, n);
    return 0;
}

//###INSERT CODE HERE -
