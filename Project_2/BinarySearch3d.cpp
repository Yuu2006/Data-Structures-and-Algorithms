#include <iostream>

using namespace std;

struct Point{
    double x, y, z;
};

void Input(Point *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }
}

int compare2Points(Point A, Point B)
{
    if(A.x > B.x) return 1;
    else if(A.x < B.x) return -1;
    if(A.y > B.y) return 1;
    else if(A.y < B.y) return -1;
    if(A.z > B.z) return 1;
    else if(A.z < B.z) return -1;
    return 0;
}

int BinarySearch(Point *A, int n, Point k)
{
    int l = 0, r = n - 1, mid, steps = 0;
    while(l <= r)
    {
        steps++;
        mid = (l + r) / 2;
        int compare = compare2Points(A[mid], k); 
        if(compare == 0) return steps;
        else if(compare < 0) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    Point *A = new Point[n];
    Input(A, n);
    
    int m;
    cin >> m;
    Point *B = new Point[m];
    Input(B, m);

    for(int i = 0; i < m; i++)
    {
        int Final = BinarySearch(A, n, B[i]);
        if(Final != -1)
            cout << Final << "\n";
        else cout << "KHONG\n";
    }
    delete[] A;
    delete[] B;
    return 0;
}