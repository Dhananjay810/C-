#include<iostream>
#include<climits>
#include<queue>
#include<unordered_map>
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
void kk(Node *root,int l,int n){
    if(root==NULL) return;
    if(l==n){
        cout<<root->val<<" ";
    }
    kk(root->left,l+1,n);
    kk(root->right,l+1,n);
}
void levelorder(Node *root,int le){
    for(int i=0; i<le; i++){
        kk(root,0,i);
        cout<<endl;
    }

}
int level(Node *root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}
void topView(Node *root){
    unordered_map<int,int> m;
    queue< pair<Node *,int> > q;
    q.push({root,0});
    while(q.size()>0){
        Node *temp=(q.front()).first;
        int le=(q.front()).second;
        q.pop();
        Node *l=temp->left;
        Node *r=temp->right;
        if(m.find(le)==m.end()){
            m[le]=temp->val;
        }
        if(l!=NULL) q.push({l,le-1});
        if(r!=NULL) q.push({r,le+1});
    }
    int minLevel=INT_MAX;
    int maxLevel=INT_MIN;
    for(auto x : m){
        int le=x.first;
        minLevel=min(minLevel,le);
        maxLevel=max(maxLevel,le);
    }
    for(int i=minLevel; i<=maxLevel; i++){
        cout<<m[i]<<" "; 
    }
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node *root=construct(arr,n);
    // BFS(root);
    int u=level(root);
    levelorder(root,u);
    topView(root);
}