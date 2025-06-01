/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
###End banned keyword*/

//###INSERT CODE HERE -

#include <iostream>
using namespace std;

struct Point
{
    int x, y, z;
};

int compare(Point A, Point B)
{
    if(A.x != B.x) return A.x < B.x;  
    if(A.y != B.y) return A.y > B.y;    
    return A.z < B.z;                
}

void swapPoint(Point &A, Point &B)
{
    Point temp = A;
    A = B;
    B = temp;
}

void QuickSort(Point *P, int l, int r)
{
    if(l >= r) 
    {
        return;
    }

    int i = l, j = r;
    Point mid = P[(i+j)/2];
    while(i <= j)
    {
        while(compare(P[i], mid)) i++;
        while(compare(mid, P[j])) j--;
        if(i <= j)
        {
            swapPoint(P[i], P[j]);
            i++;
            j--;
        }
    }

    QuickSort(P, l, j);
    QuickSort(P, i, r);
}

int main()
{
    int n; cin >>n;
    Point *P = new Point[n];
    for(int i = 0; i < n; i++)
    {
        cin >> P[i].x >> P[i].y >> P[i].z;
    }
    QuickSort(P, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << P[i].x << " " << P[i].y << " " << P[i].z << endl;
    }
}