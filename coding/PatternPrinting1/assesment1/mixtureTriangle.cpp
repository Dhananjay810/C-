#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the side of triangle : ";
    cin>>n;
    for(int i=1; i<=n; i++){
        if(i%2==0 && i!=1){
            for(int j=65; j<65+i; j++){
                char a=(char)j;
                cout<<a;
            }
        }
        else{
            for(int l=1; l<=i; l++){
                cout<<l;
            }
        }
        cout<<endl;
        
    }
}