#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter size : ";
    cin>>n;
    for (int i=1; i<=n; i++){
        for(int k=1; k<=n-i; k++){
            cout<<" ";
        }

        for(int j=1; j<=i; j++){
            cout<<j;
        }
        for(int h=i; h>=1; h--){
           int y=h-1;
           if(y==0){
            cout<<" ";
           }
           else{
            cout<<y;
           }
        }
        cout<<endl;
    }
    
}