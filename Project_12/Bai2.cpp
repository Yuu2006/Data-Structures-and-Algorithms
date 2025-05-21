void initHash(Hash &H){
    H.n=0;
    H.pL = new List[H.m];
    for (int i=0;i<H.m;i++){
        H.pL[i].head=NULL;
        H.pL[i].tail=NULL;
    }
}
int hashFunc(int x,Hash H){
    return x%H.m;
}
node* CreateNode(int x){
    node* p=new node;
    p->info=x;
    p->next=NULL;
    return p;
}
void addTail(List &l, int x){
    node*p=CreateNode(x);
    if (l.head==NULL){
        l.head=p;
        l.tail=p;
    }
    else {
        l.tail->next=p;
        l.tail=p;
    }
}
void inputHash(Hash &H, int n){
    initHash(H);
    for (int i=0;i<n;i++){
        int x;
        cin >>x;
        int index = hashFunc(x,H);
        if ((H.n+1.0)/H.m > H.load)
            continue;
        addTail(H.pL[index],x);
        H.n++;
    }
}

void printHash(Hash H){
    for (int i=0;i<H.m;i++){
        cout <<"List "<<i<<": ";
        node* p=H.pL[i].head;
        while (p!=NULL){
            cout <<p->info<<" ";
            p=p->next;
        }
        cout << endl;
    }
 
}

void searchHash(Hash H,int x){
    int index = hashFunc(x,H);
    node*p=H.pL[index].head;
    int SoLanSoSanh=0;
    while (p!=NULL){
        SoLanSoSanh++;
        if (p->info==x){
            cout <<SoLanSoSanh<<endl;
            return;
        }
        p=p->next;
    }
    cout <<"KHONG"<<endl;
}