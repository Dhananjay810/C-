#include<iostream>
using namespace std;
int main(){
    string s="dhananjay from bihar";
    cout<<s<<endl;

    string f;
    //cin>>f; // only if no space in the srring 
    // oyhtr wise we use gatline();
    getline(cin,f);

    cout<<"DJ"<<" "<<f;
}