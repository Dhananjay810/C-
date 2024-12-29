#include<iostream>
#include<queue>
#include<vector>
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
void size(Node *root, int &s){
    if(root==NULL) return;
    s=s+1;
    size(root->left,s);
    size(root->right,s);
}
void isCBT(Node *root, bool &flag1, int s){
    queue<Node *> q;
    q.push(root);
    int u=0;
    while(q.size()>0){
        Node *temp=q.front();
        q.pop();
        if(temp==NULL) break;
        else u++;
        Node *l=temp->left;
        Node *r=temp->right;
        q.push(l);
        q.push(r);
    }
    if(u!=s){
        flag1=false;
    }
    else flag1=true;
}
void isMax(Node *root, bool &flag2){
    if(root==NULL) return;
    if(root->left!=NULL){
        if(root->val<root->left->val){
            flag2=false;
            return;
        }
    }
    if(root->right!=NULL){
        if(root->val<root->right->val){
            flag2=false;
            return;
        }
    }
    isMax(root->left,flag2);
    isMax(root->right,flag2);
}
int main(){
    int arr[]={20,15,10,8,11,INT_MIN,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node *root=construct(arr,n);
    int s=0;
    size(root,s);
    bool flag1=false;
    isCBT(root,flag1,s);
    // cout<<flag1;
    bool flag2=true;
    isMax(root,flag2);
    // cout<<endl<<flag2;
    if(flag1==true && flag2==true) cout<<"True";
    else cout<<"False";
}