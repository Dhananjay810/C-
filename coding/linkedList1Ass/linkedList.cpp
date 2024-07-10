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
    Node *head=NULL;
    int size=0;

    void insertAtBeg(int val){
        Node *a=new Node(val);
        a->nxt=head;
        head=a;
        size++;
    }

    void insertAtEnd(int val){
        if(size==0) insertAtBeg(val);
        Node *a=new Node(val);
        Node *temp=head;
        while(temp->nxt!=NULL) temp=temp->nxt;
        a->nxt=temp->nxt;
        temp->nxt=a;
        size++;
    }

    void insertAtIdx(int idx,int val){
        if(idx<0 || idx>size){
            cout<<"Invalid index"<<endl;
            return;
        }
        if(idx==0) insertAtBeg(val);
        else if(idx==size) insertAtEnd(val);
        else{
            Node *a=new Node(val);
            Node *temp=head;
            idx -= 1;
            while(idx!=0){
                temp=temp->nxt;
                idx--;
            }
            a->nxt=temp->nxt;
            temp->nxt=a;
        }
        size++;
    }

    int getIdx(int idx){
        if(idx<0 || idx>size-1){
            cout<<"Invalid Index"<<endl;
            return -1;
        }
        if(idx==0) return head->val;
        else{
            Node *temp=head;
            for(int i=1; i<=idx; i++){
                temp=temp->nxt;
            }
            return temp->val;
        }
    }

    void deleteAtBeg(){
        deleteIdx(0);
    }

    void deleteAtEnd(){
        deleteIdx(size-1);
    }

    void deleteIdx(int idx){
        if(idx<0 || idx>size-1){
            cout<<"Invalid Index"<<endl;
            return;
        }
        if(size==0){
            cout<<"List is empty"<<endl;
            return;
        }
        if(idx==0){
            cout<<head->val<<" is deleted"<<endl;
            head=head->nxt;
        }
        else{
            Node *temp=head;
            for(int i=1; i<idx; i++){
                temp=temp->nxt;
            }
            cout<<temp->nxt->val<<" is deleted"<<endl;
            temp->nxt=temp->nxt->nxt;
        }
        size--;
    }

    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->nxt;
        }
        cout<<endl;
    }

};
int main(){
    LinkedList ll;

    cout<<"Enter 1 for insertion at beginning"<<endl;
    cout<<"Enter 2 for insertion at end"<<endl;
    cout<<"Enter 3 for insertion at particular idx"<<endl;
    cout<<"Enter 4 for display"<<endl;
    cout<<"Enter 5 for get value at particular idx"<<endl;
    cout<<"Enter 6 for deletion at beginning"<<endl;
    cout<<"Enter 7 for deletion at end"<<endl;
    cout<<"Enter 8 for deletion at particular idx"<<endl;

    while(true){
        int n;
        cout<<"enter command from above :";
        cin>>n;
        cout<<endl;
        if(n==1){
            int val;
            cout<<"Enter Value u want to store :";
            cin>>val;
            cout<<endl;
            ll.insertAtBeg(val);
        }
        else if(n==2){
            int val;
            cout<<"Enter Value u want to store :";
            cin>>val;
            cout<<endl;
            ll.insertAtEnd(val);
        }
        else if(n==3){
            int idx;
            cout<<"Enter index where you want to store that :";
            cin>>idx;
            cout<<endl;
            int val;
            cout<<"Enter Value u want to store :";
            cin>>val;
            cout<<endl;
            ll.insertAtIdx(idx,val);
        }
        else if(n==4){
            ll.display();
        }
        else if(n==5){
            int idx;
            cout<<"Enter Index u want to Get :";
            cin>>idx;
            cout<<endl;
            cout<<ll.getIdx(idx)<<endl;
        }
        else if(n==6){
            ll.deleteAtBeg();
        }
        else if(n==7){
            ll.deleteAtEnd();
        }
        else if(n==8){
            int idx;
            cout<<"Enter Index u want to delete :";
            cin>>idx;
            cout<<endl;
            ll.deleteIdx(idx);
        }
        else break;
    }
}