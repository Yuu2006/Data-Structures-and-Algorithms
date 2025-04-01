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

struct Point2D
{
    int x;
    int y;
};

int Compare2Points(Point2D point1, Point2D point2)
{
    if(point1.x > point2.x) return 1;
    else if(point1.x < point2.x) return -1;
    else
    {
        if(point1.y > point2.y) return -1;
        else if(point1.y < point2.y) return 1;
    }
    return 0;
}

void Quick_Sort(Point2D *a, int left, int right)
{
    if (left >= right)
        return;
    int i = left, j = right;
    Point2D mid = a[(left + right) / 2];
    while (i <= j)
    {
        while (Compare2Points(a[i], mid) < 0) i++;
        while (Compare2Points(a[j], mid) > 0) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    Quick_Sort(a, left, j);
    Quick_Sort(a, i, right);
}

int main()
{
    int n;
    cin >> n;
    Point2D *points = new Point2D[n];

    for(int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    Quick_Sort(points, 0, n - 1);  
    
    for(int i = 0; i < n; i++)
    {
        cout << points[i].x << " " << points[i].y << endl;
    }

    delete[] points;
    return 0;
}