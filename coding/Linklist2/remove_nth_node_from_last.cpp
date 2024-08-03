#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node *nxt;

    Node(int val){
        this->val=val;
        this->nxt=NULL;
    }
};

int len(Node *head){
    int c=0;
    while(head!=0){
        c++;
        head=head->nxt;
    }
    return c;
}

void display(Node *head){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->nxt;
        }
        cout<<endl;
    }

int main(){
    Node *a=new Node(10);
    Node *b=new Node(20);
    Node *c=new Node(30);
    Node *d=new Node(40);
    Node *e=new Node(50);
    Node *x=new Node(60);
    a->nxt=b;
    b->nxt=c;
    c->nxt=d;
    d->nxt=e;
    e->nxt=x;
    int n=3;

    // Method 1 ==> 2 pass

    // Node *temp=a;
    // int size=0;
    // while(temp!=NULL){
    //     size++;
    //     temp=temp->nxt;
    // }
    // if(n==size){
    //     a=a->nxt;
    // }
    // else
    // {int idx=size-n;
    // temp=a;
    // while(idx!=1){
    //     temp=temp->nxt;
    //     idx--;
    // }
    // temp->nxt=temp->nxt->nxt;}
    // display(a);

    //

    // Method 2 ==> one Pass

    Node *s=a;
    Node *f=a;
    int m=0;
    while(m<n){
        f=f->nxt;
        m++;
    }

    if(f==NULL){
        a=a->nxt;
        display(a);
        return 0;
    }

    while(f->nxt!=NULL){
        s=s->nxt;
        f=f->nxt;
    }
    s->nxt=s->nxt->nxt;

    display(a);

    //
    
    
}