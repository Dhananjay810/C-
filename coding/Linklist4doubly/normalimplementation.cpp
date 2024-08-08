#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    Node *perv;

    Node(int val){
        this->val=val;
        this->next=NULL;
        this->perv=NULL;
    }

};

void display(Node *head){
    while(head){
    cout<<head->val<<" ";
    head=head->next;
    }
}

void displayrev(Node *head){
    while(head){
    cout<<head->val<<" ";
    head=head->perv;
    }
}

int main(){
    Node *a=new Node(10);
    Node *b=new Node(20);
    Node *c=new Node(30);
    Node *d=new Node(40);
    Node *e=new Node(50);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;

    e->perv=d;
    d->perv=c;
    c->perv=b;
    b->perv=a;

    display(a);
    cout<<endl;
    displayrev(e);

}