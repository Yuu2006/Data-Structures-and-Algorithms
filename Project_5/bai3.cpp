/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *createNode(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void createList(List &x)
{
    x.head = NULL;
    x.tail = NULL;
}

void inputHead(List &L, int x)
{
    Node *p = createNode(x);
    if(L.head == NULL)
    {
        L.head = p;
        L.tail = L.head;
        return;
    }
    else
    {
        p->next = L.head; 
        L.head = p;       
    }
}

void inputTail(List &L, int x)
{
    Node *p = createNode(x);
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

void printList(List L)
{
    Node *p = L.head;
    if(p == NULL)
    {
        cout << "blank";
    }
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

Node *Search(List L, int x)
{
    Node *p;
    p = L.head;
    while((p != NULL) && (p->data != x)) 
    {
        p = p->next;
    }
    return p;
}

void InsertAfter(List &L, int a, int b)
{
    Node *p = createNode(b);
    Node *q = Search(L, a);
    if(q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if(L.tail == q)
            L.tail = p;
    }
    else  
        inputHead(L, p->data);
}

void DeleteNode(List &L)
{
    if(!L.head)
        return;
    Node *p = L.head;
    L.head = L.head->next;
    p->next = NULL;
    delete p;
    if(L.head == NULL) L.tail = NULL;
}

void DeleteAfter(List &L, int x)
{
// p = q; p = vi tri tim kiem p => NULL
// delete p->head;
// q.next = p;

    if(!L.head) return; 
    if(L.head->data == x)
    {
        DeleteNode(L);
        return;
    }

    Node *q = L.head;
    Node *p = L.head->next;
    while(p != NULL)
    {
        if(p->data == x)
        {
            q->next = p->next;
            if(p == L.tail) 
            {
                L.tail = q;
            }
            delete p;
            return;
        }
        q = p;
        p = p->next;
    }
}


int main()
{
    List L;
    createList(L);
    while(true)
    {
        int input;
        cin >> input;
        
        if(input == 6) break;
        else if(input == 5)
        {
            DeleteNode(L);
        }
        else
        {
            int x;
            cin >> x;
            if(input == 0)
            {
                inputHead(L, x);
            }
            else if(input == 1)
            {
                inputTail(L, x);
            }
            else if(input == 2)
            {
                int b;
                cin >> b;
                Node *q = Search(L, x);
                if(q != NULL)
                {
                    InsertAfter(L, x, b);
                }
                else 
                {
                    inputHead(L, b);
                }
            }
            else if(input == 3)
            {
                DeleteAfter(L, x);
            }
        } 
    }
    printList(L);

    return 0;
}