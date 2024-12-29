#include<iostream>
using namespace std;
class MinHeap{
public:
    int arr[50];
    int idx;
    MinHeap(){
        idx=1;
    }

    int top(){
        return arr[1];
    }

    void push(int x){
        arr[idx]=x;
        int i=idx;
        idx++;
        while(i!=0){
            int parent=i/2;
            if(arr[i]<arr[parent]) swap(arr[i],arr[parent]);
            else break;
        }
    }

    void pop(){
        idx--;
        arr[1]=arr[idx];

        //rearrangement
        int i=1;
        while(true){
            int left=2*i, right=2*i+1;
            if(left>idx-1) break;
            if(right>idx-1){
                if(arr[i]>arr[left]){
                    swap(arr[i],arr[left]);
                    i=left;
                }
                break;
            }
            if(arr[left]<arr[right]){
                if(arr[i]>arr[left]){
                    swap(arr[i],arr[left]);
                    i=left;
                }
            }
            else{
                if(arr[i]>arr[right]){
                    swap(arr[i],arr[right]);
                    i=right;
                }
            }
        }
    }

    int size(){
        return idx-1;
    }

    void display(){
        for(int i=1; i<idx; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main(){
    MinHeap mh;
    mh.push(10);
    mh.push(-6);
    mh.push(100);
    mh.push(90);
    cout<<mh.size()<<endl;
    cout<<mh.top()<<endl;
    mh.display();
    mh.pop();
    mh.display();
    mh.push(70);
    cout<<mh.top()<<endl;
    mh.display();
}