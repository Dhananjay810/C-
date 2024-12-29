#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    cout<<s.size()<<endl;
    s.insert(5);   // sets not contain duplicate elements
    cout<<s.size()<<endl;
    for(int ele : s) cout<<ele<<" "; // printing element of sets
    cout<<endl;
    if(s.find(41)!=s.end()) cout<<"exist";
    else cout<<"not exist";
    s.erase(1);
    for(int ele : s) cout<<ele<<" "; // printing element of sets
}