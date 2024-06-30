#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    int count=0;
    for(int i=0; i<n; i++){
        if(i>=a && (n-i)-1<=b){
            count++;
        }
    }
    cout<<count;
}