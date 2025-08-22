#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the side of rhombus : ";
    cin>>n;
    for(int i=0; i<=n-1; i++){
        for(int j=1; j<=(2*n-1+i); j++){
            if(j<=n-1-i || j>2*n-1-i){
                cout<<" ";
            }
            else{
                cout<<"*";
            }

        }
        cout<<endl;
    }
}