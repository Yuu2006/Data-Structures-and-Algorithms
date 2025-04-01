/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct node
{
    int data;
    node *next;
};

struct List
{
    node *head;
    node *tail;
};

node *createNode(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void createList(List &x)
{
    x.head = NULL;
    x.tail = NULL;
}

void inputTail(List &L, int x)
{
    node *p = createNode(x);
    if(L.head == NULL)
    {
        L.head = p;
        L.tail = L.head;
        return;
    } 
    else 
    {
        L.tail->next = p;
        L.tail = p;
    }
}

void inputList(node *&N, int n)
{
    List L;
    createList(L);
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        inputTail(L, x);
    }
    N = L.head;
}

void MySort(node* &L)
{
    node *pmin, *pi, *pj;
    for (pi = L; pi->next != NULL; pi = pi->next)
    {
        pmin = pi;
        for (pj = pi->next; pj != NULL; pj = pj->next)
        {
            if (pj->data < pmin->data)
            {
                pmin = pj;
            }
        }
        swap(pi->data, pmin->data);
    }
}

void outputList(node* L)
{
    for (node* i = L; i != NULL; i = i->next)
    {
        cout << i->data << " ";
    }
}

int MySearch(node* L, int x)
{
    int index = 0;
    for(node *i = L; i != NULL; i = i->next)
    {
        index++;
        if(i->data == x) return index - 1;
    }
    return -1;
}


int main()
{
    int n; cin>>n;
    node* L=NULL;
    inputList(L,n);
    MySort(L);
    cout<<"Sorted List: ";
    outputList(L);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = MySearch(L,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

