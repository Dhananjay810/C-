#include<iostream>
using namespace std;
int main(){
    
    int n;
    cout<<"enter no. till what you want the sum :";
    cin>>n;

    int sum=0;

    int i=1; //loop variable
    while(i<=n){ //condition
        sum+=i;
        i++;//updating value of i
    }

    cout<<sum<<endl;


}