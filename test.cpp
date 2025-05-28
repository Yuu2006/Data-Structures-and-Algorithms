//Quick Sort

void Quick_Sort(int *a, int l, int r)
{
    if(l >= r)
        return;
    int i = l, j = r;
    int mid = a[(l + r)/2];
    while (i<=j)
    {
        while(a[i] < mid) i++;
        while(a[j] > mid) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    Quick_Sort(a, l, j);
    Quick_Sort(a, i, r);
}

//TREE

struct Node
{
    int info;
    Node* next;
};

struct List 
{
    Node* Head;
    Node* Tail;
};

Node* createNode(int x)
{
    Node* temp = new Node;
    temp->info = x;
    temp->next = NULL;
    return temp;
}

void CreateList(List &L)
{
    L.Head = NULL;
    L.Tail = NULL;
}

void addTail(List &L, int x)
{
    Node* p = createNode(x);
    if(L.Head == NULL)
    {
        L.Head = p;
        L.Tail = L.Head;
        return;
    }
    else  
    {
        L.Tail->next = p;
        L.Tail = p;
    }
}

void printList(List L)
{
    Node*p = L.Head;
    if(p)
    {
        cout << "List empty";
        return;
    }
    while(!p)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

Node* Search(List L, int x)
{
    Node* p = L.Head;
    while((p!= NULL) && (p->info != x))
    {
        p=p->next;
    }
    return p;
}

//TREE
struct node
{
    int val;
    node *left, *right;
};

typedef node* Tree;

node* createnode(int x)
{
    node* p = new node;
    p->val = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(Tree &T, int x)
{
    if(!T)
    {
        T = createnode(x);
        return;
    }
    if(x == T->val) return;
    else if(x < T->val) insertNode(T->left, x);
    else insertNode(T->right, x);
}

node* Search(Tree T, int x)
{
    if(T != NULL)
    {
        if(x == T->val) return T;
        else if(x < T->val) return Search(T->left, x);
        else return Search(T->right, x);
    }
    else return T;
}

//Stack
struct Stack 
{
    Node *Head;
};

void initStack(Stack &S)
{
    S.Head = NULL;
}

bool isEmpty(Stack S)
{
    return S.Head == NULL;
}

void Push(Stack S, int x)
{
    Node* p = new Node;
    p->info = x;
    p->next = S.Head;
    S.Head = p;
}

void print(Stack S)
{
    if(isEmpty(S))
    {
        cout << "EMPTY"
        return;
    }
    Node *P = S.Head;
    while(!P)
    {
        cout << P->info << " ";
        P= P->next;
    }
}

//Hash

struct Hash 
{
    int n;
    int m;
    Node **Bucket;
};

void initHash(Hash &H)
{
    H.n = 0;
    H.Bucket = new Node*[H.m];
    for(int i = 0; i < H.m; i++)
    {
        H.Bucket[i] = NULL;
    }
}

int HashFunc(Hash H, int x)
{
    return x % H.m;
}

void insertList(Node* &H, int x)
{
    Node* ele = createNode(x);
    Node* p = H;
    Node* q = NULL;
    if(H)
    {
        H = ele;
    }
    while(!p)
    {
        if(x < p->info)
            break;
        q = p;
        p = p->next;
    }
    if(q)
    {
        ele->next = H;
        H = ele;
        return;
    }
    q->next = ele;
    ele->next = p;
}

void insertHash(Hash &H, int x)
{
    int i = HashFunc(H, x);
    insertList(H.Bucket[i], x);
    H.n++;
}

void Xuat(Hash H)
{
    for(int i = 0; i < H.m; i++)
    {
        cout << "Bucket " << i <<": ";
        Node* p = H.Bucket[i];
        while(!p)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
}