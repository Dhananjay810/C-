#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    public:
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class Queue{
    public:
    Node *head;
    Node *tail;
    int size;
    Queue(){
        size=0;
        head=NULL;
        tail=NULL;
    }
    void push(int val){
        Node *temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void pop(){
        if(size==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node *a=head;
        head=head->next;
        delete(a); // prevent from wastage of memory
        size--;
    }
    int front(){
        if(size==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->val;
    }
    int rear(){
        if(size==0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return tail->val;
    }
    int length(){
        return size;
    }
    void disp(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.disp();
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.disp();
    q.pop();
    q.disp();
    cout<<q.front()<<endl;
    cout<<q.rear();
    cout<<endl<<q.length();
}