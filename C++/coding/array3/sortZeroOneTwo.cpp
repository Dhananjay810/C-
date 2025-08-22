#include<iostream>
using namespace std;
int sort(int a[], int b){
    int h=0, j=0, k=0;
    for(int i=0; i<b; i++){
        if(a[i]==0){
            h++;
        }
        else if(a[i]==1){
            j++;
        }
        else{
            k++;
        }
        
    }
    for(int i=1; i<=h; i++){
        cout<<"0";
    }
    for(int i=1; i<=j; i++){
        cout<<"1";
    }
    for(int i=1; i<=k; i++){
        cout<<"2";
    }

}


int main(){
    int n;
    cout<<"enter no. of element : ";
    cin>>n;
    int array[n];
    cout<<"enter value : ";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    int y=sort(array,n);
    
}