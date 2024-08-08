#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    Node *prev;

    Node(int val){
        this->val = val;
        this->next= NULL;
        this->prev=NULL;
    }
};

class DLL{
    public:
    Node *head=NULL;
    Node *tail=NULL;
    int size=0;

    void addAtBegn(int val){
        Node *temp=new Node(val);
        if(s==0){
            head=tail=temp;
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        size++;
    }

    void addAtend(int val){
        Node *temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
        size++;
    }

    void addAtIdx(int val,int idx){
        if(idx==0) addAtBegn(val);
        else if(idx==size) addAtend(val);
        else{
            Node *temp=new Node(val);
            Node *tr=head;
            while(idx-1!=0){
                tr=tr->next;
            }
            temp->next=tr->next;
            tr->next=temp;
            temp->prev=tr;
        }
        size++;
    }
}

int main(){

}