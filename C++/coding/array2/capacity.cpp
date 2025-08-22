#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(18);
    v.push_back(47);
    v.push_back(78);
    v.push_back(5);
    v.push_back(18);
    v.push_back(47);
    v.push_back(78);
    v.push_back(47);
    v.push_back(78);

    cout<<v.capacity();

    cout<<endl<<v.size();
    
}