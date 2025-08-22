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
void preorder(Node *root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(Node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
int main(){
    Node *root=new Node(1);
    Node *a=new Node(2);
    Node *b=new Node(3);
    Node *c=new Node(4);
    Node *d=new Node(5);
    Node *e=new Node(6);
    Node *f=new Node(7);


    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    
}