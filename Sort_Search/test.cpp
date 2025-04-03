#include <iostream>

using namespace std;

struct node
{
    int info;
    node *left, *right;
};

// Kieu struct dung mo ta thong tin doi tuong dang de tao ra
//Tree(node *root)          // = Tree(Tree T)

typedef node* Tree;         // dat ten cho kieu co san

node* createnode(int x)
{
    node *p = new node;

    if (p == NULL)
    {
        cout <<"Memory is full";
        return p;
    }
    p -> info = x;
    p -> left = p -> right = NULL;
    return p;
}

void insertnode(Tree &T, int x)
{
    if ( !T )                   // cay hien hanh cua lan goi de quy nay co T la NULL
        T = createnode(x);      //tao node moi roi cho T tro toi
    if (x == T -> info)         // x = node goc => khong lam gi
        return;
    if (x < T -> info)          // x < node goc => gan vao nhanh trai
        insertnode(T -> left, x);           //goi de quy qua nhanh trai
    else                        // x > node goc => gan vao   nhanh phai
        insertnode(T -> right, x);          //goi de quy qua nhanh phai
}

void inputTree(Tree &T)
{
    int n, x;
    cin >> n;               //nhap so luong node
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        insertnode(T, x);   //tao 1 node chua x roi gan vao cay
    }
}

void NLR(Tree T)
{
    if(T != NULL)
    {
        cout << T -> info <<" ";
        NLR(T -> left);
        NLR(T -> right);
    }
}

void LNR(Tree T)
{
    if(T != NULL)
    {
        LNR(T -> left );
        cout << T -> info <<" ";
        LNR(T -> right);
    }
}

void LRN( Tree T)
{
    if(T !=NULL)
    {
        LRN(T -> left );
        LRN(T -> right);
        cout << T -> info <<" ";
    }
}

/*
Ham insertnode duoc goi dau tien tu ham inputTree; tham so T1 khi do la

con tro tro toi 20

Trong than ham, thuc hien loi goi de quy insertnode(T1 -> left,x);

=> chuong trinh bay vao ham insertnode de thuc hien lan thu 2. Mot con T khac
duoc tao ra, tam goi la T2
T2 duoc truyen tham so tu T1 -> left, tuc la T2 = T1 -> left
lai goi de quy insertnode(T -> right, x)

Ham insertnode duoc thuc hien lan thu 3, voi T3 = T2 -> right(dang la null)

khi viet cau lenh T = createnode(x)
*/
int main()
{
    Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);
    return 0;
}