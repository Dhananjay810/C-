#include<iostream>
#include<climits>
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
void kk(Node *root,int l){
    if(root==NULL) return;
    if(l==4){
        cout<<root->val<<" ";
    }
    kk(root->left,l+1);
    kk(root->right,l+1);
}
int main(){
    Node *root=new Node(1);
    Node *a=new Node(7);
    Node *b=new Node(9);
    Node *c=new Node(2);
    Node *d=new Node(6);
    Node *f=new Node(9);
    Node *g=new Node(5);
    Node *h=new Node(11);
    Node *i=new Node(5);


    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->right=f;
    d->left=g;
    d->right=h;
    f->left=i;
    kk(root,1);
    
}