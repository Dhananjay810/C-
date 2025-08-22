#include<iostream>
using namespace std;
class Queue{
public:
    int f=0;
    int r=0;
    int arr[6];
    Queue(){
        f=0;
        r=0;
    }
    void push(int n){
        if(r==6){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[r]=n;
        r++;
    }    
    void pop(){
        if(f==r){
            cout<<"Queue is empty"<<endl;
            return;
        }
        f++;
    }
    int front(){
        if(f==r){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[f];
        }
    }
    int rear(){
        if(f==r){
            cout<<"Queue ids empty"<<endl;
            return -1;
        }
        return arr[r-1];
    }
    int size(){
        return r-f;
    }
    void disp(){
        for(int i=f; i<r; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    q.push(18);
    q.disp();
    q.push(18);
    q.disp();
    q.push(18);
    q.disp();
    q.push(18);
    q.disp();
    q.push(18);
    q.push(18);
    q.push(18);
    q.disp();
}