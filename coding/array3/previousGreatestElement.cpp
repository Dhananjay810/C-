#include<iostream>
using namespace std;
int pre(int a[], int n){
    int max=a[0];
    int b[n],k[n];
    b[0]={-1};
    b[1]=a[0];
    k[n-1]={-1};
    k[n-2]=a[n-1];
    for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
           
        if(max<a[j])
        {
            max=a[j];
        }
        b[i]=max;
         
        }
    }
    for(int r=0; r<n; r++){
        cout<<b[r]<<" ";
    }
    cout<<endl;
    
    for(int i=0; i<n-2; i++){
        int nxtmax=a[i+1];
        for(int j=i+1; j<n-1; j++){
           
        if(nxtmax<a[j])
        {
            nxtmax=a[j];
        }
        k[i]=nxtmax;
         
        }
    }
    for(int r=0; r<n; r++){
        cout<<k[r]<<" ";
    }
    cout<<endl;
    int sum=0,fan;
    for(int g=1; g<n-1; g++){
        if(b[g]>k[g]){
            b[g]=k[g];
        }
        else{
            continue;
        }
    }
    for(int r=0; r<n; r++){
        cout<<b[r]<<" ";
}
for(int u=1; u<n-1; u++){
    if(a[u]<=b[u]){
        fan=-a[u]+b[u];
        sum=sum+fan;
    }
    else{
        continue;
    }
}
cout<<endl<<sum;
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
    int y=pre(array,n);


}