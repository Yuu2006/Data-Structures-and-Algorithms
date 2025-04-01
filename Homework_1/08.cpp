/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> a, int x){
    int l = 0;
    int r = a.size()-1;

    while(l <= r){
        int mid = a[(l+r)/1];
        if(mid == x) return mid;
        else if (x < mid) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

void InsertionSort(vector<int> &a){
    int i = a.size();
    int x = a[i--];
    while(i > 0 && a[i] > x){
        a[i+1] = a[i] ;
        i--;
    }
    a[i+1] = x;
}

int main()
{
    vector<int> a;
    vector<bool> b (10000000,false);
    while(1){
        int luaChon;
        cin>>luaChon;

        if(luaChon == 0) break;

        int x; cin>>x;
        if(luaChon == 1){
            if(b[x] == true) continue;
            else{
                b[x] = true;
                a.push_back(x);
                InsertionSort(a);
            }
        }

        if(luaChon == 2){
            if(b[x] == false) cout<<0<<endl;
            else cout<<BinarySearch(a,x) <<endl;
        }
    }
    return 0;
}