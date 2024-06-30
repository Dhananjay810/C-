#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter no. :";
    cin>>n;
    
   int count=0;

   while(n>0){
    n=n/10;
    count= count+1;

   }
   cout<<count<<endl;
    

}