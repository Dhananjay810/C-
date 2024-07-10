#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
int main(){
    Node a(10),b(20),c(30),d(40);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    Node *n;
    n=&a;
    // do{
    //     cout<<n->val<<" ";
    //     n=n->next;
    // }while(n!=NULL);

    cout<<n->next->next->val;
}