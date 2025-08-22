#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        this->left=NULL;
        this->right=NULL;
    }
};
void product(Node *root,int &u){
    if(root==NULL) return;
    u=u*(root->val);
    product(root->left,u);
    product(root->right,u);
}
int main(){
    Node *root=new Node(1);
    Node *a=new Node(2);
    Node *b=new Node(3);
    Node *c=new Node(4);
    Node *d=new Node(5);
    Node *e=new Node(6);


    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->right=e;
    int u=1;
    product(root,u);
    cout<<u;
}