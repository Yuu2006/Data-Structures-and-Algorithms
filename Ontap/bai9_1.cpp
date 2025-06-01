#include <iostream>
using namespace std;

struct node 
{
    int stt = 0;
    char *com;
    node *next;
};

struct List 
{
    node *head;
    node *tail;
};

void copyS(char *a, char *b)
{
    while(*a != '\0')
    {
        *b = *a;
        a++;
        b++;
    }
    *b = '\0';
}

node *createNode(int stt, char *com)
{
    node *p = new node;
    p->stt = stt;
    p->com = new char;
    copyS(com, p->com);
    p->next = NULL;
    return p;
}

void createList(List &L)
{
    L.head = L.tail = NULL;
}

void addTail(List &L, int stt, char *x)
{
    if(L.head == NULL)
    {
        L.head = L.tail = createNode(stt, x);
        return;
    }

    node *p = createNode(stt, x);
    L.tail->next = p;
    L.tail = p;
}

void deleteNode(List &L)
{
    if(L.head == NULL)
        return;
    
    node *temp = L.head;
    L.head = L.head->next;

    delete temp->com;
    delete temp;

    if (L.head == NULL)
        L.tail = NULL;
}


int main()
{
    List L;
    createList(L);

    int stt = 1;
    while(true)
    {
        int th;cin >> th;
        cin.ignore();
        if(th == -1)
            break;
        else if(th == 0)
        {
            char *x = new char;
            cin >> x;
            addTail(L, stt, x);
            stt++;
            delete x;
        }
        else if(th == 1)
        {
            deleteNode(L);
        }
    }
    
    if (L.head == NULL) {
        cout << "Tiem qua e, khong co khach nao" << endl;
    } else {
        node* p = L.head;
        while (p != NULL) {
            cout << p->stt << " " << p->com << endl;
            p = p->next;
        }
    }


    return 0;
}