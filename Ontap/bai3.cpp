/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
->
###End banned keyword*/

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;




struct Hash
{
    int hashtable[M];
    int n; //số phần tử hiện có trên bảng băm
};
int hashfunc (int key)
{	return (key % M); 	}

void initHash(Hash &H)
{
    H.n = 0;
    for(int i = 0; i < M; i++)
    {
        H.hashtable[i] = NULLKEY;
    }
}

int insertHash(Hash &H, int x)
{
    // Nếu bảng băm đã đầy
    if(H.n >= M) return -1;
    
    int k = hashfunc(x);
    
    // Nếu vị trí trống, thêm vào
    if(H.hashtable[k] == NULLKEY) {
        H.hashtable[k] = x;
        H.n++;
        return k;
    }
    
    // Nếu bị xung đột, thử băm lại tối đa M-1 lần với dò bậc 2
    for(int j = 1; j < M; j++) {
        // Công thức dò bậc 2: fj(key) = (f(key) + j^2 + j) % M
        int pos = (k + j*j + j) % M;
        if(H.hashtable[pos] == NULLKEY) {
            H.hashtable[pos] = x;
            H.n++;
            return pos;
        }
    }
    
    // Không thể thêm được
    return -1;
}

// Duyệt và in bảng băm
void traverseAllHash(Hash H) {
    for(int i = 0; i < M; i++) {
        cout << i;
        if(H.hashtable[i] != NULLKEY) {
            cout << " --> " << H.hashtable[i];
        }
        cout << endl;
    }
}

//###INSERT CODE HERE -
int main()
{
    Hash H;
    initHash(H);
    vector<int> b;
    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;        
        int k=insertHash(H,x);// them 1 gia tri du lieu vao bang bam       
        if(k==-1) b.push_back(x); // neu khong them duoc thi bo vao vector, de khi can thi co the xu ly nhung so nay
    }
    cout<<"\nBang bam:"<<endl;
    traverseAllHash(H);
    if(!b.empty())cout<<"Co "<<b.size()<<" gia tri khong them duoc";
    return 0;
}

