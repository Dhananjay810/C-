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
// void kk(Node *root,int l,int u){
//     if(root==NULL) return;
//     if(l==u){
//         cout<<root->val<<" ";
//     }
//     kk(root->left,l+1,u);
//     kk(root->right,l+1,u);
// }

// Optimize code;;
void nthlevel(Node *root,int l,int u){
    if(root==NULL) return;
    if(l==u){
        cout<<root->val<<" ";
        return; 
    }
    nthlevel(root->left,l+1,u);
    nthlevel(root->right,l+1,u);
}

void nthlevelreverse(Node *root,int l,int u){
    if(root==NULL) return;
    if(l==u){
        cout<<root->val<<" ";
        return; 
    }
    nthlevelreverse(root->right,l+1,u);
    nthlevelreverse(root->left,l+1,u);
}


int level(Node *root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
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

    int n=level(root);
    for(int i=1; i<=n; i++){
        nthlevel(root,1,i);
        cout<<endl;
    }

    //reverse
    for(int i=1; i<=n; i++){
        nthlevelreverse(root,1,i);
        cout<<endl;
    }
    
}