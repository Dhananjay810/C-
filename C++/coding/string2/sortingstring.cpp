// sorting according to alphabet 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string n = "6584";
    sort(n.begin(),n.end());
    cout<<n<<endl;
    //here sort work in ASCII value.
}