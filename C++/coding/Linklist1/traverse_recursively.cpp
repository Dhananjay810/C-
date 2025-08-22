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

void disp(Node *print){ // itrative traverse is better then recursive traversing
    if(print==NULL) return;
    disp(print->nxt); // reverse
    cout<<print->val<<" ";
    //disp(print->nxt); // forward
}



int main(){

    Node *a=new Node(10);
    Node *b=new Node(20);
    Node *c=new Node(30);
    Node *d=new Node(40);
    Node *e=new Node(50);

    a->nxt=b;
    b->nxt=c;
    c->nxt=d;
    d->nxt=e;

    disp(a);

}