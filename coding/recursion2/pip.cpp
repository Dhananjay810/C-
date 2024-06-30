#include<iostream>
using namespace std;
void pip(int n){
    if(n==0){
        cout<<endl<<endl;
        return;
    }
    cout<<"pre "<<n<<endl;
    pip(n-1);
    cout<<"In "<<n<<endl;
    pip(n-1);
    cout<<"Post "<<n<<endl;
}
int main(){
    int n;
    cin>>n;
    cout<<endl;
    pip(n);
    cout<<endl;
}