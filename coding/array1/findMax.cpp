#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<" enter no. of element : ";
    cin>>n;
    int array[n];
    cout<<"enter value of element : ";
    for(int j=0; j<=n-1; j++){
        
        cin>>array[j];
    }
    int max=array[0];
    for(int i=1; i<=n-1; i++){
        if(max<array[i]){
            max=array[i];
        }
    }
    cout<<max;

}
    
