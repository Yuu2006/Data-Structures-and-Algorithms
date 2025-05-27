#include <iostream>
using namespace std;

#define M 10
#define NULLKEY -1

struct Hash 
{
    int n;
    int data[M];
};

void initHash(Hash &H)
{
    H.n = 0; 
    for(int i = 0; i < M; i++)
        H.data[i] = NULLKEY;
}

int HashFunc(int x)
{
    return x % M;
}

void insertHash(Hash &H, int x)
{
    if(H.n >= M)
    {
        cout << "Bang bi day, khong them duoc";
        return;
    }
    int index = HashFunc(x);
    int start = index;
    int i = 0;
    while(H.data[index] != NULLKEY)
    {
        i++;
        index = (start + i * i) % M;
        if(index == start)
        {
            cout << "Bang bi day, khong them duoc";
            return;
        }
    }
    H.data[index] = x;
    H.n++;
    return;
}

void traverseAllHash(Hash H)
{
    for(int i = 0; i < M; i++)
    {
        if(H.data[i] == -1)
            cout << i << endl;
        else
            cout << i << "-->" << H.data[i] << endl;
    }
}

int main()
{
    Hash H;
    initHash(H);

    int n, x; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        cout << "\nInsert " << x;
        insertHash(H, x);
    }
    cout << "\nCreated Hash: \n";
    traverseAllHash(H); 
    return 0;
}