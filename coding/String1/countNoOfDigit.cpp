#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    string t = to_string(n);
    cout<<t.length();
}