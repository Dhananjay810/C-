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

    // Method 1 ==> take 2 pass
    int size=len(a);
    int idx=(size/2)+1;

    Node *temp=a;
    while(idx>1){
        temp=temp->nxt;
        idx--;
    }
    cout<<temp->val<<endl;

    //

    // Method 2 ==> take 1 pass

    Node *s=a;
    Node *f=a;
    while(f!=NULL && f->nxt!=NULL){ // order IMPORTANT 
        s=s->nxt;
        f=f->nxt->nxt;
    }
    cout<<s->val;
    
}