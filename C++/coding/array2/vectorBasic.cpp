#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v; // you need not mention size
    // inserting / input do not use []
    v.push_back(6);
    //cout<<v.capacity<<endl;



    // if want to update / access 
    v[0]=18;
    cout<<v[0];
}