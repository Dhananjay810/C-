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
        if(size==0){
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
        else if(idx==size+1) addAtend(val);
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

    void delatbeg(){
        if(size==0) cout<<"List is empty"<<endl;
        else{
            head=head->next;
            head->prev=NULL;
        }
        size--;
    }
    
    void delatend(){
        if(size==0) cout<<"List is empty"<<endl;
        else{
            tail=tail->prev;
            tail->next=NULL;
        }
        size--;
    }

    void delatidx(int idx){
        if(idx<0 || idx>size) cout<<"Invalid idx"<<endl;
        else{
            if(idx==0) delatbeg();
            else if(idx==size-1) delatend();
            else{
                Node *tr=head;
                while(idx-1!=0){
                    tr=tr->next;
                }
                tr->next=tr->next->next;
                tr->next->prev=tr;
            }
        }
        size--;
    }
    void display(){
        Node *tr=head;
        while(tr!=NULL){
            cout<<tr->val<<" ";
            tr=tr->next;
        }
        cout<<endl;
    }
};

int main(){
    DLL dll;

    dll.addAtBegn(15);
    dll.display();
    dll.addAtBegn(18);
    dll.display();
    cout<<dll.head->next->prev->val<<endl;
    dll.addAtend(78);
    dll.display();
    dll.addAtIdx(45,4);
    dll.display();
    dll.delatbeg();
    dll.display();
    // dll.delatend();
    // dll.display();
    dll.delatidx(1);
    dll.display();
    cout<<dll.head->next->prev->val<<endl;
}