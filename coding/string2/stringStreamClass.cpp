#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
int main
(){
    string n = "Dhananjay from bihar";
    stringstream nn(n);
    string temp;

    while(nn>>temp){
        cout<<temp<<endl;
    }
      
}