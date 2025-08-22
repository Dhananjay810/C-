#include<iostream>
#include<string>
using namespace std;
int main(){
    //string to integer
    string n = "1234";
    int x = stoi(n);
    cout<<x<<endl<<x+1;

    //string to long long integer
    string u = "123456787654321";
    long long c = stoll(u);
    cout<<c<<endl<<c+1;
}