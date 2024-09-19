#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node *pre;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->pre=NULL;
    }
};
class Deque{
    public:
    Node* head;
    Node* tail;
    int size;
    Deque(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void pushfront(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head->pre=temp;
            head=temp;
        }
        size++;
    }
    void pushback(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->pre=tail;
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void popfront(){
        if(size==0){
            cout<<"Deque is empty"<<endl;
            return;
        }
        Node *a=head;
        head=head->next;
        delete(a);
        head->pre=NULL;
        size--;
    }
    void popback(){
        if(size==0){
            cout<<"Deque is empty"<<endl;
            return;
        }
        Node *a=tail;
        tail=tail->pre;
        delete(a);
        tail->next=NULL;
        size--;
    }
    int front(){
        if(size==0){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        return head->val;
    }
    int rear(){
        if(size==0){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        return tail->val;
    }
    int length(){
        return size;
    }
    void disp(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Deque q;
    q.pushfront(45);
    q.pushback(18);
    q.pushback(50);
    q.pushfront(00);
    q.disp();
    q.popfront();
    q.disp();

    q.popback();
    q.disp();
}