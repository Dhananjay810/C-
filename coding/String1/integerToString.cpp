#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int x=123; 
    string n = to_string(x);
    cout<<n<<endl;
    cout<<(int)n[1]+(int)n[1];
}