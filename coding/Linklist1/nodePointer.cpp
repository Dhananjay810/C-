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
// Traverse
void display(Node *x){
    Node *print;
    print=x;
    while(print!=NULL){
        cout<<print->val<<" ";
        print=print->nxt;
    }
    cout<<endl;
}

// Finding size--
void length(Node *x){
    int s=0;
    while(x!=NULL){
        s++;
        x=x->nxt;
    }
    cout<<s<<endl;
}

void insertAtEnd(Node *x,int val){
    Node *t = new Node(val);
    while(x->nxt!=NULL) x=x->nxt; 
    x->nxt=t;
}
int main(){
    Node *a=new Node(10);
    Node *b=new Node(20);
    Node *c=new Node(30);
    Node *d=new Node(40);
    a->nxt=b;
    b->nxt=c;
    c->nxt=d;
    insertAtEnd(a,80);
    display(a);
    length(a);
    
}