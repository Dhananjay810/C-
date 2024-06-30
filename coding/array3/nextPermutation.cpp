#include<iostream>
using namespace std;
int nextpermutation(int a[], int n){
    int h=-1;
        for(int i=n-2; i>=0; i--){
            if(a[i]<a[i+1]){
                h=i;
                break;
            }
        }
        if(h==-1){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(a[i]<a[j]){
                        int temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
                    else{
                        continue;
                    }
                }
            }
       }
       else if(h==0){
        int f=a[0];
        a[0]=a[n-1];
        a[n-1]=f;
        for(int r=1; r<n; r++){
            for(int x=1; x<n; x++){
                if(a[r]<a[x]){
                        int temp=a[r];
                        a[r]=a[x];
                        a[x]=temp;
                    }
                    else{
                        continue;
                    }
            }
        }
       }
        else{
            for(int i=h; i<n; i++){
        for(int j=h; j<n; j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            else{
                continue;
            }
        }
    }
        }
    
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    
}
int main(){
    int n;
    cout<<"enter no. of element : ";
    cin>>n;
    int array[n];
    cout<<"enter value : ";
    for(int i =0; i<n; i++){
        cin>>array[i];
    }
    int y=nextpermutation(array,n);

}