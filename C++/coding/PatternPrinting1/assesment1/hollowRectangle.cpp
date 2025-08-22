#include<iostream>
using namespace std;
int main(){
    int l,b; 
    cout<<"enter the length and breadth : ";
    cin>>l>>b;
    for(int i=1; i<=b; i++){
        if(i==1 || i==b){
            for(int j=1; j<=l; j++){
                cout<<"*";
            }
            cout<<endl;


        }
        else{
            for(int o=1; o<=l; o++){
                if(o==1 || o==l){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
                
            }
            cout<<endl;
        }
    }
}