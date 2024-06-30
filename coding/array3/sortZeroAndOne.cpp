#include<iostream>
using namespace std;
int sort(int a[], int n){
    int i=0,j=n-1;
    while(i<j){
        if(a[i]==0)i++;
        if(a[j]==1)j--;
        if(a[i]==1 && a[j]==0){
            a[i]=0;
            a[j]=1;
            i++;
            j--;
        }

    }
    for(int u=0; u<n; u++){
        cout<<a[u];
    }


}
int main(){
    int n;
    cout<<"enter the no. of elements : ";
    cin>>n;
    int array[n];
    cout<<"enter value : ";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    int y = sort(array,n);
}
