#include <iostream>
using namespace std;

struct Point 
{
    double x, y, z;
};

int compare(Point a, Point b)
{
    if (a.x > b.x) return 1;
    if (a.x < b.x) return -1;
    if (a.y > b.y) return 1;
    if (a.y < b.y) return -1;
    if (a.z > b.z) return 1;
    if (a.z < b.z) return -1;

    return 0;
} 

int BinarySearch(Point *a, int n, Point b)
{
    int l = 0, r = n - 1, mid, count = 0;
    while(l <= r)
    {
        count++;
        mid = (l + r)/2;
        int x = compare(a[mid], b);
        if(x == 0) return count;
        else if(x < 0) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main()
{
    int n; cin >> n;
    Point *A = new Point[n];
    for(int i = 0; i < n; i++)
    {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }

    int m; cin >> m;
    Point *B = new Point[m];
    for(int i = 0; i < m; i++)
    {
        cin >> B[i].x >> B[i].y >> B[i].z;
        int kq = BinarySearch(A, n, B[i]);
        if(kq == -1)
        {
            cout <<"KHONG\n";
        }
        else cout << kq << endl;
    }
    return 0;
}