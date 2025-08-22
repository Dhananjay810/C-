#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter sides : ";
    cin>>n;
    for(int i=1; i<=n; i++){
        
        for(int j=65; j<=(64+n); j++){
            char a=(char)j;
            cout<<a;
        }
        cout<<endl;
    }
    return 0;
}