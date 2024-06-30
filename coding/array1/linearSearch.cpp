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

    int x;
    cout<<"enter no. which you want to search : ";
    cin>>x;

    bool flag = false;

    for(int l=0; l<=n-1; l++){
        if(x==array[l]) flag = true;
       

    }
    if(flag = true) cout<<"present";
    else cout<<"not present";

    cout<<endl;

}