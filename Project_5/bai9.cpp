/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

//###INSERT CODE HERE -

DNode *createDNode(int x)
{
    DNode *temp = new DNode;
    temp->info = x;
    temp->pNext = NULL;
    temp->pPrev = NULL;
    return temp;
}

void init(DList &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

void addHead(DList &L, int x)
{
    DNode *p = createDNode(x);
    if(L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
        return;
    }
    else
    {
        p->pNext = L.pHead; 
        L.pHead->pPrev = p;
        L.pHead = p;       
    }
}

void addTail(DList &L, int x)
{
    DNode *p = createDNode(x);
    if(L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
        return;
    } 
    else 
    {
        p->pPrev = L.pTail;
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void createList(DList &L)
{
    while(true)
    {
        int x; cin >> x;
        if(x == -1) break;
        else addTail(L, x);
    }
}

void printList(DList L)
{
    DNode *p = L.pHead;
    if(p == NULL)
    {
        cout << "List is empty";
        return;
    }
    while(p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void addBefore(DList &L, int x, int y)
{
    DNode *p = L.pHead;
    while ((p != NULL) && (p->info != x)) 
    {
        p = p->pNext;
    }
    if (p == NULL) 
    {
        cout << "\nCan't find the value "<< x;
        return;
    }

    // chen node new_ele vao truoc p
    DNode *new_ele = createDNode(y);
    new_ele->pNext = p;
    new_ele->pPrev = p->pPrev;
    if(new_ele->pPrev != NULL)
    {
        // 1 4 3
        // p = 4 
        // new ele = 2
        // new ele -> next = 4
        // new ele -> prev = 1
        // p -> prev : 1 -> next = 2;
        p->pPrev->pNext = new_ele;
    }
    else 
    {
        // 2 1 4 3
        L.pHead = new_ele;
    }   
        // p -> prev = 2
    p->pPrev = new_ele;
    
    // 1 2 4 3
}

void addAfter(DList &L, int x, int y)
{
    DNode *p = L.pHead;
    while ((p != NULL) && (p->info != x)) 
    {
        p = p->pNext;
    }
    if (p == NULL) 
    {
        cout << "\nCan't find the value "<< x;
        return;
    }

    // chen node new_ele vao sau node p;
    DNode *new_ele = createDNode(y);
    new_ele->pNext = p->pNext;
    new_ele->pPrev = p;
    
    if(new_ele->pNext != NULL)
    {
        p->pNext->pPrev = new_ele;
    }
    else
    {
        L.pTail = new_ele;
    }
    
    p->pNext = new_ele;
}

int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
