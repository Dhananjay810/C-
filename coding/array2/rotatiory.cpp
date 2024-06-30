#include<iostream> 
using namespace std;
int rotate(int a[],  int n){
    int k;
    cout<<"enter by which you want to rotate : ";
    cin>>k;
    for(int u=1; u<=k; u++){
        int temp1=a[u-1];
        int temp2=a[n-u];
        a[u-1]=a[n-u];
        a[n-u]=temp1;

    }
    for(int h=0; h<n; h++){
        cout<<a[h]<<" ";
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
    for(int h=0; h<n; h++){
        cout<<array[h]<<" ";
    }
    cout<<endl;
    int y = rotate(array,n);

}