/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

int calculateHIndex(int *citation, int n);

//###INSERT CODE HERE -	
void Quick_Sort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int i = left, j = right;
    int mid = a[(left + right) / 2];
    while (i <= j)
    {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
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
	int* citation;
	int n;
	int i;
	cin >> n;
	//cout << n << endl;
	citation = new int[n];

	for (i = 0; i < n; i++)
		cin >> citation[i];

	cout << calculateHIndex(citation, n);
	return 0;


}

int calculateHIndex(int *citation, int n)
{
	Quick_Sort(citation, 0, n - 1);
	int count = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(citation[i] >= count)
		{
			count++;
		}
		else if(citation[i] < count)
		{
			return count;
		}
	}
	return count;
}
