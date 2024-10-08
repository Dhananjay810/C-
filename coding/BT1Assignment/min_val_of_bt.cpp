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
int mini(Node *root){
    if(root==NULL) return INT_MAX;
    return min(root->val,min(mini(root->left),mini(root->right)));
}
int main(){
    Node *root=new Node(10);
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
    cout<<mini(root);
}