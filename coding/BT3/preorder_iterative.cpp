#include<iostream>
#include<climits>
#include<stack>
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
void display(Node *root){
    stack<Node *> st;
    st.push(root);
    while(st.size()>0){
        Node *temp=st.top();
        st.pop();
        cout<<temp->val<<" ";
        if(temp->right!=NULL) st.push(temp->right); //stack mai FILO hota hai to hume ulta push karna hoga
        if(temp->left!=NULL) st.push(temp->left);
    }
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
    display(root);
}