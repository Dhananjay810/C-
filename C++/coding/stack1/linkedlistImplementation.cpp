#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node *nxt;

    Node(int val){
        this->val=val;
        this->nxt=NULL;
    }
};
class Stack{
public:
    Node *head;
    int size;
    Stack(){
        head=NULL;
        size=0;
    }
    void push(int val){
        Node *temp = new Node(val);
        temp->nxt=head;
        head=temp;
        size++;
    }
    void pop(){
        if(head==NULL){
            cout<<"Empty"<<endl;
            return;
        }
        head=head->nxt;
        size--;
    }
    int top(){
        if(head==NULL){
            cout<<"Empty"<<endl;
            return -1;
        }
        return head->val;
    }
    void print(Node *temp){
        if(temp==NULL) return;
        print(temp->nxt);
        cout<<temp->val<<" ";
    }
    void disp(){
        Node *temp=head;
        print(temp);
        // while(temp!=NULL){
        //     cout<<temp->val<<" ";
        //     temp=temp->nxt;
        // }
        cout<<endl;
    }
};
int main(){
    Stack st;
    st.push(18);
    st.push(18);
    st.push(18);
    st.push(19);
    st.disp();
    cout<<st.top();
}