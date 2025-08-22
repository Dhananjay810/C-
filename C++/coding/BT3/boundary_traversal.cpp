#include<iostream>
#include<climits>
#include<queue>
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
void BFS(Node *root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node *temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
}
Node *construct(int arr[],int n){
    queue<Node *> q;
    Node *root=new Node(arr[0]);
    q.push(root);
    int i=1; 
    int j=2;
    while(q.size()>0 && i<n){
        Node *temp=q.front();
        q.pop();
        Node *l;
        Node *r;
        if(arr[i]!=INT_MIN) l=new Node(arr[i]);
        else l=NULL;
        if(j<n &&  arr[j]!=INT_MIN) r=new Node(arr[j]);
        else r=NULL;
        temp->left=l;
        temp->right=r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
}
void leftboundary(Node *root){
    if(root->left==NULL &
    & root->right==NULL) return;
    cout<<root->val<<" ";
    if(root->left!=NULL) leftboundary(root->left)\
    if(root->left==NULL) leftboundary(root->right);
}
void leaf(Node *root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL)cout<<root->val<<" ";
    leaf(root->left);
    leaf(root->right);
}
void rightboundary(Node *root){
    if(root->left==NULL && root->right==NULL) return;
    if(root->right!=NULL) rightboundary(root->right);
    if(root->right==NULL) rightboundary(root->left);
    cout<<root->val<<" ";
}
void nthlevel(Node *root,int l,int u){
    if(root==NULL) return;
    if(l==u){
        cout<<root->val<<" ";
        return; 
    }
    nthlevel(root->left,l+1,u);
    nthlevel(root->right,l+1,u);
}
int level(Node *root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,INT_MIN,18,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,28};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node *root=construct(arr,n);
    // BFS(root);
    int nn=level(root);
    for(int i=1; i<=nn; i++){
        nthlevel(root,1,i);
        cout<<endl;
    }
    cout<<endl;
    leftboundary(root);
    leaf(root);
    rightboundary(root->right);
}