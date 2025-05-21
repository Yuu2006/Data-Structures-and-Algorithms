#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct Hash
{
    int m;           
    int n;           
    node **bucket;   
};

node* getNode(int x)
{
    node* temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void initHash(Hash &H, int m)
{
    H.m = m;
    H.n = 0;
    H.bucket = new node*[H.m];
    for(int i = 0; i < H.m; i++)
        H.bucket[i] = NULL;
}

int hashFunct(int x, Hash H)
{
    return x % H.m;
}

void insertList(node* &head, int x)
{
    node* temp = new node;
    temp->data = x;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        return;
    }
    node* p = head;
    node* q = NULL;
    while(p)
    {
        if(x < p->data)
        {
            break;
        }
        q = p;
        p = p->next;
    }
    if(q == NULL)
    {
        temp->next = head;
        head = temp;
        return;
    }
    q->next = temp;
    temp->next = p;
}

void insertHash(Hash &H, int x)
{
    int index = hashFunct(x, H);
    insertList(H.bucket[index], x);
    H.n++;
}

bool deleteNode(node*& head, int x)
{
    node* p = head;
    node* q = NULL;
    while (p != NULL && p->data != x)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
        return false;

    if (q == NULL)
        head = head->next;
    else
        q->next = p->next;

    delete p;
    return true;
}

bool deleteHash(Hash &H, int x)
{
    int index = hashFunct(x, H);
    bool deleted = deleteNode(H.bucket[index], x);
    if (deleted) H.n--;
    return deleted;
}

void outputList(node* head)
{
    node* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void outputHash(Hash H)
{
    for (int i = 0; i < H.m; i++)
    {
        cout << "Bucket " << i << ": ";
        outputList(H.bucket[i]);
        cout << endl;
    }
}

int main()
{
    Hash H;
    int m, n;
    cin >> m >> n;
    initHash(H, m);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertHash(H, x);
    }
    cout << "Created Hash: " << endl;
    outputHash(H);
    int a, b;
    while (cin >> a >> b)
    {
        if (a == 1)
        {
            cout << "\nInsert " << b;
            insertHash(H, b);
        }
        else if (a == 2)
        {
            cout << "\nDelete " << b;
            if (!deleteHash(H, b))
                cout << "\nKhong co phan tu co khoa " << b;
        }
        else
        {
            break;
        }
    }
    cout << endl;
    cout << "Updated Hash: " <<endl;
    outputHash(H); 
    return 0;
}