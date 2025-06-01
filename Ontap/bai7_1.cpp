#include <iostream>
#include <cmath>

using namespace std;

struct Node 
{
    double x, y, z;
    Node *next;
};

struct List 
{
    Node *Head;
};

Node* createNode(double x, double y, double z)
{
    Node *p = new Node;
    p->x = x;
    p->y = y;
    p->z = z;
    p->next = NULL;
    return p;
}

void createList(List &L)
{
    L.Head = NULL;
}

void addList(List &L, double x, double y, double z)
{
    Node *p = createNode(x,y,z);
    if(L.Head == NULL)
    {
        L.Head = p;
        return;
    }
    Node *q = L.Head;
    while(q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
}

int TimKiem(List L, double x, double y, double z)
{
    Node *q = L.Head;
    int dem = 0;
    while(q->next != NULL)
    {
        if(q->x == x && q->y == y && q->z == z)
        {
            return dem;
        }
        else
        {    
            dem++;
            q= q->next;
        }
    }
    return -1;
}

int main()
{
    List L;
    createList(L);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        double x, y, z;
        cin >> x >> y >> z;
        addList(L, x, y, z);
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++)
    {
        double x, y, z;
        cin >> x >> y >> z;
        int kq = TimKiem(L, x, y, z);
        if(kq == -1)
            cout << "KHONG\n";
        else cout << kq << endl;
    }
}