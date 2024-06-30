#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter no.";
    cin>>n;
    for(int i=2; i<n; i++){


        if(n%i==0){
            cout<<n<<" is composite no."<<endl;break;

           
        }
    }
    

    
}