struct Node{
    int data;
    Node *next;
};
struct Hash{
    int m;
    int n;
    Node **bucket;
};

void initHash(Hash &H){
    H.n=0;
    H.bucket=new Node*[H.m];
    for (int i=0;i<H.m;i++){
        H.bucket[i]=NULL;
    }
}

int hashFunction(int x,Hash H){
    return x%H.m;
}

Node* CreateNode(int x){
    Node*p=new Node;
    p->data=x;
    p->next=NULL;
    return p;
}
void insertlist(Node* &head, int x){
    Node* new_ele=CreateNode(x);
    Node* p=head;
    Node* q=NULL;
    if (head==NULL){
        head=new_ele;
        return;
    }
    while (p!=NULL){
        if (x<p->data)
            break;
        q=p;
        p=p->next;
    }
    if (q==NULL){
        new_ele->next=head;
        head=new_ele;
        return;
    }
    q->next=new_ele;
    new_ele->next=p;
}

void insertHash(Hash &H,int x){
    int index = hashFunction(x,H);
    insertlist(H.bucket[index],x);
}
void traverseAllHash(Hash H){
    for (int i=0;i<H.m;i++){
        cout <<"Bucket "<<i<<": ";
        Node* p=H.bucket[i];
        while (p!=NULL){
            cout <<p->data<<" ";
            p=p->next;
        }
        cout <<endl;
    }
}