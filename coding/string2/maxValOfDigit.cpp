#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
    string n; 
    cout<<"enter string : ";
    getline(cin,n);
    stringstream h(n);
    string temp;
    string u;
    int count = 0, maxcount = 0;
    while(h>>temp){
        count = temp.length();
        if(maxcount<count){
            maxcount=count;
            count =0;
            u=temp;
        }
    }
    cout<<maxcount<<endl<<u<<endl;
    
}