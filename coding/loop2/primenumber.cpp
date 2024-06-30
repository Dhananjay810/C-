#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a no.";
    cin>>n;
    bool flag = true; //true means prime
    for(int i=2; i<n; i++){

        if(n%i==0){
            flag = false; // false means composite
           break;

        }
    }
    if(n==1) cout<<"1 is nither prime nor composite ";
    else if(flag == true) cout<<n<<" is prime no.";
    else cout<<n<<" is composite no,";
}