/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
<
>
###End banned keyword*/

#include <iostream>
using namespace std;



//###INSERT CODE HERE -
int getMax(int *a, int n)
{
    int maxValue = a[0];
    int i = 1;
    while(n - 2 != 0)
    {
        maxValue = max(maxValue, a[i]);
        i++;
        n--;
    }
    return maxValue;
}
void countSort(int *&a, int n, int e)
{
    int *output = new int [n];
    int count[10] = { 0 };

    int na = n, i = 0;
    while(na)
    {
        count[(a[i] / e) % 10]++;
        i++;
        na--;   
    }

    i = 1, na = 10;
    while(na - 1)
    {
        count[i] += count[i - 1];
        na--;
        i++;
    }

    i = n - 1, na = n;
    while (na) {
        output[count[(a[i] / e) % 10] - 1] = a[i];
        count[(a[i] / e) % 10]--;
        i--;
        na--;
    }

    i = 0, na = n;
    while (na) {
        a[i] = output[i];
        na--;
        i++;
    }
    delete[] output;
}

void my_sort(int *a, int n)
{
    int m = getMax(a, n);
    for (int e = 1; m / e > 0; e *= 10)
        countSort(a, n, e);
}

int main(){
    int n;
    cin >> n;

    int *A = new int[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    my_sort (A, n);

    for(int i = 0; i < n; i++){
        cout << A[i] << " " ;
    }
}
