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
int maxx(Node *root){
    if(root==NULL) return INT_MIN;
    int max1 = root->val;
    int u= max(max1,maxx(root->left));
    return max(u,maxx(root->right));
}
int main(){
    Node *a=new Node(5);
    Node *b=new Node(14);
    Node *c=new Node(3);
    Node *d=new Node(6);
    Node *e=new Node(2);
    Node *f=new Node(1);
    Node *g=new Node(1);
    
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    f->left=g;
    cout<<maxx(a);
}