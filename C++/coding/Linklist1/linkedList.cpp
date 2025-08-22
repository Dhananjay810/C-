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
class LinkedList{
public:
    Node *head;
    Node *tail;
    int size=0;

    // INSERTION AT END
    void insertAtEnd(int val){ // TC = O(1)
        Node *temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            tail->nxt=temp;
            tail=temp;
        }
        size++;
    }

    // DISPLAY
    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->nxt;
        }
        cout<<endl;
    }

    // INSERTION AT BEGINNING
    void insertAtBeg(int val){ // TC = O(1) 
        Node *t=new Node(val);
        if(size==0) head=tail=t;
        else{
            t->nxt=head;
            head=t;
        }
        size++;
    }

    void insertIdx(int idx,int val){
        if(idx==0) insertAtBeg(val);
        else if(idx>size) insertAtEnd(val);
        else{
            Node * t = new Node(val);
            int count=0;
            Node *temp=head;
            while(count!=idx-1){
                temp=temp->nxt;
                count++;
            }
            t->nxt=temp->nxt;
            temp->nxt=t;
        }
        size++;
    }
    int getAtIdx(int idx){
        if(idx==0) return head->val;
        else{
            Node *t=head;
            while(idx!=0){
                t=t->nxt;
                idx--;
            }
            return t->val;
        }
    }
    void deleteIdx(int idx){
        if(size<0){
            cout<<"List is empty"<<endl;
            return; 
        }
        if(idx==0){
            head=head->nxt;
        }
        else{
            Node *t=head;
            while(idx-1!=0){
                t=t->nxt;
                idx--;
            }
            t->nxt=t->nxt->nxt;
            if(idx==size-1) tail=t;
        }
        size--;
    }
};
int main(){
    LinkedList ll;
    // ll.insertAtEnd(100);
    // ll.insertAtEnd(150);
    // ll.insertAtEnd(6845);
    // ll.insertAtEnd(685);
    ll.insertAtBeg(50);
    ll.display();
    // ll.insertAtBeg(0);
    // ll.insertIdx(50,88);
    // ll.insertIdx(10,18);
    ll.deleteIdx(0);
    ll.display();
    ll.insertAtEnd(100);
    ll.display();
    ll.insertAtBeg(88);
    ll.display();
    // cout<<ll.getAtIdx(5)<<endl;
    // ll.deleteIdx(6);
    // ll.display();
    // cout<<ll.size;
}