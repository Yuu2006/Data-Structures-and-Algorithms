/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multi_set
map
unordered_map
include
###End banned keyword*/

#include <iostream>
#include <random>
using namespace std;

//###INSERT CODE HERE -

struct CA{
    char Loai[50];
    double canNang;
    char Mau[50];
    double chieuDai;
    double Tuoi;
    double TBCDaiCNang;
};

void Nhap(CA *&ca, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> ca[i].Loai;
        cin >> ca[i].canNang;
        cin >> ca[i].Mau;
        cin >> ca[i].chieuDai;
        cin >> ca[i].Tuoi;
        ca[i].TBCDaiCNang = (ca[i].canNang + ca[i].chieuDai) / 2;
    }
}

void Quick_Sort(CA *ca, int left, int right) {
    if (left >= right) return;
    
    int i = left, j = right;
    double mid = ca[(left + right) / 2].TBCDaiCNang;
    
    while (i <= j) {
        while (ca[i].TBCDaiCNang < mid) i++;
        while (ca[j].TBCDaiCNang > mid) j--;
        if (i <= j) {
            swap(ca[i], ca[j]);
            i++;
            j--;
        }
    }
    
    Quick_Sort(ca, left, j);
    Quick_Sort(ca, i, right);
}

\

int main()
{
    int n;
    cin >> n;
    CA *ca = new CA[n];
    Nhap(ca, n);

    Quick_Sort(ca, 0, n - 1);
    int k;
    cin >> k;

    cout << ca[k].Loai << " " << ca[k].canNang << " " << ca[k].Mau << " " << ca[k].chieuDai << " " << ca[k].Tuoi << endl;
    
    double xapxi;
    cin >> xapxi;
    int iGanNhat = 0;
    double kcGanNhat = abs(ca[0].TBCDaiCNang - xapxi);
    
    for(int i = 1; i < n; i++) {
        double kc = abs(ca[i].TBCDaiCNang - xapxi);
        if(kc < kcGanNhat) {
            kcGanNhat = kc;
            iGanNhat = i;
        }
    }
    cout << ca[iGanNhat].Loai << " " << ca[iGanNhat].canNang << " " << ca[iGanNhat].Mau << " " << ca[iGanNhat].chieuDai << " " << ca[iGanNhat].Tuoi << endl;

}
